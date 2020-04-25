#!/usr/bin/env python
# -*- coding:utf-8 -*-

<<<<<<< HEAD
# @file    afe.py
=======
## @file    afe.py
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#  @brief   OEL blood stream sensor node
#  @author  Akio Shigekane
#  @date    2015.3.3

import rospy
import serial
import json
import traceback
import pprint
import subprocess

from std_msgs.msg import Int32

PORT = "/dev/ttyUSB0"
KEYS = (u"Raw", u"HBR")

dev = serial.Serial(
    port=None,
    baudrate=115200,
<<<<<<< HEAD
)
=======
    )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
dev.port = PORT


def main():
    print "Hello World"
<<<<<<< HEAD
    cmd_chmod = "sudo chmod a+rw " + PORT
    print cmd_chmod + "\n", subprocess.check_output(cmd_chmod.split(" "))
=======
    cmd_chmod = "sudo chmod a+rw "+PORT
    print cmd_chmod+"\n",   subprocess.check_output(cmd_chmod.split(" "))
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    dev.open()
    pub = {}
    pub[KEYS[0]] = rospy.Publisher('afe/blood_pressue', Int32, queue_size=10)
    pub[KEYS[1]] = rospy.Publisher('afe/hbr', Int32, queue_size=10)
    rospy.init_node("afe", anonymous=False)
    est = {}
    est[KEYS[0]] = 0
    est[KEYS[1]] = 0
    est_K = {}
    est_K[KEYS[0]] = 0.95
    est_K[KEYS[1]] = 0.5
    # print subprocess.check_output("rqt_plot /afe/blood_pressue &".split(" "))
    # print subprocess.check_output("rqt_plot /afe/period &".split(" "))
    r = rospy.Rate(50)
    while not rospy.is_shutdown():
        r.sleep()
        print ""
        in_js = dev.readline().replace('\n\r', '')
        print "in:", in_js
        try:
            in_dic = json.loads(in_js)
            pprint.pprint(in_dic)
            for key, val in in_dic.items():
                # pub[key].publish(val)
<<<<<<< HEAD
                est[key] = est_K[key] * est[key] + (1 - est_K[key]) * val
=======
                est[key] = est_K[key]*est[key] + (1-est_K[key])*val
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
                pub[key].publish(est[key])
        except:
            print traceback.format_exc()

if __name__ == '__main__':
    main()
