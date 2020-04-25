//
// C++ Interface: exception
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

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

<<<<<<< HEAD
#include <string>
#include "dllexport.h"

=======

#include <string>
#include "dllexport.h"


>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#ifdef HAVE_LIBEBT

#include <libebt/libebt.hh>
#include <libebt/libebt_util.hh>

<<<<<<< HEAD
struct ExceptionTag
{
};
typedef libebt::BacktraceContext< ExceptionTag, std::string > Context;
=======
struct ExceptionTag { };
typedef libebt::BacktraceContext<ExceptionTag, std::string> Context;

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

///
/// @defgroup exceptions Exceptions
/// @{
///

<<<<<<< HEAD
class DLLDIR Exception : public libebt::Backtraceable< ExceptionTag >, public std::exception
{
protected:
  const std::string _message;
  const int _error_number;

public:
  Exception(const std::string& message, const int error_number) throw()
    : libebt::Backtraceable< ExceptionTag >(), std::exception(), _message(message), _error_number(error_number)
  {
  }

  virtual ~Exception() throw()
  {
  }

  std::string message() const throw()
  {
    return _message;
  }
  const char* what() const throw()
  {
    return _message.c_str();
  }

  const int error_number() const throw()
  {
    return _error_number;
  }
=======
class DLLDIR Exception : public libebt::Backtraceable<ExceptionTag>,
						 public std::exception {
    protected:
        const std::string _message;
		const int _error_number;

    public:
        Exception(const std::string & message, const int error_number) throw () :
            libebt::Backtraceable<ExceptionTag>(),
            std::exception(),
            _message(message), _error_number(error_number) {
        }

        virtual ~Exception() throw () {
        }

        std::string message() const throw() {
            return _message;
        }
	const char* what() const throw() {
	    return _message.c_str();
	}

	const int error_number() const throw() {
	    return _error_number;
	}
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};

///
/// @}
///

<<<<<<< HEAD
#else  // HAVE_LIBEBT
=======
#else // HAVE_LIBEBT
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

///
/// @defgroup exceptions Exceptions
/// @{
///

// The compiler should optimize that away
<<<<<<< HEAD
struct DLLDIR Context
{
  Context(const char*)
  {
  }
};

class DLLDIR Exception : public std::exception
{
protected:
  const std::string _message;
  const int _error_number;

public:
  Exception(const std::string& message, const int error_number) throw()
    : std::exception(), _message(message), _error_number(error_number)
  {
  }

  virtual ~Exception() throw()
  {
  }

  std::string message() const throw()
  {
    return _message;
  }
  const char* what() const throw()
  {
    return _message.c_str();
  }

  int error_number() const throw()
  {
    return _error_number;
  }
=======
struct DLLDIR Context {
    Context(const char*) {}
};

class DLLDIR Exception : public std::exception {
    protected:
        const std::string _message;
        const int _error_number;

    public:
        Exception(const std::string & message, const int error_number) throw () :
            std::exception(),
            _message(message), _error_number(error_number) {
        }

        virtual ~Exception() throw () {
        }

        std::string message() const throw() {
            return _message;
        }
	const char* what() const throw() {
	    return _message.c_str();
	}

	int error_number() const throw() {
	    return _error_number;
	}
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};

///
/// @}
///

<<<<<<< HEAD
=======

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#endif

#endif
