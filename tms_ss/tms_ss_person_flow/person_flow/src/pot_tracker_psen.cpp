//----------------------------------------------------------
// @file   : pot_tracker_double.cpp
// @author : Watanabe Yuuta
// @version: Ver0.1.4 (since 2014.05.02)
// @date   : 2016.11.18
//----------------------------------------------------------

#include <ros/ros.h>
#include <pthread.h>
#include <std_msgs/String.h>
#include <tms_msg_ss/pot_tracking_psen.h>
#include <tms_msg_ss/pot_tracking_psens.h>

pthread_mutex_t mutex_laser  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_target = PTHREAD_MUTEX_INITIALIZER;

#include "opencv/cv.h"
#include <sensor_msgs/LaserScan.h>
#include "tms_ss_pot/define.h"
#include "tms_ss_pot/Target.h"
#include "tms_ss_pot/Laser.h"
#include "tms_ss_pot/Particle_filter.h"
#include "tms_ss_pot/Multiple_particle_filter.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include <iostream>
#include <ctime>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>

std::vector<float> scanData;
CLaser laser;
bool CallbackCalled = false;
Psenparam tmp_param;
std::vector< int > endid;
std::vector< int >::iterator p;
std::vector< Psenparam > psenparam;
std::vector< Psenparam >::iterator v;
////
int right_count = 0;
int left_count  = 0;

///
void *Getcharactor(void *ptr)
{
    int reset_button;
    ros::Rate r(1);
    while (ros::ok())
    {
        std::cin >> reset_button;
        if (reset_button == 0)
        {
            right_count = 0;
            left_count  = 0;
        }
        r.sleep();
    }
}

void *Visualization( void *ptr )
{
    int   ID;
    float X;
    float Y;
    ros::Rate r(10);
    ros::Publisher *pub = (ros::Publisher *)ptr;

    while (ros::ok())
    {
        tms_msg_ss::pot_tracking_psen psen;
        tms_msg_ss::pot_tracking_psens psens;
        pthread_mutex_lock(&mutex_target);

        for (v = psenparam.begin(); v != psenparam.end(); ++v)
        {
            v -> flag = 0;
        }

        for (int i = 0; i < MAX_TRACKING_OBJECT; i++)
        {
            if (laser.m_pTarget[i] != NULL)
            {
                if (laser.m_pTarget[i]->cnt < 50)
                {
                    //cout << laser.m_pTarget[i]->cnt << endl;
                    continue;
                }

                ID =  (laser.m_pTarget[i]->id);
                X  = -(laser.m_pTarget[i]->py);
                Y  =  (laser.m_pTarget[i]->px);

                if (psenparam.size() > 0)
                {
                    for (v = psenparam.begin(); v != psenparam.end(); ++v)
                    {
                        if ( v -> id == ID)
                        {
                            v -> flag = 1;
                            if (X < 0)
                            {
                                if (v -> x >= 0)
                                {
                                    right_count++;
                                }
                            }
                            else if (X >= 0)
                            {
                                if (v -> x < 0)
                                {
                                    left_count++;
                                }
                            }
                            v -> x = X;
                            v -> y = Y;
                            break;
                        }
                        else if (v == psenparam.end() - 1 )
                        {
                            tmp_param.id = ID;
                            tmp_param.flag = 1;
                            tmp_param.x = X;
                            tmp_param.y = Y;
                            psenparam.insert(psenparam.begin(), tmp_param);
                            break;
                        }
                    }
                }
                else
                {
                    tmp_param.id = ID;
                    tmp_param.flag = 1;
                    tmp_param.x = X;
                    tmp_param.y = Y;
                    //psenparam.insert(psenparam.begin(), tmp_param);
                    psenparam.push_back(tmp_param);
                }
            }
        }
        if (psenparam.size() > 0 )
        {
            //std::cout << "<<id  " ;
            for (v = psenparam.begin(); v != psenparam.end(); ++v)
            {
                psen.id = v -> id;
                psen.flag = v -> flag;
                psen.x = v -> x;
                psen.y = v -> y;
                psen.righter = right_count;
                psen.lefter  = left_count;
                psens.pot_tracking_psen.push_back(psen);
                //std::cout << v -> id << "." << v->flag << " ";
            }
            //std::cout << " >>" << std::endl;
            psenparam.resize(psenparam.size());
L:
            int n_flag = 0;
            for (v = psenparam.begin(); v != psenparam.end(); ++v)
            {
                if (v -> flag == 0)
                {
                    endid.push_back(v -> id);
                    //std::cout << "v " << v -> id << " erase start " << std::endl;
                    psenparam.erase (v);
                    //std::cout << "erase complete" << std::endl;
                    n_flag = 1;
                    break;
                }
            }
            if (n_flag == 1)
            {
                goto L;
            }
        }
        pub->publish(psens);
        pthread_mutex_unlock(&mutex_target);
        r.sleep();
    }
}



