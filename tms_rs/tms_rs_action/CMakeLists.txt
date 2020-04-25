cmake_minimum_required(VERSION 2.8.3)
project(tms_rs_action)

<<<<<<< HEAD
find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
=======
find_package(catkin REQUIRED COMPONENTS 
  roscpp 
  geometry_msgs 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  nav_msgs
  tms_msg_rs
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
   #INCLUDE_DIRS include
   #LIBRARIES smartpal_simple_task
   CATKIN_DEPENDS roscpp geometry_msgs nav_msgs message_runtime
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

add_executable(smartpal_simple_task

<<<<<<< HEAD
    src/tms_rs_simple_task.cpp
)

add_dependencies(smartpal_simple_task tms_msg_rs_generate_messages_cpp)

#add_dependencies(tms_msg_rs_gencpp tms_msg_rp_gencpp tms_msg_db_gencpp)
=======
    src/tms_rs_simple_task.cpp 
)

add_dependencies(smartpal_simple_task DEPENDS tms_msg_rs_gencpp tms_msg_rp_gencpp tms_msg_db_gencpp)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

target_link_libraries(smartpal_simple_task ${catkin_LIBRARIES})

add_executable(simpletask_service

<<<<<<< HEAD
    src/simpletask_service.cpp
)

add_dependencies(simpletask_service tms_msg_rs_generate_messages_cpp)

#add_dependencies(tms_msg_rs_gencpp tms_msg_rp_gencpp tms_msg_db_gencpp)
=======
    src/simpletask_service.cpp 
)

add_dependencies(simpletask_service DEPENDS tms_msg_rs_gencpp tms_msg_rp_gencpp tms_msg_db_gencpp)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

target_link_libraries(simpletask_service ${catkin_LIBRARIES})

#add_executable(smartpal_rp_move

<<<<<<< HEAD
 #   src/tms_rs_rpmove.cpp
=======
 #   src/tms_rs_rpmove.cpp 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#)

#add_dependencies(smartpal_rp_move DEPENDS tms_msg_rc_gencpp tms_msg_rp_gencpp tms_msg_db_gencpp)

#target_link_libraries(smartpal_rp_move ${catkin_LIBRARIES})
