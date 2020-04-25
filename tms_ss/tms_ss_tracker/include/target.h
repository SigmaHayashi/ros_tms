#ifndef TARGET_H
#define TARGET_H

class CTarget
{
public:
  CTarget();
  virtual ~CTarget();

public:
  int id;
  double px;
  double py;
  int cnt;

public:
  void SetPosi(double x, double y);
};

<<<<<<< HEAD
#endif  // TARGET_H
=======
#endif // TARGET_H
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
