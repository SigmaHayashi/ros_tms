cmake_minimum_required(VERSION 2.8.3)
project(tms_ur_notification)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tms_msg_ur
)

#catkin_python_setup()

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tms_ur_notification
   CATKIN_DEPENDS roscpp rospy tms_msg_ur
#  DEPENDS system_lib
)

###########
## Build ##
###########
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
