using namespace std;
#include <ros/ros.h>
#include <tms_msg_ts/ts_state_control.h>

#include <tms_msg_rc/rc_robot_control.h>

#include <tms_msg_db/TmsdbStamped.h>
#include <tms_msg_db/Tmsdb.h>
#include <tms_msg_db/TmsdbGetData.h>

#include <std_srvs/Empty.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265       // 180
#define HALF_PI 1.57079633  // 90

int main(int argc, char **argv)
{
  // Init ROS node
  ros::init(argc, argv, "tms_ts_subtask_real");

  

  ros::spin();
  return 0;
}