//
// C++ Interface: SctBase
//
<<<<<<< HEAD
// Description:
=======
// Description: 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
//
//
// Author: Tiziano Müller <tiziano.mueller@neuronics.ch>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

<<<<<<< HEAD
=======

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#ifndef KMLSCTBASE_H
#define KMLSCTBASE_H

#include "common/dllexport.h"

#include "KNI/kmlCommon.h"
#include "KNI/cplBase.h"

<<<<<<< HEAD
class CKatBase;  // forward declaration
class CSctBase;  // forward declaration
=======

class CKatBase; //forward declaration
class CSctBase; //forward declaration

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

/****************************************************************************/
// CSctBase ----------------------------------------------------------------//
/****************************************************************************/

/*!	\brief sensor controller description (partly)
 */
<<<<<<< HEAD
struct TSctDesc
{
  byte ctrlID;       //!< controller number (ID)
  short sens_res;    //!< resolution: 8/12 bit
  short sens_count;  //!< count of sensors
=======
struct  TSctDesc {
	byte		ctrlID;			//!< controller number (ID)
	short		sens_res;		//!< resolution: 8/12 bit
	short		sens_count;		//!< count of sensors
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};

/*!	\brief	[SCT] every sens ctrl's attributes
 */
<<<<<<< HEAD
struct TKatSCT
{
  short cnt;       //!< count of sens ctrl's
  CSctBase* arr;   //!< array of sens ctrl's
  TSctDesc* desc;  //!< description[]
=======
struct  TKatSCT {
	short		cnt;			//!< count of sens ctrl's
	CSctBase*	arr;			//!< array of sens ctrl's
	TSctDesc*	desc;			//!< description[]
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};

/*!	\brief	[GNL] controller generals
 */
<<<<<<< HEAD
struct TSctGNL
{
  CKatBase* own;  //!< parent robot
  byte SID;       //!< slave ID
  short res;      //!< resolution: 8/12 bit
=======
struct TSctGNL {
	CKatBase*	own;			//!< parent robot
	byte		SID;			//!< slave ID
	short		res;			//!< resolution: 8/12 bit
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};

/*!	\brief	[DAT] sensor data
 */
<<<<<<< HEAD
struct TSctDAT
{
  short cnt;   //!< count of sensors
  short* arr;  //!< sensor data
=======
struct  TSctDAT {
	short		cnt;			//!< count of sensors
	short*		arr;			//!< sensor data
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};

//--------------------------------------------------------------------------//

/*!	\brief	Sensor Controller class
 *
 *	By using this class you can get access to the sensor data; to do so you
 *	should (after initialization) call 'recvDat()' to updated the internal
 *	'TSctDAT dat' structure; after the updated you can read out the values
 *	by using the 'GetDAT()' function, which will return a constant pointer
 *	to the internal 'dat' structure.
 */
<<<<<<< HEAD
class DLLDIR CSctBase
{
  friend class CKatBase;

protected:
  TSctGNL gnl;  //!< controller generals
  TSctDAT dat;  //!< sensor data

public:
  const TSctGNL* GetGNL()
  {
    return &gnl;
  }
  const TSctDAT* GetDAT()
  {
    return &dat;
  }

protected:
  CCplBase* protocol;  //!< protocol interface

public:
  virtual ~CSctBase()
  {
  }  // destructor

  bool init(CKatBase* _own, const TSctDesc _sctDesc, CCplBase* protocol);

  /*!\brief receive data
  */
  void recvDAT();
};

=======
class DLLDIR CSctBase {

	friend class CKatBase;

protected:
	TSctGNL	gnl;	//!< controller generals
	TSctDAT dat;	//!< sensor data

public:
	const TSctGNL* GetGNL() { return &gnl; }
	const TSctDAT* GetDAT() { return &dat; }

protected:
	CCplBase* protocol;	//!< protocol interface

public:
	virtual ~CSctBase() {}	//destructor

	bool init(CKatBase* _own, const TSctDesc _sctDesc, CCplBase* protocol);

	/*!\brief receive data
	*/	
	void recvDAT();
};











>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#endif
