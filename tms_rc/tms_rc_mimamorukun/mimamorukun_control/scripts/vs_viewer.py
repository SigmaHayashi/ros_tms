#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys
# import platform
import PyQt4.QtCore as QtCore
import PyQt4.QtGui as QtGui
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
# from tms_msg_db.srv import TmsdbGetData
import tms_msg_db.srv
<<<<<<< HEAD
# include <tms_msg_db/TmsdbGetData.h>
=======
#include <tms_msg_db/TmsdbGetData.h>
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7


def main():
    print "Hello World"

<<<<<<< HEAD
    # init ROS
=======
    ###init ROS
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    rospy.init_node('tms_ss_vs_viewer')
    print ("wainting for DB service server")
    rospy.wait_for_service('/tms_db_reader/dbreader')
    print ("found DB service server")
    try:
        db_client = rospy.ServiceProxy("/tms_db_reader/dbreader", tms_msg_db.srv.TmsdbGetData)
        # db_client = n.serviceClient<tms_msg_db::TmsdbGetData>("/tms_db_reader/dbreader");
        # req = TmsdbGetDataRequest()
        req = tms_msg_db.srv.TmsdbGetDataRequest()

        req.tmsdb.id = 3018
        req.tmsdb.sensor = 3018
        res = db_client(req)
        if 0 < len(res.tmsdb):
            print (res.tmsdb[0].note)
<<<<<<< HEAD
    except rospy.ServiceException as e:
=======
    except rospy.ServiceException, e:
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        print "Service call failed: %s" % e
    while True:
        pass


if __name__ == '__main__':
    main()
