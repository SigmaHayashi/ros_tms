#!/usr/bin/env python
# -*- coding:utf-8 -*-

import rospy
from geometry_msgs.msg import Pose2D, Twist
from tms_msg_rc.srv import rc_robot_control, rc_robot_controlResponse
from tms_msg_db.srv import TmsdbGetData, TmsdbGetDataRequest

def main():
    global GOAL
    global cmd
    global pose
    print "Turtlebot3_subtask_real"
    rospy.init_node ('turtlebot3_subtask_real')

    r = rospy.Rate(30)
    while not rospy.is_shutdown():
      tms_msg_db::TmsdbGetData srv
      srv.request.tms_msg_db.id = 2013
      srv.request.tms_msg_db.sensor = 3001

      rospy.wait_for_service('/tms_db_reader')
      tms_db = 

      tms_msg_rc::rc_robot_control turtlebot3_srv
      turtlebot3_srv.request.unit = 1
      turtlebot3_srv.request.cmd = 0
      turtlebot3_srv.request.arg.resize(size)

def distance(x1, y1, x2, y2):
    dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))
    return dis


def diffRadian(rad1, rad2):
    rad1 = normalizeAng(rad1)
    rad2 = normalizeAng(rad2)
    rad = normalizeAng(rad2- rad1)
    return rad


def normalizeAng(rad):
    while rad > pi:   # 角度を-180°~180°(-π~π)の範囲に合わせる
        rad = rad - (2 * pi)
    while rad < -pi:
        rad = rad + (2 * pi)
    return rad


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass