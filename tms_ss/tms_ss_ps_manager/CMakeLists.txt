cmake_minimum_required(VERSION 2.8.3)
project(tms_ss_ps_manager)

find_package(catkin REQUIRED COMPONENTS 
  roscpp 
  tms_msg_ss
  tms_msg_db
  message_generation
  )

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
   LIBRARIES tms_ss_ps_manager
   CATKIN_DEPENDS message_runtime roscpp std_msgs
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

add_executable(rps_manager src/rps.cpp)
<<<<<<< HEAD
add_dependencies(rps_manager
=======
add_dependencies(rps_manager tms_ss_ps_gencpp 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
tms_msg_ss_gencpp 
tms_msg_db_gencpp
tms_msg_rp_gencpp)
target_link_libraries(rps_manager   ${catkin_LIBRARIES})

