#!/usr/bin/env python
# -*- coding:utf-8 -*-

import rospy
from tms_msg_rc.srv import rc_robot_control, rc_robot_controlResponse
from tms_msg_rc.msg import sp5_unity
from sensor_msgs.msg import JointState
import datetime
from math import sin, cos, atan2, pi, radians, degrees, sqrt

class armInfo:
    def __init__(self):
        self.move = 0
        self.j_L = []
        self.gripperLeft = 0
        self.j_R = []
        self.gripperRight = 0
    """
    move = 0
    j_L = []
    gripperLeft = 0
    j_R = []
    gripperRight = 0
    """


Goal = sp5_unity()
Vpos = sp5_unity()
Trajectory = []
l = 3

def main():
    global Goal
    
    print "Smartpal5_control_unity"
    rospy.init_node('smartpal_control_unity')

    service = rospy.Service("sp5_control_unity", rc_robot_control, goalPoseCallBack)
    pub = rospy.Publisher("/sp5Goal/unity", sp5_unity, queue_size = 10)
    sub = rospy.Subscriber("/sp5Pos/unity", sp5_unity, virtualPosCallBack)
    sub = rospy.Subscriber("/move_group/fake_controller_joint_states", JointState, armPosCallBack)

    r = rospy.Rate(30)
    while not rospy.is_shutdown():
        if None == Goal.cmd:
            continue
        """
        elif Goal.cmd == 8:
            if len(Goal.arg) < 7:
                continue
        else:
            if len(Goal.arg) < 3:
                continue
        """

        pub.publish(Goal)
        r.sleep()

def goalPoseCallBack(req):
    global Goal
    Goal = sp5_unity()
    global Vpos
    global l

    print "unit : {0}".format(req.unit)
    print "cmd : {0}".format(req.cmd)
    print "arg_size : {0}".format(len(req.arg))

    if req.cmd == 15 or req.cmd == 16: # cmd_move_abs or cmd_move_rel
        l = 3
        Goal.gripper = False
    elif req.cmd == 8: # cmd_move_trajectory
        l = 7
        moveTrajectory()
    print "l : {0}".format(l)
    Goal.unit = req.unit
    Goal.cmd = req.cmd
    for i in range(l):
        Goal.arg.append(req.arg[i])
    while True:
        s = 0
        for j in range(l):
            if Goal.arg[j] - Vpos.arg[j] < 0.01 and Goal.arg[j] - Vpos.arg[j] > -0.01:
                s = s + 1
        if s == l:
            Goal.cmd = None
            Goal.arg = []
            return rc_robot_controlResponse()
    return rc_robot_controlResponse()

def moveTrajectory():
    global Goal
    global Trajectory
    global l

    for t in range(len(Trajectory)):
        temp_ai = Trajectory.pop(0)
        if temp_ai.move == 0:
            l = 7
            Goal.gripper = False
            for i in range(l):
                Goal.arg[i] = temp_ai.j_L[i]
        else:
            l = 1
            Goal.gripper = True
            Goal.arg[0] = temp_ai.gripperLeft
        while True:
            s = 0
            for j in range(l):
                if Goal.arg[j] - Vpos.arg[j] < 0.01 and Goal.arg[j] - Vpos.arg[j] > -0.01:
                    s = s + 1
            if s == l:
                break

def virtualPosCallBack(data):
    global Vpos
    global l
    for i in range(l):
      Vpos.arg.append(data.arg[i])

def armPosCallBack(data):
    global Trajectory
    ai = armInfo()

    if data.name[0] == "l_gripper_thumb_joint":
        ai.gripperLeft = data.position[0]
        ai.move = 0
    elif data.name[0] == "l_arm_j1_joint":
        for i in range(7):
            ai.j_L.append(data.position[i])
        ai.move = 0
    Trajectory.append(ai)

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass