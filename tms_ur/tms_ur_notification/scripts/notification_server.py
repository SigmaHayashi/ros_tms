#!/usr/bin/env python
# -*- coding:utf-8 -*-

import rospy
from tms_msg_ur.srv import tms_ur_notification, tms_ur_notificationResponse
import firebase_admin
from firebase_admin import messaging

def handle_notification(req):
     notification_title = req.title
     notification_body = req.body
     start_app = req.start_app

     rospy.loginfo("Notification Title : " + notification_title)
     rospy.loginfo("Notification Body : " + notification_body)
     rospy.loginfo("Start App : " + start_app)

     message = messaging.Message(
          topic = 'tms_ur_notification',
          notification = messaging.Notification(
               title = notification_title,
               body = notification_body
          ),
          data = {
               'notification.title': notification_title,
               'notification.body': notification_body,
               'start_app': start_app
          }
     )
     message_response = messaging.send(message)

     rospy.loginfo("Result : " + message_response)

     response = tms_ur_notificationResponse()
     response.result = message_response
     
     return response

def main():
     rospy.init_node('notification_server')
     rospy.loginfo('tms_ur_notification_server')

     service = rospy.Service('tms_ur_notification', tms_ur_notification, handle_notification)

     default_app = firebase_admin.initialize_app()

     #r = rospy.Rate(5)

     #while not rospy.is_shutdown():
     #     r.sleep()

if __name__ == '__main__':
     try:
          #print("Hello")
          main()
          rospy.spin()
     except rospy.ROSInterruptException:
          pass
