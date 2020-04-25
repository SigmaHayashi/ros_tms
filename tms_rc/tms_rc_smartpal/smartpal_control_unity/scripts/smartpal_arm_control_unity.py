#!/usr/bin/env python
# -*- coding:utf-8 -*-

import rospy
from tms_msg_rc.srv import rc_robot_control, rc_robot_controlResponse
from tms_msg_rc.srv import sp5_control_unity, sp5_control_unityResponse
#from tms_msg_rc.srv import sp5_arm_control_unity, sp5_arm_control_unityResponse
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

srv_req = sp5_control_unity()
Trajectory = []

def main():
    print "Smartpal5_arm_control_unity"
    rospy.init_node('smartpal_arm_control_unity')

    service = rospy.Service("sp5_arm_control_unity", sp5_control_unity, moveTrajectory)
    sub = rospy.Subscriber("/move_group/fake_controller_joint_states", JointState, armPosCallBack)
    
    """
    first_ai = armInfo()
    for i in range(7):
      #first_ai.j_L.append(0.0)
      first_ai.j_L = [0]*7
    first_ai.move = 0
    first_ai.j_L[1] = -1.4
    Trajectory.append(first_ai)
    """
    
    r = rospy.Rate(30)
    while not rospy.is_shutdown():
        r.sleep()


def moveTrajectory(req):
    global srv_req
    global Trajectory

    srv_req.unit = 0 # all
    srv_req.cmd = 8 # move trajectory
    
    if len(Trajectory) == 0:
      srv_req.arg = req.arg
      callUnityService(srv_req)
      return sp5_control_unityResponse(1)

    for t in range(len(Trajectory)):
        temp_ai = Trajectory.pop(0)
        if temp_ai.move == 0:
          srv_req.arg = [0]*7
          for i in range(7):
            srv_req.arg[i] = temp_ai.j_L[i]
        else:
          srv_req.arg = [0]
          srv_req.arg[0] = temp_ai.gripperLeft
        """
        print "srv_req.unit : {0}".format(srv_req.unit)
        print "srv_req.cmd : {0}".format(srv_req.cmd)
        print "srv_req.arg : {0}".format(srv_req.arg[6])
        """
        callUnityService(srv_req)
    return sp5_control_unityResponse(1)


def callUnityService(s):
    rospy.wait_for_service('sp5_arm_control_uwp')
    try:
      arm_nav = rospy.ServiceProxy('sp5_arm_control_uwp', sp5_control_unity)
      result = arm_nav(s.unit, s.cmd, s.arg)
      return result 
    except rospy.ServiceException, e:
      print "Service call failed: %s"%e

def armPosCallBack(data):
    global Trajectory
    ai = armInfo()

    if data.name[0] == "l_gripper_thumb_joint":
        ai.gripperLeft = data.position[0]
        ai.move = 1
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
