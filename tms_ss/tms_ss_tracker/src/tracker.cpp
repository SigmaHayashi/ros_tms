//----------------------------------------------------------
// @file   : tracker_double.cpp
// @adder  : Watanabe Yuuta
// @version: Ver0.0.1 (since 2014.05.02)
// @date   : 2014.11.21
//----------------------------------------------------------
#include <ros/ros.h>
#include <pthread.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/MultiEchoLaserScan.h>
#include <tms_msg_ss/tracking_points.h>
#include <tms_msg_ss/tracking_grid.h>
#include <tms_msg_ss/tracking_clusters_data.h>
#include <tms_msg_ss/tracking_cluster.h>

pthread_mutex_t mutex_laser = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_target = PTHREAD_MUTEX_INITIALIZER;

#include "opencv/cv.h"

#include "define.h"
#include "target.h"
#include "laser.h"

#include "particle_filter.h"
#include "multiple_particle_filter.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include <iostream>
#include <ctime>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>

<<<<<<< HEAD
std::vector< float > scanData;
std::vector< float > scanData1;
CLaser laser;
bool CallbackCalled = false;
bool CallbackCalled1 = false;

ros::Publisher pub;
ros::Publisher pub1;
ros::Subscriber sub;
ros::Subscriber sub1;

void *Object_points_show(void *ptr)
{
  int ID;
=======
std::vector<float> scanData;
std::vector<float> scanData1;
CLaser laser;
bool CallbackCalled  = false;
bool CallbackCalled1 = false;

ros::Publisher  pub ;
ros::Publisher  pub1;
ros::Subscriber sub ;
ros::Subscriber sub1;

void *Object_points_show( void *ptr )
{
  int   ID;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  float X;
  float Y;
  ros::Rate r(20);
  ros::Publisher *pub = (ros::Publisher *)ptr;
  int latest_id = 0;

  while (ros::ok())
  {
    tms_msg_ss::tracking_grid grid;
    tms_msg_ss::tracking_points points;

    pthread_mutex_lock(&mutex_target);

    for (int i = 0; i < MAX_TRACKING_OBJECT; i++)
    {
      if (laser.m_pTarget[i] != NULL)
      {
        if (laser.m_pTarget[i]->cnt < 20)
        {
          continue;
        }

<<<<<<< HEAD
        ID = (laser.m_pTarget[i]->id) % 20;
        X = -(laser.m_pTarget[i]->py) + 5200;
        Y = (laser.m_pTarget[i]->px) + 100;
=======
        ID =  (laser.m_pTarget[i]->id) % 20;
        X  = -(laser.m_pTarget[i]->py) + 5200;
        Y  =  (laser.m_pTarget[i]->px) + 100;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

        if (0.0 < X && X < 8000.0 && 0.0 < Y && Y < 4500.0)
        {
          grid.id = ID;
<<<<<<< HEAD
          grid.x = X;
          grid.y = Y;
=======
          grid.x  = X;
          grid.y  = Y;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

          points.tracking_grid.push_back(grid);
        }
      }
    }

    pthread_mutex_unlock(&mutex_target);

    pub->publish(points);
    r.sleep();
  }
  return 0;
}

<<<<<<< HEAD
void *Processing(void *ptr)
{
  CMultipleParticleFilter m_PF;

  std::vector< int > lrf_number;
  std::vector< double > lrf_cls_x;
  std::vector< double > lrf_cls_y;
  std::vector< int > length;
=======

void *Processing( void *ptr )
{
  CMultipleParticleFilter m_PF;

  std::vector<int>    lrf_number;
  std::vector<double> lrf_cls_x;
  std::vector<double> lrf_cls_y;
  std::vector<int>    length;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  tms_msg_ss::tracking_cluster cluster;
  tms_msg_ss::tracking_clusters_data clusters;
  ros::Publisher *pub = (ros::Publisher *)ptr;

  ros::Rate r(30);

  laser.Init();

  laser.m_bNodeActive[0] = true;
  laser.m_bNodeActive[1] = true;
  laser.m_nConnectNum = 2;
  laser.GetLRFParam();
<<<<<<< HEAD
  laser.m_nStep[0] = laser.m_LRFParam[0].step;
  laser.m_nStep[1] = laser.m_LRFParam[1].step;
  laser.m_StartAngle[0] = -laser.m_LRFParam[0].viewangle / 2.0;
  laser.m_StartAngle[1] = -laser.m_LRFParam[1].viewangle / 2.0;
  laser.m_DivAngle[0] = laser.m_LRFParam[0].divangle;
  laser.m_DivAngle[1] = laser.m_LRFParam[1].divangle;

  CvMat *m_Rotate = cvCreateMat(2, 2, CV_64F);
  CvMat *m_Translate = cvCreateMat(2, 1, CV_64F);
  CvMat *Temp = cvCreateMat(2, 1, CV_64F);
=======
  laser.m_nStep[0]      =  laser.m_LRFParam[0].step;
  laser.m_nStep[1]      =  laser.m_LRFParam[1].step;
  laser.m_StartAngle[0] = -laser.m_LRFParam[0].viewangle / 2.0;
  laser.m_StartAngle[1] = -laser.m_LRFParam[1].viewangle / 2.0;
  laser.m_DivAngle[0]   =  laser.m_LRFParam[0].divangle;
  laser.m_DivAngle[1]   =  laser.m_LRFParam[1].divangle;

  CvMat *m_Rotate     = cvCreateMat(2, 2, CV_64F);
  CvMat *m_Translate  = cvCreateMat(2, 1, CV_64F);
  CvMat *Temp         = cvCreateMat(2, 1, CV_64F);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  int count;
  double theta, range;

  if (laser.m_bNodeActive[0])
<<<<<<< HEAD
    while (!CallbackCalled)
      r.sleep();
=======
  while (!CallbackCalled) r.sleep();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  if (laser.m_bResetBackRangeData == true)
  {
    for (int it = 0; it < laser.m_ring; it++)
    {
      for (int n = 0; n < laser.m_cnMaxConnect; n++)
      {
        if (laser.m_bNodeActive[n])
        {
          pthread_mutex_lock(&mutex_laser);
          laser.m_LRFData[n].clear();

          if (n == 0)
          {
            laser.m_LRFData[n].resize(scanData.size());

            for (int i = 0; i < scanData.size(); i++)
            {
              laser.m_LRFData[n][i] = scanData[i];
            }
          }
          else if (n == 1)
          {
            laser.m_LRFData[n].resize(scanData1.size());

            for (int i = 0; i < scanData1.size(); i++)
            {
              laser.m_LRFData[n][i] = scanData1[i];
            }
          }
          pthread_mutex_unlock(&mutex_laser);
        }
      }
      laser.GetBackLRFDataGaussian();
      r.sleep();
    }
    laser.m_bResetBackRangeData = false;
    std::cout << "Back range data is stored" << std::endl;
  }

  int iteration = 0;
  while (ros::ok())
  {
    if (laser.m_bResetBackRangeData == false)
    {
      for (int n = 0; n < laser.m_cnMaxConnect; n++)
      {
        if (laser.m_bNodeActive[n])
        {
          pthread_mutex_lock(&mutex_laser);
          laser.m_LRFData[n].clear();

          if (n == 0)
          {
            laser.m_LRFData[n].resize(scanData.size());

            for (int i = 0; i < scanData.size(); i++)
            {
              laser.m_LRFData[n][i] = scanData[i];
            }
          }
          else if (n == 1)
          {
            laser.m_LRFData[n].resize(scanData1.size());
            for (int i = 0; i < scanData1.size(); i++)
            {
              laser.m_LRFData[n][i] = scanData1[i];
            }
          }
          pthread_mutex_unlock(&mutex_laser);

          laser.GetDiffLRFCluster(n);

<<<<<<< HEAD
          cvmSet(m_Rotate, 0, 0, cos(deg2rad(laser.m_LRFParam[n].rz)));
          cvmSet(m_Rotate, 0, 1, -sin(deg2rad(laser.m_LRFParam[n].rz)));
          cvmSet(m_Rotate, 1, 0, sin(deg2rad(laser.m_LRFParam[n].rz)));
          cvmSet(m_Rotate, 1, 1, cos(deg2rad(laser.m_LRFParam[n].rz)));
=======
          cvmSet(m_Rotate, 0, 0,  cos(deg2rad(laser.m_LRFParam[n].rz)));
          cvmSet(m_Rotate, 0, 1, -sin(deg2rad(laser.m_LRFParam[n].rz)));
          cvmSet(m_Rotate, 1, 0,  sin(deg2rad(laser.m_LRFParam[n].rz)));
          cvmSet(m_Rotate, 1, 1,  cos(deg2rad(laser.m_LRFParam[n].rz)));
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
          cvmSet(m_Translate, 0, 0, laser.m_LRFParam[n].tx);
          cvmSet(m_Translate, 1, 0, laser.m_LRFParam[n].ty);

          laser.m_LRFClsPoints[n].clear();
          laser.m_LRFClsPoints[n].resize(laser.m_LRFClsData[n].size());
          for (int i = 0; i < laser.m_LRFClsData[n].size(); i++)
          {
            count = laser.m_LRFClsData[n][i].n;
            range = laser.m_LRFClsData[n][i].range;
            theta = laser.m_DivAngle[0] * count + laser.m_StartAngle[0];
            theta = laser.m_DivAngle[1] * count + laser.m_StartAngle[1];

            cvmSet(laser.m_LRFClsPos[n][i], 0, 0, range * cos(deg2rad(theta)));
            cvmSet(laser.m_LRFClsPos[n][i], 1, 0, range * sin(deg2rad(theta)));
<<<<<<< HEAD
            cvMatMul(m_Rotate, laser.m_LRFClsPos[n][i], Temp);
            cvAdd(m_Translate, Temp, laser.m_LRFClsPos[n][i]);
=======
            cvmMul(m_Rotate, laser.m_LRFClsPos[n][i], Temp);
            cvmAdd(m_Translate, Temp, laser.m_LRFClsPos[n][i]);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

            laser.m_LRFClsPoints[n][i].x = cvmGet(laser.m_LRFClsPos[n][i], 0, 0) * 1000.0;
            laser.m_LRFClsPoints[n][i].y = cvmGet(laser.m_LRFClsPos[n][i], 1, 0) * 1000.0;

            lrf_number.push_back(laser.m_LRFClsData[n][i].n);
            lrf_cls_x.push_back(laser.m_LRFClsPoints[n][i].x);
            lrf_cls_y.push_back(laser.m_LRFClsPoints[n][i].y);
            length.push_back(laser.m_LRFClsData[n][i].length);
          }
        }

        if (n == 1)
        {
          laser.m_LRFClsPoints[0].clear();
          laser.m_LRFClsPoints[0].resize(lrf_cls_x.size());

          for (int i = 0; i < lrf_cls_x.size(); i++)
          {
            laser.m_LRFClsPoints[0][i].x = lrf_cls_x[i];
            laser.m_LRFClsPoints[0][i].y = lrf_cls_y[i];
<<<<<<< HEAD
            // std::cout << "x " << lrf_cls_x[i] << "y " << lrf_cls_y[i] << std::endl;
            cluster.point_number = lrf_number[i];
            cluster.x = -(lrf_cls_y[i]) + 5200;
            cluster.y = lrf_cls_x[i] + 100;
            cluster.cluster_points = length[i];

            if (0.0 < cluster.x && cluster.x < 8000.0 && 0.0 < cluster.y && cluster.y < 4500.0)
            {
              clusters.tracking_clster.push_back(cluster);
=======
            //std::cout << "x " << lrf_cls_x[i] << "y " << lrf_cls_y[i] << std::endl;
            cluster.point_number = lrf_number[i];
            cluster.x = -(lrf_cls_y[i]) + 5200;
            cluster.y =   lrf_cls_x[i]  + 100;
            cluster.cluster_points = length[i];

            if(0.0 < cluster.x && cluster.x < 8000.0 && 0.0 < cluster.y && cluster.y < 4500.0)
            {
            clusters.tracking_clster.push_back(cluster);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
            }
          }
          pthread_mutex_lock(&mutex_target);
          pub->publish(clusters);
          pthread_mutex_unlock(&mutex_target);

          lrf_number.clear();
          lrf_cls_x.clear();
          lrf_cls_y.clear();
          length.clear();
        }
      }
    }

    pthread_mutex_lock(&mutex_target);
    m_PF.update(&laser);
    pthread_mutex_unlock(&mutex_target);

    ros::Time begin = ros::Time::now();
    if (m_PF.m_ParticleFilter.size() > 0)
    {
      std::cout << "Time " << begin << " Number of PFs " << m_PF.m_ParticleFilter.size() << std::endl;
    }

    if (!(iteration % 100000))
    {
      laser.GetBackLRFDataGaussian();
    }
    r.sleep();
<<<<<<< HEAD
    iteration++;
=======
    iteration ++;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  }

  cvReleaseMat(&Temp);
  cvReleaseMat(&m_Rotate);
  cvReleaseMat(&m_Translate);
}

void LaserSensingCallback(const sensor_msgs::LaserScan::ConstPtr &scan)
{
  pthread_mutex_lock(&mutex_laser);
  int num = floor((scan->angle_max - scan->angle_min) / scan->angle_increment);

<<<<<<< HEAD
  if (scanData.size() == 0)
=======
  if ( scanData.size() == 0 )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    scanData.resize(num);

  scanData = scan->ranges;

  pthread_mutex_unlock(&mutex_laser);
<<<<<<< HEAD
  CallbackCalled = true;
=======
  CallbackCalled  = true;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

void LaserSensingCallback1(const sensor_msgs::LaserScan::ConstPtr &scan)
{
  pthread_mutex_lock(&mutex_laser);
  int num = floor((scan->angle_max - scan->angle_min) / scan->angle_increment);

<<<<<<< HEAD
  if (scanData1.size() == 0)
=======
  if ( scanData1.size() == 0 )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    scanData1.resize(num);

  scanData1 = scan->ranges;

  pthread_mutex_unlock(&mutex_laser);
  CallbackCalled1 = true;
}

<<<<<<< HEAD
int main(int argc, char **argv)
=======
int main( int argc, char **argv )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
{
  pthread_t thread_p;
  pthread_t thread_v;
  ros::MultiThreadedSpinner spinner(4);

  ros::init(argc, argv, "moving_object_tracker");
  ros::NodeHandle n;
<<<<<<< HEAD
  ros::Publisher pub = n.advertise< tms_msg_ss::tracking_points >("tracking_points", 10);
  ros::Publisher pub1 = n.advertise< tms_msg_ss::tracking_clusters_data >("clusters_data", 10);
  ros::Subscriber sub = n.subscribe("/urg2/most_intense", 10, LaserSensingCallback);
  ros::Subscriber sub1 = n.subscribe("/urg1/most_intense", 10, LaserSensingCallback1);

  if (pthread_create(&thread_v, NULL, Object_points_show, (void *)&pub))
=======
  ros::Publisher  pub  = n.advertise<tms_msg_ss::tracking_points>("tracking_points", 10);
  ros::Publisher  pub1 = n.advertise<tms_msg_ss::tracking_clusters_data>("clusters_data", 10);
  ros::Subscriber sub  = n.subscribe("/urg2/most_intense" , 10, LaserSensingCallback);
  ros::Subscriber sub1 = n.subscribe("/urg1/most_intense" , 10, LaserSensingCallback1);

  if ( pthread_create( &thread_v, NULL, Object_points_show, (void *)&pub) )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    printf("error creating thread.");
    abort();
  }

<<<<<<< HEAD
  if (pthread_create(&thread_p, NULL, Processing, (void *)&pub1))
=======
  if ( pthread_create( &thread_p, NULL, Processing, (void *)&pub1) )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    printf("error creating thread.");
    abort();
  }

  spinner.spin();

  ros::waitForShutdown();

<<<<<<< HEAD
  if (pthread_join(thread_p, NULL))
=======
  if ( pthread_join( thread_p, NULL) )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    printf("error joining thread.");
    abort();
  }

<<<<<<< HEAD
  if (pthread_join(thread_v, NULL))
=======
  if ( pthread_join( thread_v, NULL) )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    printf("error joining thread.");
    abort();
  }

  scanData.clear();

  return 0;
}
