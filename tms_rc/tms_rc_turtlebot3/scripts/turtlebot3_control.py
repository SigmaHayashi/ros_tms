#!/usr/bin/env python
# -*- coding:utf-8 -*-

import rospy
from geometry_msgs.msg import Pose2D, Twist
from tms_msg_rc.srv import rc_robot_control, rc_robot_controlResponse
from tms_msg_db.srv import TmsdbGetData, TmsdbGetDataRequest

import datetime
import pymongo
from math import sin, cos, atan2, pi, radians, degrees, sqrt

BURGER_MAX_LIN_VEL = 0.22 #turtlebot3 model = burger
BURGER_MAX_ANG_VEL = 2.84

#pub = rospy.Publisher("turtlebot3/cmd_vel",Twist,queue_size = 10)
pub = rospy.Publisher("cmd_vel",Twist,queue_size = 10)

GOAL = None
pose = Pose2D()
cmd = 10

def main():
    global GOAL
    global cmd
    global pose
    print "Turtlebot3_voronoi_follower"
    rospy.init_node ('turtlebot3_voronoi_follower')

    rospy.wait_for_service('/tms_db_reader')
    service = rospy.Service(
        "turtlebot3_goal_pose" , rc_robot_control, goalPoseCallBack)

    r = rospy.Rate(30)
    while not rospy.is_shutdown():
        pose = getCurrentPose()
        if None == GOAL:
            continue
        KPang = 0.5#1
        KDang = 0
        KPdist = 0.5#1.0
        KDdist = 0
        ARV_DIST = 0.2

        twist = Twist()
        errorT = normalizeAng(GOAL.theta - pose.theta)

        if cmd == 10:
            twist.angular.z = 0
            twist.linear.x = 0
            GOAL = None
        elif cmd == 1:
            tmp_turn = limit(KPang * errorT,1,-1)
            #rospy.loginfo("turn:{0}".format(tmp_turn))
            twist.angular.z = tmp_turn
            twist.linear.x = 0
        elif cmd == 2:
            errorX = GOAL.x - pose.x
            errorY = GOAL.y - pose.y        
            errorNX = errorX * cos(-pose.theta) - errorY * sin(-pose.theta)
            tmp_spd = limit(KPdist * errorNX, BURGER_MAX_LIN_VEL, -BURGER_MAX_LIN_VEL)
            twist.angular.z = 0
            twist.linear.x = tmp_spd
            #print("pose : {0}, {1}, {2}".format(pose.x, pose.y, pose.theta))
        else:
            errorX = GOAL.x - pose.x
            errorY = GOAL.y - pose.y
            targetT = atan2(errorY, errorX)

            errorNX = errorX * cos(-pose.theta) - errorY * sin(-pose.theta)
            errorNT = normalizeAng(targetT - pose.theta)

            tmp_spd = limit(KPdist * errorNX, 1, -1)
            tmp_turn = limit(KPang * errorNT, 1, -1)

            distance = sqrt(errorX ** 2 + errorY **2)
            #rospy.loginfo("dist:{0}".format(distance))
            #rospy.loginfo("spd:{0}" "turn:{1}".format(tmp_spd, tmp_turn))
            twist.angular.z = tmp_turn
            twist.linear.x = tmp_spd
        pub.publish(twist)
        r.sleep()

def constrain(input, low, high):
    if input < low:
      input = low
    elif input > high:
      input = high
    else:
      input = input

    return input

def goalPoseCallBack(req):
    global pose   
    global cmd
    if req.cmd == 10:
        cmd = req.cmd
	return rc_robot_controlResponse()
    elif req.cmd == 2:
      rad = diffRadian(pose.theta, req.arg[2])
      if rad >= 0.1 or rad <= -0.1:
        return rc_robot_controlResponse()
      else:
        cmd = req.cmd
    else:
      cmd = req.cmd
    
    global GOAL
    GOAL = Pose2D()
    GOAL.x = req.arg[0]
    GOAL.y = req.arg[1]
    GOAL.theta = req.arg[2]
    goal_dis = req.arg[3]   

    rospy.loginfo("SubGOAL : {0}".format(GOAL))
    print("cmd : {0}".format(cmd)) 

    #*******************************************  
    # conditions for moving next operation    
    while True:
      if cmd == 1:
        rad = diffRadian(pose.theta, GOAL.theta)
        if rad > -0.02 and rad < 0.02:
          if goal_dis <= 0.25:
            print("goal_arrived")
          else:
            print("turned")          
          cmd = 10
          return rc_robot_controlResponse()
      elif cmd == 2:
        dis = distance(pose.x, pose.y, GOAL.x, GOAL.y)
        rad = diffRadian(pose.theta, GOAL.theta)
        if dis <= 0.25 or rad >= 0.1 or rad <= -0.1:
          cmd = 10
          print("pose : {0}, {1}, {2}".format(pose.x, pose.y, pose.theta))
          return rc_robot_controlResponse()

    return rc_robot_controlResponse()


def distance(x1, y1, x2, y2):
    dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))
    return dis


def diffRadian(rad1, rad2):
    rad1 = normalizeAng(rad1)
    rad2 = normalizeAng(rad2)

    rad = normalizeAng(rad2- rad1)
    return rad


def getCurrentPose():
    pose = Pose2D()
    db_req = TmsdbGetDataRequest()
    db_req.tmsdb.id = 2013
    db_req.tmsdb.sensor = 3001
    try:
        srv_client = rospy.ServiceProxy("/tms_db_reader", TmsdbGetData)

        res = srv_client(db_req)
        if 0 == len(res.tmsdb):
            return pose
        pose.x = res.tmsdb[0].x
        pose.y = res.tmsdb[0].y
        pose.theta = res.tmsdb[0].ry

    except rospy.ServiceException as e:
        print "Service call failed: %s" %e

    return pose


def normalizeAng(rad):
    while rad > pi:   # 角度を-180°~180°(-π~π)の範囲に合わせる
        rad = rad - (2 * pi)
    while rad < -pi:
        rad = rad + (2 * pi)
    return rad


def limit(val, maxn, minn):
    return max(min(maxn, val), minn)

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
