<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <pthread.h>
=======
// ParticleFilter.cpp : �����t�@�C��
//
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <vector>
  #include <string.h>
  #include <pthread.h>
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

//#include "opencv2/opencv.hpp"
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "define.h"
#include "target.h"
#include "laser.h"
#include "particle_filter.h"

#include "multiple_particle_filter.h"

<<<<<<< HEAD
extern pthread_mutex_t mutex_laser;
extern pthread_mutex_t mutex_target;

CMultipleParticleFilter::CMultipleParticleFilter()
{
  m_max_ID = Config::is()->m_max_ID;
  m_min_distance = Config::is()->m_min_distance;  // 1m以上離れて出現したときだけ、新しいPFを生成
  m_initial_dist = Config::is()->m_initial_dist;  // 0.5m四方にパーティクルを初期配置
  m_max_lost_count = 1;  // 何回連続でデータが得られなかったか
  Area[0] = Config::is()->target_area[0];
  Area[1] = Config::is()->target_area[1];
  Area[2] = Config::is()->target_area[2];
  Area[3] = Config::is()->target_area[3];

  m_ID = 0;
=======
  extern pthread_mutex_t mutex_laser;
  extern pthread_mutex_t mutex_target;

CMultipleParticleFilter::CMultipleParticleFilter()
{
	m_max_ID = Config::is()->m_max_ID;
	m_min_distance = Config::is()->m_min_distance;	// 1000mm�ȏ㗣��ďo�������Ƃ������A�V����PF�𐶐�
	m_initial_dist = Config::is()->m_initial_dist;	// 500mm�l���Ƀp�[�e�B�N���������z�u

	m_ID = 0;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

CMultipleParticleFilter::~CMultipleParticleFilter()
{
<<<<<<< HEAD
  m_ParticleFilter.clear();
=======
	m_ParticleFilter.clear();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

void CMultipleParticleFilter::update(CLaser *Laser)
{
<<<<<<< HEAD
  m_pLaser = Laser;
  double obs[2], p[2];

  // 失探知した回数のカウンタを増やす もし，以下でパーティクルフィルタが更新，生成されたら，0にリセットされる
  for (vector< CPF >::iterator it = m_ParticleFilter.begin(); it != m_ParticleFilter.end(); ++it)
  {
    it->IncLostCnt();
  }

  for (int n = 0; n < m_pLaser->m_cnMaxConnect; n++)
  {
    if (m_pLaser->m_bNodeActive[n])
    {
      std::vector< int > label(m_pLaser->m_LRFClsPoints[n].size(), -1);  // クラスタに対応するパーティクルフィルタの番号
      int pn = m_ParticleFilter.size();                                  // 現在のパーティクルフィルタの個数

      for (int j = 0; j < m_pLaser->m_LRFClsPoints[n].size(); j++)
      {
        // クラスタ代表点
        obs[0] = m_pLaser->m_LRFClsPoints[n][j].x;
        obs[1] = m_pLaser->m_LRFClsPoints[n][j].y;

        // クラスタ毎に，一番近いパーティクルフィルタを探す
        double min_r = 1e10;
        int min_np = -1;
        int np = 0;
        for (vector< CPF >::iterator it = m_ParticleFilter.begin(); it != m_ParticleFilter.end(); ++it, ++np)
        {
          p[0] = it->state[0];
          p[1] = it->state[1];

          double r = sqrt(pow(p[0] - obs[0], 2) + pow(p[1] - obs[1], 2));
          // クラスタと既存のパーティクルフィルタとの距離がm_min_distance以下なら，既存のパーティクルフィルタに紐づけ
          if (r < m_min_distance)
          {
            if (min_r > r) {
               min_r = r;
               min_np = np;
            }
          }
        }

        // もし，クラスタに対応するパーティクルフィルタがなかったとき
        if (min_r < m_min_distance) {
          label[j] = min_np; // 対応したパーティクルフィルタの番号を保存
        } else {
          label[j] = pn++; // 新たにパーティクルフィルタを生成するために，新規の番号を与える
        }

      }

      for (int j = 0; j < m_pLaser->m_LRFClsPoints[n].size(); j++)
      {
        if (label[j] < 0)
        {
          std::cout << "Error" << std::endl;
        }
        else if (label[j] < m_ParticleFilter.size())
        {
          // 既存のパーティクルフィルタを更新
          obs[0] = m_pLaser->m_LRFClsPoints[n][j].x;
          obs[1] = m_pLaser->m_LRFClsPoints[n][j].y;
          m_ParticleFilter[label[j]].SetTarget(obs);
          m_ParticleFilter[label[j]].update();
        }
        else
        {
          // 新たにパーティクルフィルタを生成
          CPF pf;
          //int d = Config::is()->particle_area;
          obs[0] = m_pLaser->m_LRFClsPoints[n][j].x;
          obs[1] = m_pLaser->m_LRFClsPoints[n][j].y;
          if ((obs[0] < Area[0]) || (obs[0] >= Area[2]) || (obs[1] < Area[1]) || (obs[1] >= Area[3])) continue;

          int area[4] = {obs[0] - m_initial_dist / 2, obs[1] - m_initial_dist / 2, obs[0] + m_initial_dist / 2,
                         obs[1] + m_initial_dist / 2};
          pf.initialize(area);

          pf.SetTarget(obs);
          pf.SetID(m_ID++);
          pf.update();
          if(!isnan(pf.state[0]) && !isnan(pf.state[1]))
          m_ParticleFilter.push_back(pf);

        }
      }
    }
  }

  for (vector< CPF >::iterator it = m_ParticleFilter.begin(); it != m_ParticleFilter.end(); ++it)
  {
    // 多数回，更新も生成もされていないパーティクルフィルタを消去
    if (it->GetLostCnt() >= m_max_lost_count)
    {
      it->clear();
      it = m_ParticleFilter.erase(it);
      if (it == m_ParticleFilter.end())
        break;
    }
  }

  // 追跡結果（m_pTarget）の情報を更新
  for (int i = 0; i < MAX_TRACKING_OBJECT; i++)
  {
    delete m_pLaser->m_pTarget[i];
    m_pLaser->m_pTarget[i] = NULL;
  }

  int np = 0;
  for (vector< CPF >::iterator it = m_ParticleFilter.begin(); it != m_ParticleFilter.end(); ++it, ++np)
  {
    if(np >= MAX_TRACKING_OBJECT) break;
    m_pLaser->m_pTarget[np] = new CTarget();
    m_pLaser->m_pTarget[np]->id = it->GetID();
    m_pLaser->m_pTarget[np]->cnt = it->GetCnt();
    m_pLaser->m_pTarget[np]->SetPosi(it->state[0], it->state[1]);
  }

  std::cout << "Total number of particle filters " << m_ParticleFilter.size() << std::endl;

=======
	m_pLaser = Laser;
	double obs[2], p[2];

	for (int n = 0; n < 1; n++){
		if (m_pLaser->m_bNodeActive[n]){
			std::vector<int> label(m_pLaser->m_LRFClsPoints[n].size(), -1);		// �N���X�^�ɑΉ�����p�[�e�B�N���t�B���^�̔ԍ�
			int pn = m_ParticleFilter.size();	// ���݂̃p�[�e�B�N���t�B���^�̌�

			for (int j = 0; j < m_pLaser->m_LRFClsPoints[n].size(); j++){
				// �N���X�^��\�_
				obs[0] = m_pLaser->m_LRFClsPoints[n][j].x;
				obs[1] = m_pLaser->m_LRFClsPoints[n][j].y;

				// �N���X�^���ɁC��ԋ߂��p�[�e�B�N���t�B���^��T��
				double min_r = 1e10;
				int np = 0;
				for (vector<CPF>::iterator it = m_ParticleFilter.begin(); it != m_ParticleFilter.end(); ++it, ++np) {
					p[0] = it->state[0];
					p[1] = it->state[1];

					double r = sqrt(pow(p[0] - obs[0], 2) + pow(p[1] - obs[1], 2));

					if (min_r > r && r < m_min_distance){
						min_r = r;
						label[j] = np;
					}
				}

				// �����C�N���X�^�ɑΉ�����p�[�e�B�N���t�B���^���Ȃ������Ƃ�
				if (min_r >= m_min_distance){
					label[j] = pn++;
				}
			}

			std::vector<int> flg(pn, -1);		// �N���X�^�ɑΉ�����p�[�e�B�N���t�B���^�̔ԍ�
			for (int j = 0; j < m_pLaser->m_LRFClsPoints[n].size(); j++){
				if (label[j] < 0){
					std::cout << "Error" << std::endl;
				}
				else if (label[j] < m_ParticleFilter.size()){
					obs[0] = m_pLaser->m_LRFClsPoints[n][j].x;
					obs[1] = m_pLaser->m_LRFClsPoints[n][j].y;
					m_ParticleFilter[label[j]].SetTarget(obs);
					m_ParticleFilter[label[j]].update();
				}
				else{
					CPF pf;
					int d = Config::is()->particle_area * 1000;
					obs[0] = m_pLaser->m_LRFClsPoints[n][j].x;
					obs[1] = m_pLaser->m_LRFClsPoints[n][j].y;

					int area[4] = {obs[0]-m_initial_dist/2, obs[1]-m_initial_dist/2, obs[0]+m_initial_dist/2, obs[1]+m_initial_dist/2};
					pf.initialize(area);

					pf.SetTarget(obs);
					pf.SetID(m_ID++);
					pf.update();
					m_ParticleFilter.push_back(pf);
				}
				flg[label[j]] = 1;
			}

			int np = 0;
			for (vector<CPF>::iterator it = m_ParticleFilter.begin(); it != m_ParticleFilter.end(); ++it, ++np) {
				if (flg[np] < 0)  {
					it->clear();
					it = m_ParticleFilter.erase(it);
					if (it == m_ParticleFilter.end()) break;
				}
			}

			for (int i = 0; i < MAX_TRACKING_OBJECT; i++){
				delete m_pLaser->m_pTarget[i];
				m_pLaser->m_pTarget[i] = NULL;
			}

			np = 0;
			for (vector<CPF>::iterator it = m_ParticleFilter.begin(); it != m_ParticleFilter.end(); ++it, ++np) {
				m_pLaser->m_pTarget[np] = new CTarget();
				m_pLaser->m_pTarget[np]->id = it->GetID();
				m_pLaser->m_pTarget[np]->cnt = it->GetCnt();
				m_pLaser->m_pTarget[np]->SetPosi(it->state[0], it->state[1]);
			}
		}
	}
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}
