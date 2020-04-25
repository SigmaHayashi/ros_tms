cmake_minimum_required(VERSION 2.8.3)
project(smartpal5_gazebo)

<<<<<<< HEAD
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

=======
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	std_msgs
  gazebo_ros
  urdf
)

find_package(gazebo REQUIRED)

include_directories(
  ${Boost_INCLUDE_DIR}
	${catkin_INCLUDE_DIRS}
	${GAZEBO_INCLUDE_DIRS}
)

link_directories(${GAZEBO_LIBRARY_DIRS})

catkin_package(
  LIBRARIES smartpal
  CATKIN_DEPENDS roscpp rospy gazebo_ros std_msgs
<<<<<<< HEAD
  #DEPENDS system_lib
=======
  DEPENDS system_lib
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
)

# add_executable(smartpal5_gazebo src/smartpal5_gazebo.cpp)
add_library(smartpal src/smartpal5_gazebo.cpp)
target_link_libraries(smartpal
  ${catkin_LIBRARIES}
  ${GAZEBO_LIBRARIES}
)
