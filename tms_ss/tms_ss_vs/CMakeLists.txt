cmake_minimum_required(VERSION 2.8.3)
project(tms_ss_vs)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  tms_msg_db
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  # INCLUDE_DIRS include
  LIBRARIES tms_ss_vs
  CATKIN_DEPENDS rospy std_msgs tms_msg_db
<<<<<<< HEAD
 # DEPENDS system_lib
=======
  DEPENDS system_lib
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
)

###########
## Build ##
###########
include_directories(
  ${catkin_INCLUDE_DIRS}
)
