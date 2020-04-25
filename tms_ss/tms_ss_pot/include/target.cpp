<<<<<<< HEAD
=======
// Target.cpp : ŽÀ‘•ƒtƒ@ƒCƒ‹
//
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#ifdef WIN32
#pragma warning(disable : 4996)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include "opencv2\opencv.hpp"
#include "opencv/cv.h"

#include "define.h"
#include "target.h"

<<<<<<< HEAD
CTarget::CTarget()
{
  id = 0;
  px = 0;
  py = 0;
  cnt = 0;
=======
// CTarget

CTarget::CTarget()
{
	id = 0;
	px = 0;
	py = 0;
	cnt = 0;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

CTarget::~CTarget()
{
}

void CTarget::SetPosi(double x, double y)
{
<<<<<<< HEAD
  px = x;
  py = y;
=======
	px = x;
	py = y;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}
