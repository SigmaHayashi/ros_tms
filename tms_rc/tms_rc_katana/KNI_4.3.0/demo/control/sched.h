/*
 * Module: sched.h
 *
 * Purpose:
 *      Provides an implementation of POSIX realtime extensions
<<<<<<< HEAD
 *      as defined in
=======
 *      as defined in 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
 *
 *              POSIX 1003.1b-1993      (POSIX.1b)
 *
 * --------------------------------------------------------------------------
 *
 *      Pthreads-win32 - POSIX Threads Library for Win32
 *      Copyright(C) 1998 John E. Bossom
 *      Copyright(C) 1999,2005 Pthreads-win32 contributors
<<<<<<< HEAD
 *
 *      Contact Email: rpj@callisto.canberra.edu.au
 *
=======
 * 
 *      Contact Email: rpj@callisto.canberra.edu.au
 * 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
 *      The current list of contributors is contained
 *      in the file CONTRIBUTORS included with the source
 *      code distribution. The list can also be seen at the
 *      following World Wide Web location:
 *      http://sources.redhat.com/pthreads-win32/contributors.html
<<<<<<< HEAD
 *
=======
 * 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
 *      This library is free software; you can redistribute it and/or
 *      modify it under the terms of the GNU Lesser General Public
 *      License as published by the Free Software Foundation; either
 *      version 2 of the License, or (at your option) any later version.
<<<<<<< HEAD
 *
=======
 * 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
 *      This library is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *      Lesser General Public License for more details.
<<<<<<< HEAD
 *
=======
 * 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
 *      You should have received a copy of the GNU Lesser General Public
 *      License along with this library in the file COPYING.LIB;
 *      if not, write to the Free Software Foundation, Inc.,
 *      59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#ifndef _SCHED_H
#define _SCHED_H

#undef PTW32_LEVEL

#if defined(_POSIX_SOURCE)
#define PTW32_LEVEL 0
/* Early POSIX */
#endif

#if defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 199309
#undef PTW32_LEVEL
#define PTW32_LEVEL 1
/* Include 1b, 1c and 1d */
#endif

#if defined(INCLUDE_NP)
#undef PTW32_LEVEL
#define PTW32_LEVEL 2
/* Include Non-Portable extensions */
#endif

#define PTW32_LEVEL_MAX 3

#if !defined(PTW32_LEVEL)
#define PTW32_LEVEL PTW32_LEVEL_MAX
/* Include everything */
#endif

<<<<<<< HEAD
#if __GNUC__ && !defined(__declspec)
#error Please upgrade your GNU compiler to one that supports __declspec.
=======

#if __GNUC__ && ! defined (__declspec)
# error Please upgrade your GNU compiler to one that supports __declspec.
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#endif

/*
 * When building the DLL code, you should define PTW32_BUILD so that
 * the variables/functions are exported correctly. When using the DLL,
 * do NOT define PTW32_BUILD, and then the variables/functions will
 * be imported correctly.
 */
#ifndef PTW32_STATIC_LIB
<<<<<<< HEAD
#ifdef PTW32_BUILD
#define PTW32_DLLPORT __declspec(dllexport)
#else
#define PTW32_DLLPORT __declspec(dllimport)
#endif
#else
#define PTW32_DLLPORT
=======
#  ifdef PTW32_BUILD
#    define PTW32_DLLPORT __declspec (dllexport)
#  else
#    define PTW32_DLLPORT __declspec (dllimport)
#  endif
#else
#  define PTW32_DLLPORT
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#endif

/*
 * This is a duplicate of what is in the autoconf config.h,
 * which is only used when building the pthread-win32 libraries.
 */

#ifndef PTW32_CONFIG_H
<<<<<<< HEAD
#if defined(WINCE)
#define NEED_ERRNO
#define NEED_SEM
#endif
#if defined(_UWIN) || defined(__MINGW32__)
#define HAVE_MODE_T
#endif
=======
#  if defined(WINCE)
#    define NEED_ERRNO
#    define NEED_SEM
#  endif
#  if defined(_UWIN) || defined(__MINGW32__)
#    define HAVE_MODE_T
#  endif
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#endif

/*
 *
 */

#if PTW32_LEVEL >= PTW32_LEVEL_MAX
#ifdef NEED_ERRNO
#include "need_errno.h"
#else
#include <errno.h>
#endif
#endif /* PTW32_LEVEL >= PTW32_LEVEL_MAX */

#if defined(__MINGW32__) || defined(_UWIN)
#if PTW32_LEVEL >= PTW32_LEVEL_MAX
/* For pid_t */
<<<<<<< HEAD
#include <sys/types.h>
/* Required by Unix 98 */
#include <time.h>
=======
#  include <sys/types.h>
/* Required by Unix 98 */
#  include <time.h>
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#endif /* PTW32_LEVEL >= PTW32_LEVEL_MAX */
#else
typedef int pid_t;
#endif

/* Thread scheduling policies */

<<<<<<< HEAD
enum
{
  SCHED_OTHER = 0,
  SCHED_FIFO,
  SCHED_RR,
  SCHED_MIN = SCHED_OTHER,
  SCHED_MAX = SCHED_RR
};

struct sched_param
{
=======
enum {
  SCHED_OTHER = 0,
  SCHED_FIFO,
  SCHED_RR,
  SCHED_MIN   = SCHED_OTHER,
  SCHED_MAX   = SCHED_RR
};

struct sched_param {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  int sched_priority;
};

#ifdef __cplusplus
<<<<<<< HEAD
extern "C" {
#endif /* __cplusplus */

PTW32_DLLPORT int __cdecl sched_yield(void);

PTW32_DLLPORT int __cdecl sched_get_priority_min(int policy);

PTW32_DLLPORT int __cdecl sched_get_priority_max(int policy);

PTW32_DLLPORT int __cdecl sched_setscheduler(pid_t pid, int policy);

PTW32_DLLPORT int __cdecl sched_getscheduler(pid_t pid);
=======
extern "C"
{
#endif                          /* __cplusplus */

PTW32_DLLPORT int __cdecl sched_yield (void);

PTW32_DLLPORT int __cdecl sched_get_priority_min (int policy);

PTW32_DLLPORT int __cdecl sched_get_priority_max (int policy);

PTW32_DLLPORT int __cdecl sched_setscheduler (pid_t pid, int policy);

PTW32_DLLPORT int __cdecl sched_getscheduler (pid_t pid);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

/*
 * Note that this macro returns ENOTSUP rather than
 * ENOSYS as might be expected. However, returning ENOSYS
 * should mean that sched_get_priority_{min,max} are
 * not implemented as well as sched_rr_get_interval.
 * This is not the case, since we just don't support
 * round-robin scheduling. Therefore I have chosen to
 * return the same value as sched_setscheduler when
 * SCHED_RR is passed to it.
 */
<<<<<<< HEAD
#define sched_rr_get_interval(_pid, _interval) (errno = ENOTSUP, (int)-1)

#ifdef __cplusplus
} /* End of extern "C" */
#endif /* __cplusplus */
=======
#define sched_rr_get_interval(_pid, _interval) \
  ( errno = ENOTSUP, (int) -1 )


#ifdef __cplusplus
}                               /* End of extern "C" */
#endif                          /* __cplusplus */
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

#undef PTW32_LEVEL
#undef PTW32_LEVEL_MAX

<<<<<<< HEAD
#endif /* !_SCHED_H */
=======
#endif                          /* !_SCHED_H */

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