void *Processing( void *ptr )
{
    CMultipleParticleFilter m_PF;
    ros::Rate r(30);
    laser.Init();

    /**********************************/
    laser.m_bNodeActive[0] = true;
    laser.m_nConnectNum = 1;
    laser.GetLRFParam();
    laser.m_nStep[0] = laser.m_LRFParam[0].step;
    laser.m_StartAngle[0] = -laser.m_LRFParam[0].viewangle / 2.0;
    laser.m_DivAngle[0] = laser.m_LRFParam[0].divangle;
    /**********************************/

    CvMat *m_Rotate = cvCreateMat(2, 2, CV_64F);
    CvMat *m_Translate = cvCreateMat(2, 1, CV_64F);
    CvMat *Temp = cvCreateMat(2, 1, CV_64F);
    int count;
    double theta, range;

    if (laser.m_bNodeActive[0])
        while (!CallbackCalled) r.sleep();

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
                    laser.m_LRFData[n].resize(scanData.size());
                    for (int i = 0; i < scanData.size(); i++) laser.m_LRFData[n][i] = scanData[i];

                    pthread_mutex_unlock(&mutex_laser);

                }
            }
            //      laser.GetBackLRFData();
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
                    laser.m_LRFData[n].resize(scanData.size());
                    for (int i = 0; i < scanData.size(); i++)
                    {
                        laser.m_LRFData[n][i] = scanData[i];
                    }

                    pthread_mutex_unlock(&mutex_laser);

                    laser.GetDiffLRFCluster(n);

                    cvmSet(m_Rotate, 0, 0, cos(deg2rad(laser.m_LRFParam[n].rz)));
                    cvmSet(m_Rotate, 0, 1, -sin(deg2rad(laser.m_LRFParam[n].rz)));
                    cvmSet(m_Rotate, 1, 0, sin(deg2rad(laser.m_LRFParam[n].rz)));
                    cvmSet(m_Rotate, 1, 1, cos(deg2rad(laser.m_LRFParam[n].rz)));
                    cvmSet(m_Translate, 0, 0, laser.m_LRFParam[n].tx);
                    cvmSet(m_Translate, 1, 0, laser.m_LRFParam[n].ty);

                    laser.m_LRFPoints[n].clear();
                    laser.m_LRFPoints[n].resize(laser.m_DiffLRFData[n].size());

                    for ( int i = 0; i < laser.m_DiffLRFData[n].size(); i++)
                    {
                        count = laser.m_DiffLRFData[n][i].n;
                        range = laser.m_DiffLRFData[n][i].range;
                        theta = laser.m_DivAngle[0] * count + laser.m_StartAngle[0];

                        cvmSet(laser.m_LRFPos[n][i], 0, 0, range * cos(deg2rad(theta)));
                        cvmSet(laser.m_LRFPos[n][i], 1, 0, range * sin(deg2rad(theta)));
                        cvmMul(m_Rotate, laser.m_LRFPos[n][i], Temp);    //
                        cvmAdd(m_Translate, Temp, laser.m_LRFPos[n][i]);  //
                        laser.m_LRFPoints[n][i].x = cvmGet(laser.m_LRFPos[n][i], 0, 0) * 1000.0;
                        laser.m_LRFPoints[n][i].y = cvmGet(laser.m_LRFPos[n][i], 1, 0) * 1000.0;
                    }

                    // Number of clusters
                    // std::cout << "Number of clusters " << laser.m_LRFClsData[n].size() << std::endl;

                    laser.m_LRFClsPoints[n].clear();
                    laser.m_LRFClsPoints[n].resize(laser.m_LRFClsData[n].size());
                    for (int i = 0; i < laser.m_LRFClsData[n].size(); i++)
                    {
                        count = laser.m_LRFClsData[n][i].n;
                        range = laser.m_LRFClsData[n][i].range;
                        theta = laser.m_DivAngle[0] * count + laser.m_StartAngle[0];

                        cvmSet(laser.m_LRFClsPos[n][i], 0, 0, range * cos(deg2rad(theta)));
                        cvmSet(laser.m_LRFClsPos[n][i], 1, 0, range * sin(deg2rad(theta)));
                        cvmMul(m_Rotate, laser.m_LRFClsPos[n][i], Temp);    //
                        cvmAdd(m_Translate, Temp, laser.m_LRFClsPos[n][i]);  //
                        laser.m_LRFClsPoints[n][i].x = cvmGet(laser.m_LRFClsPos[n][i], 0, 0) * 1000.0;
                        laser.m_LRFClsPoints[n][i].y = cvmGet(laser.m_LRFClsPos[n][i], 1, 0) * 1000.0;

                        //std::cout << laser.m_LRFClsPoints[n][i].x << " " << laser.m_LRFClsPoints[n][i].y << std::endl;
                    }
                }
            }
        }
        pthread_mutex_lock(&mutex_target);
        m_PF.update(&laser);
        pthread_mutex_unlock(&mutex_target);

        ros::Time begin = ros::Time::now();
        if (m_PF.m_ParticleFilter.size() > 0) std::cout << "Time " << begin << " Number of PFs " << m_PF.m_ParticleFilter.size() << std::endl;

        if (!(iteration % 100)) laser.GetBackLRFDataGaussian();

        r.sleep();
        iteration ++;
    }

    cvReleaseMat(&Temp);
    cvReleaseMat(&m_Rotate);
    cvReleaseMat(&m_Translate);

}

