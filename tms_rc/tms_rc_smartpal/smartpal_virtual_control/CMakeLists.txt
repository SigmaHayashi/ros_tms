cmake_minimum_required(VERSION 2.8.3)
project(tms_rc_smartpal_virtual_control)

<<<<<<< HEAD
find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  geometry_msgs
=======
find_package(catkin REQUIRED COMPONENTS 
  roscpp 
  tf 
  geometry_msgs 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  nav_msgs
  tms_msg_rc
)
find_package(Boost REQUIRED COMPONENTS system)

###################################
## catkin specific configuration ##
###################################
catkin_package(
   #INCLUDE_DIRS include
   #LIBRARIES smartpal_control
   CATKIN_DEPENDS roscpp tf geometry_msgs nav_msgs message_runtime
<<<<<<< HEAD
   #DEPENDS system_lib
=======
   DEPENDS system_lib
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
)

###########
## Build ##
###########

include_directories(
  include
  SYSTEM
  ${catkin_INCLUDE_DIRS}
)

add_executable(smartpal_virtual_control

<<<<<<< HEAD
    src/smartpal5_virtual_control.cpp
)

 add_dependencies(smartpal_virtual_control tms_msg_rc_generate_messages_cpp)
#add_dependencies(tms_msg_rc_gencpp tms_msg_db_gencpp)
=======
    src/smartpal5_virtual_control.cpp 
)

add_dependencies(smartpal_virtual_control DEPENDS tms_msg_rc_gencpp tms_msg_db_gencpp)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

 target_link_libraries(smartpal_virtual_control ${catkin_LIBRARIES})
