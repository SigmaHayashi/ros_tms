cmake_minimum_required(VERSION 2.8.3)
project(tms_rc_pot)

<<<<<<< HEAD

#set( CMAKE_INCLUDE_PATH "/usr/include")
#set( CMAKE_LIBRARY_PATH "/usr/lib/x86_64-linux-gnu/libncurses.so")

=======
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
find_package(catkin REQUIRED COMPONENTS
  tms_msg_rc
  roscpp
  rospy
  tf
<<<<<<< HEAD
  geometry_msgs
  sensor_msgs
)

#find_package(Qt4 4.6 REQUIRED COMPONENTS QtCore QtGui)
#include(${QT_USE_FILE})
find_package(Boost REQUIRED COMPONENTS thread)

generate_messages(
=======
)

# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

 generate_messages(
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
   DEPENDENCIES
   std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tf_test
#  CATKIN_DEPENDS roscpp rospy tf turtle_sim
#  DEPENDS system_lib
)

include_directories(
<<<<<<< HEAD
  include
  ${catkin_INCLUDE_DIRS}
  ${BOOST_INCLUDE_DIRS}
#  ${QT_INCLUDE_DIRS}
)

#--------------------------------------------------------------------------
#portable_tf_first
#change serial data to odom
#--------------------------------------------------------------------------
add_executable(portable_tf_node_first src/portable_tf_first.cpp)
add_dependencies(portable_tf_node_first tf_first_generate_messages_cpp)
add_dependencies(portable_tf_node_first tms_msg_rc_generate_messages_cpp)
target_link_libraries(portable_tf_node_first ${catkin_LIBRARIES})

#--------------------------------------------------------------------------
#portable_tf_second
#change odom to link , to footprint
#--------------------------------------------------------------------------
add_executable(portable_tf_node_second src/portable_tf_second.cpp)
add_dependencies(portable_tf_node_second tf_second_generate_messages_cpp)
target_link_libraries(portable_tf_node_second ${catkin_LIBRARIES})

#--------------------------------------------------------------------------
#portable_keyop
#This node is to operate portable using keyboard
#--------------------------------------------------------------------------
add_executable(portable_keyop src/portable_keyop.cpp)
add_dependencies(portable_keyop tf_test_generate_messages_cpp)
target_link_libraries(portable_keyop ${catkin_LIBRARIES})

#--------------------------------------------------------------------------
#portable_stater
#publish odom_rad
#--------------------------------------------------------------------------
add_executable(portable_stater src/portable_stater.cpp)
add_dependencies(portable_stater tf_test_generate_messages_cpp tms_msg_rc_gencpp)
target_link_libraries(portable_stater ${catkin_LIBRARIES})

#--------------------------------------------------------------------------
#virtual_portable_stater
#publish virtual_odom_rad
#--------------------------------------------------------------------------
add_executable(portable_virtual_stater src/portable_virtual_stater.cpp)
add_dependencies(portable_virtual_stater tf_test_generate_messages_cpp tms_msg_rc_gencpp)
target_link_libraries(portable_virtual_stater ${catkin_LIBRARIES})

#--------------------------------------------------------------------------
#virtual_portable_laser
#publish virtual_odom_rad
#--------------------------------------------------------------------------
add_executable(portable_virtual_laser src/portable_virtual_laser.cpp)
add_dependencies(portable_virtual_laser tms_msg_rc_gencpp)
target_link_libraries(portable_virtual_laser ${catkin_LIBRARIES})

#--------------------------------------------------------------------------
#virtual_portable_laser2
#publish virtual_odom_rad
#--------------------------------------------------------------------------
add_executable(portable_virtual_laser2 src/portable_virtual_laser2.cpp)
add_dependencies(portable_virtual_laser2 tms_msg_rc_gencpp)
target_link_libraries(portable_virtual_laser2 ${catkin_LIBRARIES})
=======
  ${catkin_INCLUDE_DIRS}
)

add_executable(tf_test_node src/tf_test.cpp)
add_dependencies(tf_test_node tf_test_generate_messages_cpp tms_msg_rc_gencpp)
target_link_libraries(tf_test_node ${catkin_LIBRARIES})

add_executable(virtual_robot src/virtual_pot_robot.cpp)
add_dependencies(virtual_robot tf_test_generate_messages_cpp tms_msg_rc_gencpp)
target_link_libraries(virtual_robot ${catkin_LIBRARIES})
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
