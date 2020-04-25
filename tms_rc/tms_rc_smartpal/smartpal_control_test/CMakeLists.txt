cmake_minimum_required(VERSION 2.8.3)
project(tms_rc_smartpal_control_test)

find_package(catkin REQUIRED COMPONENTS roscpp tms_msg_rc)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(smartpal4_control_test_getpos src/smartpal4_control_test_getpos.cpp)
add_executable(smartpal4_control_test_move src/smartpal4_control_test_move.cpp)

add_executable(smartpal5_control_test_getpos src/smartpal5_control_test_getpos.cpp)
add_executable(smartpal5_control_test_move src/smartpal5_control_test_move.cpp)

<<<<<<< HEAD
add_dependencies(smartpal4_control_test_getpos tms_msg_rc_gencpp)
add_dependencies(smartpal4_control_test_move tms_msg_rc_gencpp)

add_dependencies(smartpal5_control_test_getpos tms_msg_rc_gencpp)
add_dependencies(smartpal5_control_test_move tms_msg_rc_gencpp)
=======
add_dependencies(smartpal4_control_test_getpos DEPENDS tms_msg_rc_gencpp)
add_dependencies(smartpal4_control_test_move DEPENDS tms_msg_rc_gencpp)

add_dependencies(smartpal5_control_test_getpos DEPENDS tms_msg_rc_gencpp)
add_dependencies(smartpal5_control_test_move DEPENDS tms_msg_rc_gencpp)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

target_link_libraries(smartpal4_control_test_getpos ${catkin_LIBRARIES})
target_link_libraries(smartpal4_control_test_move ${catkin_LIBRARIES})

target_link_libraries(smartpal5_control_test_getpos ${catkin_LIBRARIES})
target_link_libraries(smartpal5_control_test_move ${catkin_LIBRARIES})
