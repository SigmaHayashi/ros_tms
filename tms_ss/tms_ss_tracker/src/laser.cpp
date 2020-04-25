#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "opencv/cv.h"
#include "define.h"
#include "target.h"
#include "laser.h"

CLaser::CLaser()
{
  int n, i, j;

  m_diff_dist = MIN_DIFF_DIST;
<<<<<<< HEAD
  m_obj_prob = MIN_OBJ_PROB;
  m_ring = N_RING;
  m_n_ring = 0;
=======
  m_obj_prob  = MIN_OBJ_PROB;
  m_ring      = N_RING;
  m_n_ring    = 0;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  m_LRFData.resize(m_cnMaxConnect);
  m_BackLRFData.resize(m_cnMaxConnect);
  m_DiffLRFData.resize(m_cnMaxConnect);
  m_LRFPoints.resize(m_cnMaxConnect);
  m_LRFClsData.resize(m_cnMaxConnect);
  m_LRFClsPoints.resize(m_cnMaxConnect);
  m_BackLRFDataRing.resize(m_cnMaxConnect);
  m_BackLRFDataAve.resize(m_cnMaxConnect);
  m_BackLRFDataVar.resize(m_cnMaxConnect);

<<<<<<< HEAD
  for (n = 0; n < m_cnMaxConnect; n++)
=======
  for (n=0; n<m_cnMaxConnect; n++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    m_LRFData[n].reserve(m_cnMaxDataSizeLRF);
    m_BackLRFData[n].reserve(m_cnMaxDataSizeLRF);
    m_DiffLRFData[n].reserve(m_cnMaxDataSizeLRF);
    m_LRFPoints[n].reserve(m_cnMaxDataSizeLRF);
    m_LRFClsData[n].reserve(m_cnMaxDataSizeLRF);
    m_LRFClsPoints[n].reserve(m_cnMaxDataSizeLRF);

<<<<<<< HEAD
    for (i = 0; i < m_cnMaxDataSizeLRF; i++)
    {
      m_LRFPos[n][i] = cvCreateMat(2, 1, CV_64F);
      m_LRFClsPos[n][i] = cvCreateMat(2, 1, CV_64F);
    }

    std::vector< double > zero(m_cnMaxDataSizeLRF, 0);
    m_BackLRFDataRing[n].resize(m_ring);

    for (i = 0; i < m_ring; i++)
=======
      for (i=0; i<m_cnMaxDataSizeLRF; i++)
      {
        m_LRFPos[n][i]    = cvCreateMat(2, 1, CV_64F);
        m_LRFClsPos[n][i] = cvCreateMat(2, 1, CV_64F);
      }

    std::vector<double> zero(m_cnMaxDataSizeLRF, 0);
    m_BackLRFDataRing[n].resize(m_ring);

    for (i=0; i<m_ring; i++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    {
      m_BackLRFDataRing[n][i] = zero;
    }

    m_BackLRFDataAve[n] = zero;
    m_BackLRFDataVar[n] = zero;
  }

<<<<<<< HEAD
  for (i = 0; i < m_cnMaxParticleNum; i++)
=======
  for (i=0; i<m_cnMaxParticleNum; i++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    m_Particle[i] = cvCreateMat(2, 1, CV_64F);
  }

<<<<<<< HEAD
  for (i = 0; i < m_cnMaxTrackingObject; i++)
=======
  for (i=0; i<m_cnMaxTrackingObject; i++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    m_pTarget[i] = NULL;
    m_Target_cnt[i] = 0;
  }

  m_TargetNum = 0;

<<<<<<< HEAD
  for (i = 0; i < sizeof(m_Grid) / sizeof(double); i++)
=======
  for (i=0; i<sizeof(m_Grid)/sizeof(double); i++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    m_Grid[i] = 0.0;
  }
}

CLaser::~CLaser()
{
  int n, i, j;

<<<<<<< HEAD
  for (n = 0; n < m_cnMaxConnect; n++)
  {
    for (i = 0; i < m_cnMaxDataSizeLRF; i++)
=======
  for(n=0;n<m_cnMaxConnect;n++)
  {
    for(i=0;i<m_cnMaxDataSizeLRF;i++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    {
      cvReleaseMat(&m_LRFPos[n][i]);
      cvReleaseMat(&m_LRFClsPos[n][i]);
    }
  }

<<<<<<< HEAD
  for (i = 0; i < m_cnMaxParticleNum; i++)
=======
  for(i=0;i<m_cnMaxParticleNum;i++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    cvReleaseMat(&m_Particle[i]);
  }

<<<<<<< HEAD
  for (i = 0; i < m_cnMaxTrackingObject; i++)
  {
    if (m_pTarget[i] != NULL)
=======
  for(i=0;i<m_cnMaxTrackingObject;i++)
  {
    if(m_pTarget[i] != NULL)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
      delete m_pTarget[i];
  }
}

<<<<<<< HEAD
bool CLaser::Init()  // OnNewDocument()
=======
bool CLaser::Init()	//OnNewDocument()
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
{
  int n, i, j;
  m_nConnectNum = 0;

<<<<<<< HEAD
  for (n = 0; n < m_cnMaxConnect; n++)
=======
  for(n=0;n<m_cnMaxConnect;n++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    m_bNodeActive[n] = false;
  }

<<<<<<< HEAD
  for (n = 0; n < m_cnMaxConnect; n++)
=======
  for(n=0;n<m_cnMaxConnect;n++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    m_nStep[n] = 0;
  }

  m_nParticleNum = m_cnMaxParticleNum;

<<<<<<< HEAD
  for (i = 0; i < m_cnMaxParticleNum; i++)
=======
  for(i=0;i<m_cnMaxParticleNum;i++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    m_ParticleLabel[i] = 0;
  }

  m_bResetBackRangeData = true;

  return 0;
}

int CLaser::GetLRFParam()
{
  int n;

<<<<<<< HEAD
  for (n = 0; n < m_cnMaxConnect; n++)
=======
  for(n=0;n<m_cnMaxConnect;n++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    LRFParam param;

    if (m_bNodeActive[n])
    {
      switch (n)
      {
        case 0:
        default:
          param.tx = 0.0;
          param.ty = 0.0;
          param.tz = 0.0;
          param.rx = 0.0;
          param.ry = 0.0;
          param.rz = 0.0;
          param.step = 1080;
          param.viewangle = 270.0;
          param.divangle = param.viewangle / (double)param.step;
          break;
        case 1:
          param.tx = 0.0;
          param.ty = 2.7;
          param.tz = 0.0;
          param.rx = 0.0;
          param.ry = 0.0;
          param.rz = 0.0;
          param.step = 1080;
          param.viewangle = 270.0;
          param.divangle = param.viewangle / (double)param.step;
          break;
        case 2:
          param.tx = 0.0;
          param.ty = 0.0;
          param.tz = 0.0;
          param.rx = 0.0;
          param.ry = 0.0;
          param.rz = 0.0;
          param.step = 1080;
          param.viewangle = 270.0;
          param.divangle = param.viewangle / (double)param.step;
          break;
        case 3:
          param.tx = 0.0;
          param.ty = 0.0;
          param.tz = 0.0;
          param.rx = 0.0;
          param.ry = 0.0;
          param.rz = 0.0;
          param.step = 1080;
          param.viewangle = 270.0;
          param.divangle = param.viewangle / (double)param.step;
          break;
      }
      CopyMemory(&m_LRFParam[n], &param, sizeof(LRFParam));
    }
    else
    {
      ZeroMemory(&m_LRFParam[n], sizeof(LRFParam));
    }
  }

  return 0;
}

int CLaser::GetBackLRFData()
{
  int backcnt = 100;

<<<<<<< HEAD
  for (int n = 0; n < m_cnMaxConnect; n++)
  {
    if (m_bNodeActive[n])
=======
  for(int n=0; n<m_cnMaxConnect; n++)
  {
    if(m_bNodeActive[n])
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    {
      m_BackLRFData[n] = m_LRFData[n];
    }
  }
  return 0;
}

int CLaser::GetBackLRFDataGaussian()
{
  static int count = 0;

<<<<<<< HEAD
  for (int n = 0; n < m_cnMaxConnect; n++)
=======
  for (int n = 0; n<m_cnMaxConnect; n++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    if (m_bNodeActive[n])
    {
      if (count < m_ring)
      {
        for (int i = 0; i < m_LRFData[n].size(); i++)
        {
          m_BackLRFDataAve[n][i] += m_LRFData[n][i];
          m_BackLRFDataVar[n][i] += (m_LRFData[n][i] * m_LRFData[n][i]);

<<<<<<< HEAD
          if (count == m_ring - 1)
=======
          if (count == m_ring-1)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
          {
            m_BackLRFDataAve[n][i] /= (double)m_ring;
            m_BackLRFDataVar[n][i] /= (double)m_ring;
            m_BackLRFDataVar[n][i] -= (m_BackLRFDataAve[n][i] * m_BackLRFDataAve[n][i]);
          }
        }
      }
      else
      {
        for (int i = 0; i < m_LRFData[n].size(); i++)
        {
          m_BackLRFDataVar[n][i] += m_BackLRFDataAve[n][i] * m_BackLRFDataAve[n][i];
          m_BackLRFDataAve[n][i] += (-m_BackLRFDataRing[n][m_n_ring][i] + m_LRFData[n][i]) / (double)m_ring;
<<<<<<< HEAD
          m_BackLRFDataVar[n][i] += (-m_BackLRFDataRing[n][m_n_ring][i] * m_BackLRFDataRing[n][m_n_ring][i] +
                                     m_LRFData[n][i] * m_LRFData[n][i]) /
                                    (double)m_ring;
=======
          m_BackLRFDataVar[n][i] += (-m_BackLRFDataRing[n][m_n_ring][i] * m_BackLRFDataRing[n][m_n_ring][i] + m_LRFData[n][i] * m_LRFData[n][i]) / (double)m_ring;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
          m_BackLRFDataVar[n][i] -= m_BackLRFDataAve[n][i] * m_BackLRFDataAve[n][i];
        }
      }
      m_BackLRFDataRing[n][m_n_ring] = m_LRFData[n];
    }
  }

<<<<<<< HEAD
  if (++count > m_ring)
=======
  if(++count>m_ring)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    count = m_ring;

  m_n_ring = (++m_n_ring) % m_ring;

  return 0;
}

int CLaser::IsFrontFData(double currentdata, double backdata, double min_dist)
{
  if (fabs(currentdata - backdata) < min_dist)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

<<<<<<< HEAD
int CLaser::IsFrontFData(double currentdata, double backdata_ave, double backdata_var, double min_prob)
{
  if (currentdata > MAX_LRF_RANGE)
=======

int CLaser::IsFrontFData(double currentdata, double backdata_ave, double backdata_var, double min_prob)
{
  if(currentdata > MAX_LRF_RANGE)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    return 0;

  double diff = currentdata - backdata_ave;

  if (backdata_var != 0.0)
  {
<<<<<<< HEAD
    double prob = exp(-diff * diff / 2.0 / backdata_var) / sqrt(2.0 * M_PI * backdata_var);
=======
    double prob = exp(- diff * diff / 2.0 / backdata_var) / sqrt(2.0 * M_PI * backdata_var);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    if (prob < min_prob)
    {
      return 1;
    }
  }
  return 0;
}

int CLaser::GetDiffLRFData()
{
  double diff;
  range_t d;

<<<<<<< HEAD
  for (int n = 0; n < m_cnMaxConnect; n++)
  {
    if (m_bNodeActive[n])
    {
      m_DiffLRFData[n].clear();
      for (int i = 0; i < m_LRFData[n].size(); i++)
      {
        diff = fabs(m_LRFData[n][i] - m_BackLRFData[n][i]);

        if (diff >= m_diff_dist)
=======
  for(int n=0;n<m_cnMaxConnect;n++)
  {
    if(m_bNodeActive[n])
    {
      m_DiffLRFData[n].clear();
      for(int i=0; i<m_LRFData[n].size(); i++)
      {
        diff = fabs(m_LRFData[n][i] - m_BackLRFData[n][i]);

        if(diff >= m_diff_dist)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        {
          d.n = i;
          d.range = m_LRFData[n][i];
          m_DiffLRFData[n].push_back(d);
        }
      }
    }
  }

  return 0;
}

int CLaser::GetDiffLRFDataGaussian()
{
  double diff, prob;
  range_t d;

<<<<<<< HEAD
  for (int n = 0; n < m_cnMaxConnect; n++)
=======
  for (int n = 0; n<m_cnMaxConnect; n++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    if (m_bNodeActive[n])
    {
      m_DiffLRFData[n].clear();

<<<<<<< HEAD
      for (int i = 0; i < m_LRFData[n].size(); i++)
=======
      for (int i = 0; i<m_LRFData[n].size(); i++)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
      {
        diff = m_LRFData[n][i] - m_BackLRFDataAve[n][i];
        if (m_BackLRFDataVar[n][i] != 0.0)
        {
<<<<<<< HEAD
          prob = exp(-diff * diff / m_BackLRFDataVar[n][i]) / sqrt(2.0 * M_PI * m_BackLRFDataVar[n][i]);
=======
          prob = exp(-diff*diff / m_BackLRFDataVar[n][i]) / sqrt(2.0 * M_PI *m_BackLRFDataVar[n][i]);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

          if (prob < m_obj_prob)
          {
            d.n = i;
            d.range = m_LRFData[n][i];
            m_DiffLRFData[n].push_back(d);
          }
        }
      }
    }
  }

  return 0;
}

int CLaser::GetDiffLRFCluster(int n)
<<<<<<< HEAD
{
=======
{    
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  range_t d;
  cluster_t c;
  int sflg = 0;
  int sp = 0;

<<<<<<< HEAD
  if (m_bNodeActive[n])
=======
  if(m_bNodeActive[n])
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    m_DiffLRFData[n].clear();
    m_LRFClsData[n].clear();

<<<<<<< HEAD
    for (int i = 0; i < m_LRFData[n].size(); i++)
    {
      if (m_LRFData[n][i] > MIN_DIFF_DIST)
=======
    for(int i=0; i<m_LRFData[n].size(); i++)
    {
      if(m_LRFData[n][i] > MIN_DIFF_DIST)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
      {
        if (IsFrontFData(m_LRFData[n][i], m_BackLRFDataAve[n][i], m_BackLRFDataVar[n][i], m_obj_prob))
        {
          d.n = i;
          d.range = m_LRFData[n][i];
          m_DiffLRFData[n].push_back(d);

          if (sflg == 0)
          {
            sflg = 1;
            sp = i;
          }
          else
          {
            sflg++;
          }
        }
        else
        {
          if (sflg > 1)
          {
            c.n = sp + sflg / 2;
            c.range = m_LRFData[n][c.n];
            c.length = sflg;
            m_LRFClsData[n].push_back(c);
          }
          sflg = 0;
        }
      }
    }
  }

  return 0;
}
