//------------------------------------------------------------------------------
// @file   : qnode.cpp
// @brief  : qt node function
// @author : Yoonseok Pyo, Masahide Tanaka
// @version: Ver0.9.5 (since 2012.05.17)
// @date   : 2012.11.14
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ros/ros.h>
#include <ros/network.h>

#include <string>
#include <sstream>

#include "qnode.hpp"

//------------------------------------------------------------------------------
// Implementation
//------------------------------------------------------------------------------
<<<<<<< HEAD
QNode::QNode(int argc, char **argv, const std::string &name) : init_argc(argc), init_argv(argv), node_name(name)
{
}
=======
QNode::QNode(int argc, char** argv, const std::string &name ) :
    init_argc(argc),
    init_argv(argv),
    node_name(name)
    {}
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

//------------------------------------------------------------------------------
QNode::~QNode()
{
<<<<<<< HEAD
  shutdown();
=======
    shutdown();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

//------------------------------------------------------------------------------
void QNode::shutdown()
{
<<<<<<< HEAD
  if (ros::isStarted())
  {
    ros::shutdown();
    ros::waitForShutdown();
  }
  wait();
=======
    if(ros::isStarted())
    {
        ros::shutdown();
        ros::waitForShutdown();
    }
    wait();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

//------------------------------------------------------------------------------
bool QNode::init()
{
<<<<<<< HEAD
  ros::init(init_argc, init_argv, node_name);

  if (!ros::master::check())
  {
    return false;
  }
  ros::start();
  start();
  return true;
=======
    ros::init(init_argc, init_argv, node_name);

    if ( ! ros::master::check() )
    {
        return false;
    }
    ros::start();
    start();
    return true;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

//------------------------------------------------------------------------------
void QNode::run()
{
<<<<<<< HEAD
  // ros::Rate loop_rate(40);     // 0.025sec
  while (ros::ok())
  {
    ros::spin();
    // ros::spinOnce();
    // loop_rate.sleep();
  }
  std::cout << "ROS shutdown, proceeding to close the gui." << std::endl;
  rosShutdown();  // used to signal the gui for a shutdown (useful to roslaunch)
=======
    //ros::Rate loop_rate(40);     // 0.025sec
    while ( ros::ok() )
    {
        ros::spin();
        //ros::spinOnce();
        //loop_rate.sleep();
    }
    std::cout << "ROS shutdown, proceeding to close the gui." << std::endl;
    rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

//------------------------------------------------------------------------------
