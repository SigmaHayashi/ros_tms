#include "ros/ros.h"
#include "std_msgs/String.h"
#include "../../rps.h"
#include <tms_msg_rp/rps_map_full.h>

#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
<<<<<<< HEAD
  ros::init(argc, argv, "rps_map_publisher");

  ros::NodeHandle n;
  ros::Publisher rps_map_pub = n.advertise< tms_msg_rp::rps_map_full >("rps_map_data", 1);

  vector< vector< CollisionMapData > > Map;
  tms_msg_rp::rps_map_full pub_Map;

  initCollisionMap(Map);
  string msg;
  setVoronoiLine(Map, msg);
  calcDistFromObj(Map, msg);
  convertMap(Map, pub_Map);

  while (ros::ok())
  {
    rps_map_pub.publish(pub_Map);
    ROS_INFO("MAP publish");
  }
=======
	ros::init(argc, argv, "rps_map_publisher");

	ros::NodeHandle n;
	ros::Publisher rps_map_pub = n.advertise<tms_msg_rp::rps_map_full>("rps_map_data", 1);
	
	vector<vector<CollisionMapData> > Map;
	tms_msg_rp::rps_map_full pub_Map;
	
	initCollisionMap(Map);
	string msg;
	setVoronoiLine(Map, msg);
	calcDistFromObj(Map, msg);
	convertMap(Map, pub_Map);
		
	while(ros::ok()){
		rps_map_pub.publish(pub_Map);
		ROS_INFO("MAP publish");
	}
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}
