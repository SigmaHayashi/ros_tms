#ifndef _MYCALIBRATION_H_
#define _MYCALIBRATION_H_

#define CAMERA_RESOLUTION_X 640
#define CAMERA_RESOLUTION_Y 480

#define PATTERN_WIDTH 45.0
#define CORRESPOND_POINTS 30

<<<<<<< HEAD
void mouseCallback(int event, int x, int y, int flag, void *);
=======
void mouseCallback(int event, int x,int y, int flag, void*);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

class MyCalibration
{
public:
  cv::Mat image;

<<<<<<< HEAD
  int initialize(pcl::visualization::CloudViewer &viewer, uint8_t *depth_frame_region, uint8_t *color_frame_region);
  int extractPlanePoints();
  int viewPoints();
  int calcurateExtrinsicParameters(double convertion_th = 0.01, int convertion_method = 2,
                                   float pattern_width = PATTERN_WIDTH);
  int startPickingPoints();
  int pickPointsAutomatically(int pattern_rows, int pattern_cols);
  void getDepthFrameCallback(const sensor_msgs::Image::ConstPtr &frame);
  void getColorFrameCallback(const sensor_msgs::Image::ConstPtr &frame);
  void getPointsCallback(const sensor_msgs::PointCloud2::ConstPtr &points);
=======
  int initialize(
      pcl::visualization::CloudViewer& viewer,
      uint8_t *depth_frame_region,
      uint8_t *color_frame_region);
  int extractPlanePoints();
  int viewPoints();
  int calcurateExtrinsicParameters(
      double convertion_th = 0.01,
      int convertion_method = 2,
      float pattern_width = PATTERN_WIDTH);
  int startPickingPoints();
  int pickPointsAutomatically(int pattern_rows, int pattern_cols);
  void getDepthFrameCallback(const sensor_msgs::Image::ConstPtr& frame);
  void getColorFrameCallback(const sensor_msgs::Image::ConstPtr& frame);
  void getPointsCallback(const sensor_msgs::PointCloud2::ConstPtr& points);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

private:
  Eigen::Matrix3f correct_mirroring;
  uint8_t *depth_frame;
  uint8_t *color_frame;
  sensor_msgs::PointCloud2::ConstPtr points;
  Eigen::Vector3f world_points[CORRESPOND_POINTS];
  Eigen::Vector3f picked_points[CORRESPOND_POINTS];

<<<<<<< HEAD
  std::vector< Eigen::Vector3f * > points_on_plane;
  std::vector< Eigen::Vector3f * > other_points;
  std::vector< Eigen::Vector3f * > picked_points_around;

  boost::shared_ptr< pcl::PointCloud< pcl::PointXYZRGB > > cloud{new pcl::PointCloud< pcl::PointXYZRGB >()};
=======
  std::vector<Eigen::Vector3f*> points_on_plane;
  std::vector<Eigen::Vector3f*> other_points;
  std::vector<Eigen::Vector3f*> picked_points_around;

  boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB> >
    cloud{new pcl::PointCloud<pcl::PointXYZRGB>()};
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  pcl::visualization::CloudViewer *viewer;
};

#endif
