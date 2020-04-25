//------------------------------------------------------------------------------
// @file   : qnode.cpp
// @brief  : QT + ROS node Implementation
// @author : Yoonseok Pyo, Masahide Tanaka
// @version: Ver0.4 (since 2012.06.05)
// @date   : 2012.11.26
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
// Namespaces
//------------------------------------------------------------------------------
<<<<<<< HEAD
namespace bas_graph
{
//------------------------------------------------------------------------------
// Implementation
//------------------------------------------------------------------------------
QNode::QNode(int argc, char** argv) : init_argc(argc), init_argv(argv)
=======
namespace bas_graph {

//------------------------------------------------------------------------------
// Implementation
//------------------------------------------------------------------------------
QNode::QNode(int argc, char** argv ) :
    init_argc(argc),
    init_argv(argv)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
{
}

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
  ros::init(init_argc, init_argv, "bas_graph");

  if (!ros::master::check())
  {
    return false;
  }
  ros::start();

  ros::NodeHandle nh;
  bas_graph_subscriber = nh.subscribe("bas_behavior_data", 10, &QNode::behaviorCallback, this);

  start();
  return true;
=======
    ros::init(init_argc, init_argv, "bas_graph");

    if ( ! ros::master::check() )
    {
        return false;
    }
    ros::start();

    ros::NodeHandle nh;
    bas_graph_subscriber = nh.subscribe("bas_behavior_data", 10, &QNode::behaviorCallback, this);

    start();
    return true;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

//------------------------------------------------------------------------------
void QNode::behaviorCallback(const tms_msg_ss::bas_behavior_data::ConstPtr& msg)
{
<<<<<<< HEAD
  m_bas_behavior_data = *msg;
=======
    m_bas_behavior_data = *msg;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

//------------------------------------------------------------------------------
void QNode::run()
{
<<<<<<< HEAD
  while (ros::ok())
  {
    ros::spin();
  }
  std::cout << "ROS shutdown, proceeding to close the gui." << std::endl;
  rosShutdown();  // used to signal the gui for a shutdown (useful to roslaunch)
=======
    while ( ros::ok() )
    {
        ros::spin();
    }
    std::cout << "ROS shutdown, proceeding to close the gui." << std::endl;
    rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

//------------------------------------------------------------------------------
}  // namespace bas_graph

//------------------------------------------------------------------------------
