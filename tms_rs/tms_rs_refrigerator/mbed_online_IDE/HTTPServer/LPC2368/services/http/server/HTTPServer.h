
/*
Copyright (c) 2010 Donatien Garnier (donatiengar [at] gmail [dot] com)
<<<<<<< HEAD

=======
 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
<<<<<<< HEAD

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

=======
 
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/** \file
HTTP Server header file
*/

#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

class HTTPRequestHandler;
class HTTPRequestDispatcher;

#include "core/net.h"
#include "HTTPRequestHandler.h"
#include "HTTPRequestDispatcher.h"

#include <string>
using std::string;

#include <map>
using std::map;

<<<<<<< HEAD
/// A simple HTTP server implementation
=======
///A simple HTTP server implementation
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
/**
The HTTPServer is composed of:
- The actual server (HTTPServer)
- A request dispatcher, instanciated on each request (HTTPRequestDispatcher)
<<<<<<< HEAD
- Request handlers instanciated by the dispatcher(deriving from HTTPRequestHandler)
=======
- Request handlers instanciated by the dispatcher(deriving from HTTPRequestHandler) 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
*/
class HTTPServer
{
public:
<<<<<<< HEAD
  /// Instantiates the HTTP Server
  HTTPServer();
  ~HTTPServer();

  struct handlersComp  // Used to order handlers in the right way
  {
    bool operator()(const string& handler1, const string& handler2) const
    {
      // The first handler is longer than the second one
      if (handler1.length() > handler2.length())
        return true;  // Returns true if handler1 is to appear before handler2
      else if (handler1.length() < handler2.length())
        return false;
      else  // To avoid the == case, sort now by address
        return ((&handler1) > (&handler2));
    }
  };

  /// Adds a handler
=======
  ///Instantiates the HTTP Server
  HTTPServer();
  ~HTTPServer();
  
  struct handlersComp //Used to order handlers in the right way
  {
    bool operator() (const string& handler1, const string& handler2) const
    {
      //The first handler is longer than the second one
      if (handler1.length() > handler2.length())
        return true; //Returns true if handler1 is to appear before handler2
      else if (handler1.length() < handler2.length())
        return false;
      else //To avoid the == case, sort now by address
        return ((&handler1)>(&handler2));
    }
  };

  ///Adds a handler
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  /**
  Appends a handler to the handlers list
  @param T : class which will be instanciated to serve these requests
  @param path : requests starting with this path will be served using this handler
  */
<<<<<<< HEAD
  template < typename T >
  void addHandler(const char* path)  // Template decl in header
  {
    m_lpHandlers[path] = &T::inst;
  }

  /// Starts listening
=======
  template<typename T>
  void addHandler(const char* path) //Template decl in header
  { m_lpHandlers[path] = &T::inst; }
  
  ///Starts listening
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  /**
  Binds server to a specific port and starts listening
  @param port : port on which to listen for incoming connections
  */
  void bind(int port = 80);
<<<<<<< HEAD

=======
  
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
private:
  friend class HTTPRequestDispatcher;

  void onTCPSocketEvent(TCPSocketEvent e);
<<<<<<< HEAD

  TCPSocket* m_pTCPSocket;
  map< string, HTTPRequestHandler* (*)(const char*, const char*, TCPSocket*), handlersComp > m_lpHandlers;
};

// Including handlers here for more convenience
=======
  
  TCPSocket* m_pTCPSocket;
  map< string, HTTPRequestHandler*(*)(const char*, const char*, TCPSocket*), handlersComp > m_lpHandlers;

};

//Including handlers here for more convenience
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#include "impl/RPCHandler.h"
#include "impl/FSHandler.h"
#include "impl/SimpleHandler.h"

#endif
