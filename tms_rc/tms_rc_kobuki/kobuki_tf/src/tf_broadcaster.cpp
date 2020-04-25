#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

<<<<<<< HEAD
int main(int argc, char** argv)
{
=======
int main(int argc, char** argv){
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  ros::init(argc, argv, "kobuki_tf");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

<<<<<<< HEAD
  while (n.ok())
  {
    broadcaster.sendTransform(
        tf::StampedTransform(tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.0, 0.01)), ros::Time::now(),
                             "base_footprint", "base_link"));

    broadcaster.sendTransform(
        tf::StampedTransform(tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.0, 0.24)), ros::Time::now(),
                             "base_link", "base_scan"));
=======
  while(n.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(
          tf::Quaternion(0, 0, 0, 1),
          tf::Vector3(0.0, 0.0, 0.01)),
          ros::Time::now(),
          "base_footprint",
          "base_link"));

    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(
          tf::Quaternion(0, 0, 0, 1),
          tf::Vector3(0.0, 0.0, 0.24)),
          ros::Time::now(),
          "base_link",
          "base_scan"));
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

    r.sleep();
  }
}
