<<<<<<< HEAD
#include "condens/condens.hpp"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
=======

#include <opencv2/legacy/legacy.hpp>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#endif

class CPF
{
public:
<<<<<<< HEAD
  CPF();
  virtual ~CPF();

public:
  void update();
  void initialize(int area[2]);
  void clear();
  void SetTarget(double t[2]);
  void GetTarget(double t[2]);
  double state[4];
  void SetID(int ID);
  int GetID();
  int GetCnt();
  int IncLostCnt();
  int GetLostCnt();

  // protected:
  CvConDensation* particle_filter;
  double m_sigma;
  int Dimension;
  int Num_of_particles;
  double Area[4];
  double MaxVel;
  double target[2];
  int m_ID;
  int m_cnt;
  double Noise[2];
  int m_lostcnt;

  double likelihood(double p[2]);
=======
	CPF();
	virtual ~CPF();

public:
	void update();
	void initialize(int area[2]);
	void clear();
	void SetTarget(double t[2]);
	void GetTarget(double t[2]);
	double state[4];
	void SetID(int ID);
	int GetID();
	int GetCnt();

//protected:
	CvConDensation* particle_filter;
	double m_sigma;
	int Dimension;
	int Num_of_particles;
	double Area[4];
	double MaxVel;
	double target[2];
	int m_ID;
	int m_cnt;
	double Noise[2];

	double likelihood(double p[2]);

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};
