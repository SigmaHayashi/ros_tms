#!/usr/bin/env python
# -*- coding:utf-8 -*-

import rospy
from geometry_msgs.msg import Pose2D, Twist
from tms_msg_rc.srv import rc_robot_control, rc_robot_controlResponse
from tms_msg_db.srv import TmsdbGetData, TmsdbGetDataRequest

import datetime
#import pymongo
from math import sin, cos, atan2, pi, radians, degrees, sqrt

BURGER_MAX_LIN_VEL = 0.22 #turtlebot3 model = burger
BURGER_MAX_ANG_VEL = 2.84

pub = rospy.Publisher("cmd_vel/turtlebot3/unity", Twist, queue_size = 10)

GOAL = None
pose = Pose2D()
cmd = 10

def main():
    global GOAL
    global cmd
    global pose
    turn_f = FALSE
    print "Turtlebot3_unity_control"
    rospy.init_node ('turtlebot3_unity_control')

    service = rospy.Service(
        "turtlebot3_virtual_goal_pose" , rc_robot_control, goalPoseCallBack)
    
    sub = rospy.Subscriber("/pose/turtlebot3/unity", Pose2D, getVirtualPose)
    #service_sim = rospy.Service("turtlebot3_get_virtual_pos", TmsdbGetData, virtualPoseCallBack)

    rospy.wait_for_message("pose/turtlebot3/unity", Pose2D)

    r = rospy.Rate(30)
    while not rospy.is_shutdown():
        if None == GOAL:
            continue

        dis = distance(pose.x, pose.y, GOAL.x, GOAL.y)
        rad = diffRadian(pose.theta, req.arg[2])
        if goal_dis <= 0.2:
          if rad > -0.05 and rad < 0.05:
            cmd = 10
          else:
            cmd = 1
        elif rad > 0.1 or rad < -0.1 or turn_f:
            if rad > -0.02 and rad < 0.02:
              turn_f = FALSE
            else:
              turn_f = TRUE
              cmd = 1
        else:
            cmd = 2

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
            tmp_turn = limit(KPang * errorT,BURGER_MAX_ANG_VEL,-BURGER_MAX_ANG_VEL)
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
        else:
            errorX = GOAL.x - pose.x
            errorY = GOAL.y - pose.y
            targetT = atan2(errorY, errorX)

            errorNX = errorX * cos(-pose.theta) - errorY * sin(-pose.theta)
            errorNT = normalizeAng(targetT - pose.theta)

            tmp_spd = limit(KPdist * errorNX, BURGER_MAX_LIN_VEL, -BURGER_MAX_LIN_VEL)
            tmp_turn = limit(KPang * errorNT, BURGER_MAX_ANG_VEL, -BURGER_MAX_ANG_VEL)

            distance = sqrt(errorX ** 2 + errorY **2)
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
    global GOAL
    GOAL = Pose2D()
    GOAL.x = req.arg[0]
    GOAL.y = req.arg[1]
    GOAL.theta = req.arg[2]
    goal_dis = req.arg[3]

    rospy.loginfo("SubGOAL : {0}".format(GOAL))
    return rc_robot_controlResponse()    

    global pose    
    global cmd
    #rospy.loginfo("req.cmd : {0}".format(req.cmd))
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


def getVirtualPose(data):
    global pose
    pose = data
    

def virtualPoseCallBack(req):
    req.tmsdb[0].x = pose.x
    req.tmsdb[0].y = pose.y
    req.tmsdb[0].ry = pose.theta  
    return


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
