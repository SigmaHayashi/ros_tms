cmake_minimum_required(VERSION 2.8.3)
project(tms_db_timer_hl)

find_package(catkin REQUIRED COMPONENTS
  tf
  roscpp
  std_msgs
  sensor_msgs
  tms_msg_db
)

catkin_package(
  #INCLUDE_DIRS include
  LIBRARIES tms_db_timer_hl
  CATKIN_DEPENDS roscpp std_msgs sensor_msgs tms_msg_db rospy
  #DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
