#!/usr/bin/python
# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import Bool
from tms_msg_rp.srv import *
import random

import os
import sys
import time
from time import time

start = time()

def set_sim(sim_time):
    rospy.init_node('set_sim_pub')
    pub = rospy.Publisher("set_sim_req", Bool, queue_size=1)

    start = time()
    while time() - start < sim_time:
        topic = Bool(True)
        pub.publish(topic)
        rospy.sleep(0.1)
    start = time()
    while time() - start < sim_time:
        topic = Bool(False)
        pub.publish(topic)
        rospy.sleep(0.1)
    print 'done'

if __name__ == '__main__':
    try:
        set_sim(3)
    except rospy.ROSInterruptException:
        rospy.loginfo("set_sim_pub node terminated.")

    '''
    print "start time %f" % (start)
    print "end time %f" % (end)
    print "time %f" % (end - start)

    try:
        changevisual(False)
    except rospy.ROSInterruptException:
        rospy.loginfo("Visible node terminated.")

    try:
        changevisual(True)
    except rospy.ROSInterruptException:
        rospy.loginfo("Visible node terminated.")
    '''
