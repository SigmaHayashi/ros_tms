cmake_minimum_required(VERSION 2.8.3)
project(tms_rc_kobuki_virtual_control)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  tms_msg_rc
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES kobuki_virtual_control
  CATKIN_DEPENDS geometry_msgs roscpp tms_msg_db tms_msg_rc
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

## Declare a cpp executable
 add_executable(kobuki_virtual_control src/kobuki_virtual_control.cpp)

<<<<<<< HEAD
 add_dependencies(kobuki_virtual_control tms_msg_rc_generate_messages_cpp)
 #add_dependencies(tms_msg_rc_gencpp tms_msg_db_gencpp)
=======
 add_dependencies(kobuki_virtual_control DEPENDS tms_msg_rc_gencpp tms_msg_db_gencpp)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

## Specify libraries to link a library or executable target against
 target_link_libraries(kobuki_virtual_control
   ${catkin_LIBRARIES}
 )
