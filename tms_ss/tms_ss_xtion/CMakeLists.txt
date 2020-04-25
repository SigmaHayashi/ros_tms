cmake_minimum_required(VERSION 2.8.3)
project(tms_ss_xtion)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  pcl_ros
)
find_package(OpenCV REQUIRED)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  CATKIN_DEPENDS
    roscpp
    sensor_msgs
    pcl_ros
  DEPENDS
    OpenCV
)

###########
## Build ##
###########
# Enable C++11
ADD_DEFINITIONS(
  -std=gnu++11
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  estimateExtrinsicParameters/include
  include
)

add_executable(estimateExtrinsicParameters
  estimateExtrinsicParameters/src/main.cpp
  estimateExtrinsicParameters/src/MyCalibration.cpp
  estimateExtrinsicParameters/src/myutility.cpp
)

target_link_libraries( estimateExtrinsicParameters
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)

<<<<<<< HEAD
=======
add_dependencies(estimateExtrinsicParameters tms_ss_xtion_gencpp)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
