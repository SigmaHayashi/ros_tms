/*
 *   Katana Native Interface - A C++ interface to the robot arm Katana.
 *   Copyright (C) 2005 Neuronics AG
 *   Check out the AUTHORS file for detailed contact information.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef KNITIMER_H
#define KNITIMER_H

#include <ctime>

<<<<<<< HEAD
#ifndef WIN32  // POSIX 1b
#include <sys/time.h>
#endif

namespace KNI
{
=======
#ifndef WIN32 // POSIX 1b
#include <sys/time.h>
#endif

namespace KNI {

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
///
/// This functions shields the platform specific implementation of the sleep function.
///
///
<<<<<<< HEAD
void sleep(long time);
=======
    void sleep(long time);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

///
/// Provides a stop-watch-like class with a resolution of milliseconds.
///
<<<<<<< HEAD
class Timer
{
private:
  long _timeout;

#ifdef WIN32
  clock_t _ct;
#else
  struct timeval _ct;
#endif

  /// Platform specific implementation of ElapsedTime().
  long _ElapsedTime() const;

public:
  Timer();
  Timer(long timeout);

  void Set(long timeout);
  void Start();

  void Set_And_Start(long timeout);

  ///
  /// Returns true if timer is elapsed.
  ///
  bool Elapsed() const;

  ///
  /// Returns the elapsed time.
  ///
  long ElapsedTime() const;

  ///
  /// Block until time's up.
  ///
  void WaitUntilElapsed() const;
};
=======
    class Timer {
    private:
	long _timeout;
	
#ifdef WIN32
	clock_t _ct;
#else
	struct timeval _ct;
#endif

        /// Platform specific implementation of ElapsedTime().
	long _ElapsedTime() const;

    public:
	Timer();
	Timer(long timeout);

	void Set(long timeout);
	void Start();

	void Set_And_Start(long timeout);
	
	///
	/// Returns true if timer is elapsed.
	///
	bool Elapsed() const;

	///
	/// Returns the elapsed time.
	///
	long ElapsedTime() const;

        ///
        /// Block until time's up.
        ///
        void WaitUntilElapsed() const;

    };



>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

#endif
