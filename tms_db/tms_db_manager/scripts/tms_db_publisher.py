#!/usr/bin/env python
<<<<<<< HEAD
# -*- coding: utf-8 -*-
import rospy
import genpy
import pymongo  # https://api.mongodb.org/python/2.6.3/
=======
# -*- coding: utf-8 -*- 
import rospy
import genpy
import pymongo # https://api.mongodb.org/python/2.6.3/
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
import json
import copy
from bson import json_util
from bson.objectid import ObjectId
from datetime import *
from tms_msg_db.msg import TmsdbStamped, Tmsdb
import tms_db_manager.tms_db_util as db_util

client = pymongo.MongoClient('localhost:27017')
db = client.rostmsdb

<<<<<<< HEAD

class TmsDbPublisher():

=======
class TmsDbPublisher():
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    def __init__(self):
        rospy.init_node("tms_db_publisher")
        rospy.on_shutdown(self.shutdown)

        db_host = 'localhost'
        db_port = 27017
<<<<<<< HEAD
        self.is_connected = db_util.check_connection(db_host, db_port)
=======
        self.is_connected = db_util.check_connection(db_host, db_port);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        if not self.is_connected:
            raise Exception("Problem of connection")

        self.data_pub = rospy.Publisher('tms_db_publisher', TmsdbStamped, queue_size=10)

        self.sendDbCurrentInformation()

    def sendDbCurrentInformation(self):
<<<<<<< HEAD
        rate = rospy.Rate(100)  # 100hz
=======
        rate = rospy.Rate(100) # 100hz
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

        while not rospy.is_shutdown():
            temp_dbdata = Tmsdb()
            current_environment_information = TmsdbStamped()

<<<<<<< HEAD
            # cursor = db.now.find({'$or': [{'state': 1}, {'state': 2}]})
            cursor = db.now.find()
=======
            cursor = db.now.find({'state':1})
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
            # print(cursor.count())
            for doc in cursor:
                del doc['_id']
                temp_dbdata = db_util.document_to_msg(doc, Tmsdb)
                current_environment_information.tmsdb.append(temp_dbdata)
            # rospy.loginfo("send db data!")
            self.data_pub.publish(current_environment_information)

            rate.sleep()

    def shutdown(self):
        rospy.loginfo("Stopping the node")

if __name__ == '__main__':
    try:
        TmsDbPublisher()
    except rospy.ROSInterruptException:
        rospy.loginfo("tms_db_publisher node terminated.")
