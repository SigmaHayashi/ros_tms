cmake_minimum_required(VERSION 2.8.3)
project(tms_ss_vicon)

find_package(catkin REQUIRED COMPONENTS roscpp tms_msg_ss tms_msg_db)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES vicon_stream
  CATKIN_DEPENDS roscpp
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
  ${catkin_INCLUDE_DIRS}
)

link_directories(${LINK_DIRECTORIES} ${PROJECT_SOURCE_DIR}/viconSDK)

add_executable(vicon_stream src/vicon_stream.cpp)

<<<<<<< HEAD
add_dependencies(vicon_stream tms_msg_ss_generate_messages_cpp
=======
add_dependencies(vicon_stream tms_msg_ss_generate_messages_cpp 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
                              tms_msg_db_generate_messages_cpp)

target_link_libraries(vicon_stream ${catkin_LIBRARIES} ViconDataStreamSDK_CPP)
