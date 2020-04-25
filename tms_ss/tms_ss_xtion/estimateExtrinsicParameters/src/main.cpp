#include <stdio.h>
#include <time.h>
#include <float.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdint>

#include <unistd.h>

#include <boost/make_shared.hpp>
#include <boost/algorithm/string.hpp>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/pcd_io.h>
#include <opencv2/opencv.hpp>
#include <Eigen/Eigen>

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/PointCloud2.h>

#include "MyCalibration.h"
#include "myutility.h"

extern Eigen::Vector2i g_points[4];

// Variables for debug
bool g_DebugFlg = false;
double d_roll, d_pitch, d_yaw;
double d_tx, d_ty, d_tz;
int d_convertion_method = 2;
<<<<<<< HEAD
int main(int argc, char **argv)
{
  int option;
  float pattern_width = 45.0;
  double convertion_threshold = 0.0001;
  while ((option = getopt(argc, argv, "dht:w:0:1")) != -1)
=======
int main (int argc, char **argv)
{
  int option;
  float pattern_width=45.0;
  double convertion_threshold = 0.0001;
  while ((option=getopt(argc,argv,"dht:w:0:1"))!=-1)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    char tmp = '\0';
    if (optarg == NULL)
    {
      optarg = &tmp;
    }
    std::string args(optarg);
    std::string delim(",");
<<<<<<< HEAD
    std::vector< std::string > list_args;
    switch (option)
    {
      case 'h':
        std::cout << "-- Usage" << std::endl
                  << "  -d flag for debug" << std::endl
                  << "In Debug Mode: " << std::endl
                  << "  -0\t"
                  << "[roll],[pitch],[yaw],[tx],[ty],[tz]" << std::endl
                  << "  -1\t"
                  << "Switch convertion method. (Perturbation method -> Steepest descent method)" << std::endl
                  << std::endl;
        return 0;
        break;
      case 'd':
        g_DebugFlg = true;
        break;
      case 't':
        convertion_threshold = atof(args.c_str());
        break;
      case 'w':
        pattern_width = atof(args.c_str());
        break;
      case '0':
        if (g_DebugFlg)
        {
          boost::split(list_args, args, boost::is_any_of(delim));
          d_roll = atof(list_args[0].c_str());
          d_pitch = atof(list_args[1].c_str());
          d_yaw = atof(list_args[2].c_str());
          d_tx = atof(list_args[3].c_str());
          d_ty = atof(list_args[4].c_str());
          d_tz = atof(list_args[5].c_str());
        }
        break;
      case '1':
        if (g_DebugFlg)
        {
          d_convertion_method = 1;
        }
        break;
      case ':':
        std::cerr << "Need some values" << std::endl;
        break;
      case '?':
        std::cerr << "unknown option" << std::endl;
        break;
    }
  }

=======
    std::vector<std::string> list_args;
    switch(option)
    {
    case 'h':
      std::cout << "-- Usage" << std::endl <<
        "  -d flag for debug" << std::endl <<
        "In Debug Mode: " << std::endl <<
        "  -0\t" << "[roll],[pitch],[yaw],[tx],[ty],[tz]" << std::endl <<
        "  -1\t" << "Switch convertion method. (Perturbation method -> Steepest descent method)" << std::endl <<
        std::endl;
      return 0;
      break;
    case 'd':
      g_DebugFlg = true;
      break;
    case 't':
      convertion_threshold = atof(args.c_str());
      break;
    case 'w':
      pattern_width = atof(args.c_str());
      break;
    case '0':
      if (g_DebugFlg)
      {
        boost::split(list_args, args, boost::is_any_of(delim));
        d_roll = atof(list_args[0].c_str());
        d_pitch = atof(list_args[1].c_str());
        d_yaw = atof(list_args[2].c_str());
        d_tx = atof(list_args[3].c_str());
        d_ty = atof(list_args[4].c_str());
        d_tz = atof(list_args[5].c_str());
      }
      break;
    case '1':
      if (g_DebugFlg)
      {
        d_convertion_method = 1;
      }
      break;
    case ':':
      std::cerr << "Need some values" << std::endl;
      break;
    case '?':
      std::cerr << "unknown option" << std::endl;
      break;
    }
  }


