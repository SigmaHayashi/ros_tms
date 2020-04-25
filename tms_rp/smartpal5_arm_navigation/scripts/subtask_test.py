#!/usr/bin/env python

"""
    subtask_pick.py - Version 0.0.2 2015-09-20

    Command the gripper to grasp a target object and move it to a new location, all
    while avoiding simulated obstacles.

    Copyright 2014 by Patrick Goebel <patrick@pirobot.org, www.pirobot.org>
    Copyright 2015 by YS Pyo <passionvirus@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details at:

    http://www.gnu.org/licenses/gpl.html
"""

import rospy
import sys
import moveit_commander
from geometry_msgs.msg import PoseStamped, Pose
from moveit_commander import MoveGroupCommander, PlanningSceneInterface
from moveit_msgs.msg import PlanningScene, ObjectColor
from moveit_msgs.msg import Grasp, GripperTranslation, MoveItErrorCodes
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from tf.transformations import quaternion_from_euler
from copy import deepcopy
from tms_msg_db.msg import TmsdbStamped, Tmsdb
from tms_msg_db.srv import *
from tms_msg_rp.srv import *

from tms_msg_rc.srv import sp5_control_unity, sp5_control_unityResponse
from tms_msg_rc.srv import robot_control, robot_controlResponse
from tms_msg_rc.srv import smartpal_control, smartpal_controlResponse
from tms_msg_rp.msg import rps_position
from tms_msg_rp.srv import rps_path_server, rps_path_serverResponse

GROUP_NAME_ARM = 'l_arm'
GROUP_NAME_GRIPPER = 'l_gripper'

GRIPPER_FRAME = 'l_end_effector_link'
GRIPPER_OPEN = [-1.0]
GRIPPER_CLOSED = [-0.7]
GRIPPER_NEUTRAL = [-0.2]
GRIPPER_JOINT_NAMES = ['l_gripper_thumb_joint']
GRIPPER_EFFORT = [1.0]

REFERENCE_FRAME = 'world_link'

INIT_ARM_VALUE = [0.0, -0.17, 0.0, 0.0, 0.0, 0.0, 0.0]
GRASP_ARM_VALUE = [0.0, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0]

def main():
    # Initialize the move_group API
    moveit_commander.roscpp_initialize(sys.argv)
    rospy.init_node("moveit_test")

    # Initialize the move group for the right arm
    arm = MoveGroupCommander(GROUP_NAME_ARM)
    # Initialize the move group for the right gripper
    #gripper = MoveGroupCommander(GROUP_NAME_GRIPPER)

    arm.set_goal_position_tolerance(0.05)
    arm.set_goal_orientation_tolerance(0.1)

    # Allow replanning to increase the odds of a solution
    #arm.allow_replanning(True)

    # Allow 5 seconds per planning attempt
    #arm.set_planning_time(5)
    # Set a limit on the number of pick attempts before bailing
    #$max_pick_attempts = 5
    # Give the scene a chance to catch up
    #rospy.sleep(0.05)

    arm.set_named_target('l_arm_init')
    arm.go()
    rospy.sleep(0.05)
    print("***** arm moved to initial pose")

    target_pose = PoseStamped()
    target_pose.header.frame_id = REFERENCE_FRAME
    target_pose.pose.position.x = 6.98
    target_pose.pose.position.y = 2.85
    target_pose.pose.position.z = 0.91 + 0.01

    q = quaternion_from_euler(0, 0, 0)
    target_pose.pose.orientation.x = q[0]
    target_pose.pose.orientation.y = q[1]
    target_pose.pose.orientation.z = q[2]
    target_pose.pose.orientation.w = q[3]

    print(target_pose.pose.position.x)
    print(target_pose.pose.position.y)
    print(target_pose.pose.position.z)

    arm.set_pose_target(target_pose)

    arm.go()
    rospy.sleep(1)

    arm.clear_pose_targets()

    ps = []
    temp = rps_position()
    temp.x = 8.0
    temp.y = 2.477
    temp.z = 0.0
    temp.th = 1.944
    temp.roll = 0.0
    temp.pitch = 0.0
    temp.yaw = 0.0
    ps.append(temp)
    temp2 = rps_position()
    temp2.x = 8.3
    temp2.y = 3.2
    temp2.z = 0.0
    temp2.th = 1.5
    temp2.roll = 0.0
    temp2.pitch = 0.0
    temp2.yaw = 0.0
    ps.append(temp2)
    print ps

    callUnitySrvTest(ps)

    srv = sp5_control_unity()
    srv.unit = 0
    srv.cmd = 8
    srv.arg = [0]
    #callUnityControler(srv)

    #r_srv = robot_control()
    r_srv = smartpal_control()
    r_srv.unit = 0
    r_srv.cmd = 8
    r_srv.arg = [0]*8
    #callRobotControler(r_srv)

def callUnitySrvTest(ps):
    rospy.wait_for_service('sp5_control_unity')
    try:
        move_test = rospy.ServiceProxy('sp5_control_unity', rps_path_server)
        result = move_test(ps)
        return result
    except rospy.ServiceException, e:
      print "Service call failed: %s"%e

def callUnityControler(s):
    rospy.wait_for_service('sp5_arm_control_unity')
    try:
        arm_navi = rospy.ServiceProxy('sp5_arm_control_unity', sp5_control_unity)
        result = arm_navi(s.unit, s.cmd, s.arg)
        return result
    except rospy.ServiceException, e:
      print "Service call failed: %s"%e

def callRobotControler(rs):
    rospy.wait_for_service('sp5_control')
    try:
        sp5_client = rospy.ServiceProxy('sp5_control', smartpal_control)
        result = sp5_client(rs.unit, rs.cmd, rs.arg)
        return result
    except rospy.ServiceException, e:
      print "Service call failed: %s"%e

if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException:
        rospy.loginfo("subtask_test node terminated.")

"""
class SubTaskTest:
     def __init__(self):
        # Initialize the move_group API
        moveit_commander.roscpp_initialize(sys.argv)
        rospy.init_node('subtask_test')
        rospy.on_shutdown(self.shutdown)

        self.test_srv = rospy.Service('subtask_test', rp_pick, self.testSrvCallback)

     def testSrvCallBack(self, req):
        rospy.loginfo("Received the service call!")
        rospy.loginfo(req)
        print("***** Test moveit can run")
"""