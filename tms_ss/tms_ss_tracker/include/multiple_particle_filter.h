#ifndef MULTIPLE_PARTICLE_FILTER_H
#define MULTIPLE_PARTICLE_FILTER_H

class CMultipleParticleFilter
{
public:
  CMultipleParticleFilter();
  virtual ~CMultipleParticleFilter();

  void update(CLaser *Laser);

public:
<<<<<<< HEAD
  std::vector< CPF > m_ParticleFilter;
  CLaser *m_pLaser;

protected:
  int m_max_ID;
  double m_min_distance;
  int m_ID;
};

#endif  // MULTIPLE_PARTICLE_FILTER_H
=======
  std::vector<CPF> m_ParticleFilter;
  CLaser* m_pLaser;

protected:
  int    m_max_ID;
  double m_min_distance;
  int    m_ID;
};

#endif // MULTIPLE_PARTICLE_FILTER_H
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