>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  ros::init(argc, argv, "ExtrinsicParameterEstimation");
  ros::NodeHandle ros_nh;

  cv::namedWindow("Depth image");
  cv::setMouseCallback("Depth image", mouseCallback, 0);

<<<<<<< HEAD
  // For Debug
=======
  //For Debug
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  g_points[0] << 295, 215;
  g_points[1] << 345, 215;
  g_points[2] << 295, 265;
  g_points[3] << 345, 265;

  pcl::visualization::CloudViewer viewer("OpenNI Viewer");

  // initialization
  char key;
  uint8_t *pdepth;
  uint8_t *pcolor;
<<<<<<< HEAD
  pdepth = new uint8_t[CAMERA_RESOLUTION_X * CAMERA_RESOLUTION_Y * 2];
  pcolor = new uint8_t[CAMERA_RESOLUTION_X * CAMERA_RESOLUTION_Y * 3];
=======
  pdepth = new uint8_t [CAMERA_RESOLUTION_X*CAMERA_RESOLUTION_Y*2];
  pcolor = new uint8_t [CAMERA_RESOLUTION_X*CAMERA_RESOLUTION_Y*3];
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  MyCalibration my_calib;
  my_calib.initialize(viewer, pdepth, pcolor);

<<<<<<< HEAD
  ros::Subscriber sub_depth =
      ros_nh.subscribe("/camera/depth/image_raw", 1, &MyCalibration::getDepthFrameCallback, &my_calib);
  ros::Subscriber sub_color =
      ros_nh.subscribe("/camera/rgb/image_raw", 1, &MyCalibration::getColorFrameCallback, &my_calib);
  ros::Subscriber sub_points =
      ros_nh.subscribe("/camera/depth/points", 1, &MyCalibration::getPointsCallback, &my_calib);
=======
  ros::Subscriber sub_depth = ros_nh.subscribe("/camera/depth/image_raw", 1, &MyCalibration::getDepthFrameCallback, &my_calib);
  ros::Subscriber sub_color = ros_nh.subscribe("/camera/rgb/image_raw", 1, &MyCalibration::getColorFrameCallback, &my_calib);
  ros::Subscriber sub_points = ros_nh.subscribe("/camera/depth/points", 1, &MyCalibration::getPointsCallback, &my_calib);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  ros::Rate loop_late(100);

  KeyboardEventReader keyboard;

<<<<<<< HEAD
  while (ros::ok() && key != KEYCODE_q)  // key == 'q' ?
  {
    ros::spinOnce();
    if (key == KEYCODE_r)  // key == 'r' ?
    {
      my_calib.extractPlanePoints();
      my_calib.viewPoints();
      my_calib.calcurateExtrinsicParameters(convertion_threshold, d_convertion_method, pattern_width);
    }
    if (key == KEYCODE_p)  // key == 'p' ?
    {
      my_calib.startPickingPoints();
    }
    if (key == KEYCODE_d)  // key == 'd' ?
=======
  while (ros::ok() && key != KEYCODE_q) // key == 'q' ?
  {
    ros::spinOnce();
    if (key == KEYCODE_r) // key == 'r' ?
    {
      my_calib.extractPlanePoints();
      my_calib.viewPoints();
      my_calib.calcurateExtrinsicParameters(
          convertion_threshold,
          d_convertion_method,
          pattern_width);
    }
    if (key == KEYCODE_p) // key == 'p' ?
    {
      my_calib.startPickingPoints();
    }
    if (key == KEYCODE_d) // key == 'd' ?
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    {
      while (key != 0 && key != KEYCODE_q)
      {
        ros::spinOnce();
<<<<<<< HEAD
        key = my_calib.pickPointsAutomatically(5, 6) & 0x00ff;
=======
        key = my_calib.pickPointsAutomatically(5,6) & 0x00ff;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
      }
    }
    key = cv::waitKey(10) & 0x00ff;
    char tmp_key;
  }

<<<<<<< HEAD
  delete[] pdepth;
  delete[] pcolor;
=======
  delete [] pdepth;
  delete [] pcolor;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  return 0;
}
