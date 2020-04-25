<<<<<<< HEAD
=======
// ParticleFilter.cpp :
//
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#ifdef WIN32
#pragma warning(disable : 4996)
#endif

#include <math.h>
//#include "opencv2/opencv.hpp"
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "define.h"
#include "particle_filter.h"

CPF::CPF()
{
<<<<<<< HEAD
  m_sigma = Config::is()->m_sigma;
  Dimension = 4;
  Num_of_particles = Config::is()->n_of_particles;
  Area[0] = Config::is()->target_area[0];
  Area[1] = Config::is()->target_area[1];
  Area[2] = Config::is()->target_area[2];
  Area[3] = Config::is()->target_area[3];
  MaxVel = Config::is()->max_vel;
  state[0] = state[1] = state[2] = state[3] = 0;
  m_ID = -1;
  particle_filter = NULL;
  m_cnt = 0;
  Noise[0] = Config::is()->pos_noise;
  Noise[1] = Config::is()->vel_noise;
  m_lostcnt = 0;
=======
	m_sigma = Config::is()->m_sigma;
	Dimension = 4;
	Num_of_particles = Config::is()->n_of_particles;
	Area[0] = Config::is()->target_area[0]*1000.0;   //
	Area[1] = Config::is()->target_area[1]*1000.0;
	Area[2] =  Config::is()->target_area[2]*1000.0;
	Area[3] =  Config::is()->target_area[3]*1000.0;
	MaxVel = Config::is()->max_vel;
	state[0] = state[1] = state[2] = state[3] = 0; 
	m_ID = -1;
	particle_filter = NULL;
	m_cnt = 0;
	Noise[0] = Config::is()->pos_noise * 1000.0;    //
	Noise[1] = Config::is()->vel_noise * 1000.0;    //
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

CPF::~CPF()
{
}

void CPF::initialize(int area[4])
{
<<<<<<< HEAD
  CvMat* lower_bound;
  CvMat* upper_bound;

  if (particle_filter)
  {
    cvReleaseConDensation(&particle_filter);
  }
  particle_filter = cvCreateConDensation(Dimension, 2, Num_of_particles);

  lower_bound = cvCreateMat(4, 1, CV_32FC1);
  upper_bound = cvCreateMat(4, 1, CV_32FC1);

  cvmSet(lower_bound, 0, 0, area[0]);
  cvmSet(lower_bound, 1, 0, area[1]);
  cvmSet(lower_bound, 2, 0, -MaxVel);
  cvmSet(lower_bound, 3, 0, -MaxVel);
  cvmSet(upper_bound, 0, 0, area[2]);
  cvmSet(upper_bound, 1, 0, area[3]);
  cvmSet(upper_bound, 2, 0, MaxVel);
  cvmSet(upper_bound, 3, 0, MaxVel);

  cvConDensInitSampleSet(particle_filter, lower_bound, upper_bound);

  cvReleaseMat(&lower_bound);
  cvReleaseMat(&upper_bound);

  const double matrix_elements[] = {
      1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0,
  };

  size_t n = sizeof(matrix_elements) / sizeof(matrix_elements[0]);
  for (size_t i = 0; i < n; ++i)
  {
    particle_filter->DynamMatr[i] = matrix_elements[i];
  }

#if 1
  cvRandInit(&(particle_filter->RandS[0]), 0, Noise[0], (int)cvGetTickCount(), CV_RAND_NORMAL);
  cvRandInit(&(particle_filter->RandS[1]), 0, Noise[0], (int)cvGetTickCount(), CV_RAND_NORMAL);
  cvRandInit(&(particle_filter->RandS[2]), 0, Noise[1], (int)cvGetTickCount(), CV_RAND_NORMAL);
  cvRandInit(&(particle_filter->RandS[3]), 0, Noise[1], (int)cvGetTickCount(), CV_RAND_NORMAL);
#else
#endif
  m_cnt = 0;
=======
	CvMat* lower_bound;
	CvMat* upper_bound;

	if (particle_filter) {
		cvReleaseConDensation(&particle_filter);
	}
	particle_filter = cvCreateConDensation(Dimension, 2, Num_of_particles);

	lower_bound = cvCreateMat(4, 1, CV_32FC1);
	upper_bound = cvCreateMat(4, 1, CV_32FC1);

	cvmSet(lower_bound, 0, 0, area[0]);
	cvmSet(lower_bound, 1, 0, area[1]);
	cvmSet(lower_bound, 2, 0, -MaxVel);
	cvmSet(lower_bound, 3, 0, -MaxVel);
	cvmSet(upper_bound, 0, 0, area[2]);
	cvmSet(upper_bound, 1, 0, area[3]);
	cvmSet(upper_bound, 2, 0, MaxVel);
	cvmSet(upper_bound, 3, 0, MaxVel);

	cvConDensInitSampleSet(particle_filter, lower_bound, upper_bound);

	cvReleaseMat(&lower_bound);
	cvReleaseMat(&upper_bound);

	const double matrix_elements[] = {
		1.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 0.0, 1.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0,
	};

	size_t n = sizeof(matrix_elements) / sizeof(matrix_elements[0]);
	for (size_t i = 0; i < n; ++i) {
		particle_filter->DynamMatr[i] = matrix_elements[i];
	}

#if 1
	cvRandInit(&(particle_filter->RandS[0]), 0, Noise[0], (int) cvGetTickCount(), CV_RAND_NORMAL);
	cvRandInit(&(particle_filter->RandS[1]), 0, Noise[0], (int) cvGetTickCount(), CV_RAND_NORMAL);
	cvRandInit(&(particle_filter->RandS[2]), 0, Noise[1], (int) cvGetTickCount(), CV_RAND_NORMAL);
	cvRandInit(&(particle_filter->RandS[3]), 0, Noise[1], (int) cvGetTickCount(), CV_RAND_NORMAL);
#else
#endif	
	m_cnt = 0;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

void CPF::clear()
{
<<<<<<< HEAD
  if (particle_filter)
  {
    cvReleaseConDensation(&particle_filter);
  }
=======
	if (particle_filter) {
		cvReleaseConDensation(&particle_filter);
	}
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

void CPF::SetTarget(double t[2])
{
<<<<<<< HEAD
  target[0] = t[0];
  target[1] = t[1];
=======
	target[0] = t[0];
	target[1] = t[1];
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

void CPF::GetTarget(double t[2])
{
<<<<<<< HEAD
  t[0] = target[0];
  t[1] = target[1];
=======
	t[0] = target[0];
	t[1] = target[1];
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

void CPF::update()
{
<<<<<<< HEAD
  for (int i = 0; i < Num_of_particles; ++i)
  {
    double p[2];
    p[0] = particle_filter->flSamples[i][0];
    p[1] = particle_filter->flSamples[i][1];
    if ((p[0] < Area[0]) || (p[0] >= Area[2]) || (p[1] < Area[1]) || (p[1] >= Area[3]))
    {
      particle_filter->flConfidence[i] = 0.0;
    }
    else
    {
      // 尤度の計算
      particle_filter->flConfidence[i] = likelihood(p);
    }
  }

  cvConDensUpdateByTime(particle_filter);

  state[0] = particle_filter->State[0];
  state[1] = particle_filter->State[1];
  state[2] = particle_filter->State[2];
  state[3] = particle_filter->State[3];

  m_cnt++;

  m_lostcnt = 0;
=======
	for (int i = 0; i < Num_of_particles; ++i) {
		double p[2];
		p[0] = particle_filter->flSamples[i][0];
		p[1] = particle_filter->flSamples[i][1];
		if ((p[0] < Area[0]) || (p[0] >= Area[2]) ||
			(p[1] < Area[1]) || (p[1] >= Area[3])) {
			particle_filter->flConfidence[i] = 0.0;
		}
		else {
			// �ޓx�̌v�Z
			particle_filter->flConfidence[i] = likelihood(p);
		}
	}

	cvConDensUpdateByTime(particle_filter);

	state[0] = particle_filter->State[0];
	state[1] = particle_filter->State[1];
	state[2] = particle_filter->State[2];
	state[3] = particle_filter->State[3];

	m_cnt++;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

double CPF::likelihood(double p[2])
{
<<<<<<< HEAD
  double dist = sqrt(pow(p[0] - target[0], 2) + pow(p[1] - target[1], 2));

  return 1.0 / (sqrt(2.0 * M_PI) * m_sigma) * exp(-pow(dist, 2.0) / (2.0 * pow(m_sigma, 2.0)));
=======
	double dist = sqrt(pow(p[0] - target[0], 2) + pow(p[1] - target[1], 2));

	return 1.0 / (sqrt(2.0 * M_PI) * m_sigma)
		* exp(-pow(dist, 2.0) / (2.0 * pow(m_sigma, 2.0)));
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

void CPF::SetID(int ID)
{
<<<<<<< HEAD
  m_ID = ID;
=======
	m_ID = ID;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

int CPF::GetID()
{
<<<<<<< HEAD
  return m_ID;
=======
	return m_ID;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

int CPF::GetCnt()
{
<<<<<<< HEAD
  return m_cnt;
}

int CPF::GetLostCnt()
{
  return m_lostcnt;
}

int CPF::IncLostCnt()
{
  m_lostcnt ++;
  return m_lostcnt;
=======
	return m_cnt;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}
