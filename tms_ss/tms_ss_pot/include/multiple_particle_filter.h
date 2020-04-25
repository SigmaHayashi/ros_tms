class CMultipleParticleFilter
{
public:
<<<<<<< HEAD
  CMultipleParticleFilter();
  virtual ~CMultipleParticleFilter();

  void update(CLaser *Laser);

public:
  std::vector< CPF > m_ParticleFilter;
  CLaser *m_pLaser;

protected:
  int m_max_ID;
  double m_min_distance;
  double m_initial_dist;
  int m_ID;
  int m_max_lost_count;
  double Area[4];

=======
	CMultipleParticleFilter();
	virtual ~CMultipleParticleFilter();

	void update(CLaser *Laser);

public:
	std::vector<CPF> m_ParticleFilter;
	CLaser* m_pLaser;

protected:
	int    m_max_ID;
	double m_min_distance;
	double m_initial_dist;
	int    m_ID;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};
