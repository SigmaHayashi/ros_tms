#!/usr/bin/env python
# -*- coding:utf-8 -*-

import serial
import json
import datetime
import time
import subprocess
import rospy
<<<<<<< HEAD
# import roslib
=======
#import roslib
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
from tms_msg_rs.srv import *
from tms_msg_db.msg import TmsdbStamped
from tms_msg_db.msg import Tmsdb

DEV_PORT = "/dev/ttyUSB0"

if __name__ == '__main__':
    print "Hello World"

<<<<<<< HEAD
    # init device
    cmd_chmod = "sudo chmod a+rw " + DEV_PORT
    print cmd_chmod + "\n", subprocess.check_output(cmd_chmod.split(" "))
    dev = serial.Serial(port=DEV_PORT, baudrate=9600)

    # init ROS
=======
    # ##init device
    cmd_chmod = "sudo chmod a+rw "+DEV_PORT
    print cmd_chmod+"\n",   subprocess.check_output(cmd_chmod.split(" "))
    dev = serial.Serial(port=DEV_PORT, baudrate=9600)

    # ##init ROS
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    rospy.init_node('tms_ss_vs_heartrate')
    db_pub = rospy.Publisher('tms_db_data', TmsdbStamped, queue_size=10)
    r = rospy.Rate(1)
    while not rospy.is_shutdown():
        r.sleep()
<<<<<<< HEAD
        # get heartrate value
=======
        # ##get heartrate value
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        dev.write("G5\r")  # get heartrate buffer[0~4]
        time.sleep(0.5)
        ret = dev.read(dev.inWaiting())
        rate = ret.split(" ")[2]
<<<<<<< HEAD
        print "heartrate:" + rate + "     raw:" + ret
=======
        print "heartrate:"+rate+"     raw:"+ret
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        if int(rate) == 0:
            print "    failed to get heartrate value"
            continue

<<<<<<< HEAD
        # make json text
=======
        # ##make json text
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        note_d = {"heartrate": rate}
        # print json.dumps(note_d, indent=4)
        note_j = json.dumps(note_d)

<<<<<<< HEAD
        # regist to DB
=======
        # ##regist to DB
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        msg = TmsdbStamped()
        db = Tmsdb()
        db.time = datetime.datetime.now().strftime("%Y-%m-%dT%H:%M:%S.%f")
        db.name = "heartrate_sensor"
        db.id = 3018
        db.sensor = 3018
        db.place = 1001
        db.note = note_j
        msg.tmsdb.append(db)
<<<<<<< HEAD
        msg.header.stamp = rospy.get_rostime() + rospy.Duration(9 * 60 * 60)
=======
        msg.header.stamp = rospy.get_rostime()+rospy.Duration(9*60*60)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        db_pub.publish(msg)