void LaserSensingCallback(const sensor_msgs::LaserScan::ConstPtr &scan)
{
    if (scan->ranges.size() > 0)
    {
        pthread_mutex_lock(&mutex_laser);
        int steps = 683;
        if ( scanData.size() == 0 ) scanData.resize(steps);

        for (int i = 0; i < steps ; i++)
        {
            scanData[i] = scan->ranges[i];
        }
        pthread_mutex_unlock(&mutex_laser);
        CallbackCalled = true;
    }
}

int main( int argc, char **argv )
{
    std::cout << "tracker_start" << std::endl;
    pthread_t thread_p;
    pthread_t thread_v;
    ////
    pthread_t thread_s;
    ros::MultiThreadedSpinner spinner(0);

    ros::init(argc, argv, "pot_tracker_psen1");
    ros::NodeHandle n;
    ros::Publisher  pub = n.advertise<tms_msg_ss::pot_tracking_psens>("tracking_psen1", 10);
    ros::Subscriber sub = n.subscribe("/LaserTracker1", 1000, LaserSensingCallback);
    //////
    if ( pthread_create( &thread_s, NULL, Getcharactor, NULL) )
    {
        printf("error creating thread.");
        abort();
    }
    if ( pthread_create( &thread_v, NULL, Visualization, (void *)&pub) )
    {
        printf("error creating thread.");
        abort();
    }

    if ( pthread_create( &thread_p, NULL, Processing, NULL) )
    {
        printf("error creating thread.");
        abort();
    }
    spinner.spin(); // spin() will not return until the node has been shutdown

    ros::waitForShutdown();

    if ( pthread_join( thread_p, NULL) )
    {
        printf("error joining thread.");
        abort();
    }
    if ( pthread_join( thread_v, NULL) )
    {
        printf("error joining thread.");
        abort();
    }
    //////
    if ( pthread_join( thread_v, NULL) )
    {
        printf("error joining thread.");
        abort();
    }

    scanData.clear();

    return 0;
}

