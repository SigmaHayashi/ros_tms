#!/usr/bin/env python
# -*- coding:utf-8 -*-

import rospy
from mav_msgs.msg import RollPitchYawrateThrust
from geometry_msgs.msg import Vector3
import sys, select, termios, tty

pub = rospy.Publisher("RPY_controler", RollPitchYawrateThrust, queue_size = 10)

def main():
     print "Calibration uwp"
     rospy.init_node('calibration_unity')

     status = 0
     roll = 0.0
     pitch = 0.0
     yaw = 0.0
     thrust = Vector3()
     rpy = RollPitchYawrateThrust()
     while(1):
          key = getKey()
          status = status + 1
          if key == 'pageup':
               roll = roll + 0.1
          elif key == 'pagedown':
               roll = roll - 0.1
          elif key == 'up':
               pitch = pitch + 0.1
          elif key == 'down':
               pitch = pitch - 0.1
          elif key == 'right':
               yaw = yaw + 0.1
          elif key == 'left':
               yaw = yaw - 0.1
          else:
               if (key == '\x03'):
                    break

          if status == 20:
               print roll + ", " + pitch + ", " + yaw
               status = 0

          rpy.roll = roll
          rpy.pitch = pitch
          rpy.yaw_rate = yaw
          rpy.thrust = thrust
          pub.publish(rpy)
          



def getKey():
     tty.setraw(sys.stdin.fileno())
     rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
     if rlist:
          key = sys.stdin.read(1)
     else:
          key = ''

     termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
     return key


if __name__ == '__main__':
     try:
          main()
     except rospy.ROSInterruptException:
          pass

     termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)