cmake_minimum_required(VERSION 2.8.3)
project(tms_rc_mimamorukun_control)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  tms_msg_db
  nav_msgs
  tf
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES kobuki_virtual_control
  CATKIN_DEPENDS geometry_msgs roscpp tms_msg_db tms_msg_rc nav_msgs
<<<<<<< HEAD
 # DEPENDS system_lib
=======
  DEPENDS system_lib
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  CATKIN_DEPENDS tf
)

###########
## Build ##
###########
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp executable
<<<<<<< HEAD
 add_executable(mimamorukun_hybrid_control src/mimamorukun_hybrid_control.cpp src/ClientSocket.cpp src/Socket.cpp)
 add_executable(mimamorukun_safe_control src/mimamorukun_safe_control.cpp src/ClientSocket.cpp src/Socket.cpp)
 add_executable(mimamorukun_node src/mimamorukun_node.cpp src/ClientSocket.cpp src/Socket.cpp)
 add_executable(mimamorukun_node_vicon src/mimamorukun_node_vicon.cpp src/ClientSocket.cpp src/Socket.cpp) 

 add_dependencies(mimamorukun_hybrid_control tms_msg_rc_gencpp tms_msg_db_gencpp)
 add_dependencies(mimamorukun_safe_control tms_msg_rc_gencpp tms_msg_db_gencpp)
 add_dependencies(mimamorukun_node tms_msg_rc_gencpp tms_msg_db_gencpp)
 add_dependencies(mimamorukun_node_vicon tms_msg_rc_gencpp tms_msg_db_gencpp)
 

## Specify libraries to link a library or executable target against
=======
 add_executable(mimamorukun_manual_control src/mimamorukun_manual_control.cpp src/ClientSocket.cpp src/Socket.cpp)
 add_executable(mimamorukun_automatic_control src/mimamorukun_automatic_control.cpp src/ClientSocket.cpp src/Socket.cpp)
 add_executable(mimamorukun_hybrid_control src/mimamorukun_hybrid_control.cpp src/ClientSocket.cpp src/Socket.cpp)
 add_executable(mimamorukun_safe_control src/mimamorukun_safe_control.cpp src/ClientSocket.cpp src/Socket.cpp)
 add_executable(mimamorukun_node src/mimamorukun_node.cpp src/ClientSocket.cpp src/Socket.cpp)

 add_dependencies(mimamorukun_manual_control DEPENDS tms_msg_rc_gencpp tms_msg_db_gencpp)
 add_dependencies(mimamorukun_automatic_control DEPENDS tms_msg_rc_gencpp tms_msg_db_gencpp)
 add_dependencies(mimamorukun_hybrid_control DEPENDS tms_msg_rc_gencpp tms_msg_db_gencpp)
 add_dependencies(mimamorukun_safe_control DEPENDS tms_msg_rc_gencpp tms_msg_db_gencpp)
 add_dependencies(mimamorukun_node DEPENDS tms_msg_rc_gencpp tms_msg_db_gencpp)

## Specify libraries to link a library or executable target against
 target_link_libraries(mimamorukun_manual_control
   ${catkin_LIBRARIES}
 )
 target_link_libraries(mimamorukun_automatic_control
   ${catkin_LIBRARIES}
 )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
 target_link_libraries(mimamorukun_hybrid_control
   ${catkin_LIBRARIES}
 )
 target_link_libraries(mimamorukun_safe_control
   ${catkin_LIBRARIES}
 )
 target_link_libraries(mimamorukun_node
   ${catkin_LIBRARIES}
 )
<<<<<<< HEAD
 target_link_libraries(mimamorukun_node_vicon
   ${catkin_LIBRARIES}
 )
=======
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
