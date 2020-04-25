
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
DNS Request header file
*/

#ifndef DNSREQUEST_H
#define DNSREQUEST_H

#include "core/net.h"
#include "core/ipaddr.h"
#include "core/host.h"
<<<<<<< HEAD
// Essentially it is a safe interface to NetDnsRequest

/// DNS Request error codes
enum DNSRequestErr
{
  __DNS_MIN = -0xFFFF,
  DNS_SETUP,       ///<DNSRequest not properly configured
  DNS_IF,          ///<Interface has problems, does not exist or is not initialized
  DNS_MEM,         ///<Not enough mem
  DNS_INUSE,       ///<Interface / Port is in use
  DNS_PROCESSING,  ///<Request has not completed
                   //...
  DNS_OK = 0       ///<Success
};

/// DNS Request Result Events
enum DNSReply
{
  DNS_PRTCL,
  DNS_NOTFOUND,  /// Hostname is unknown
  DNS_ERROR,     /// Problem with DNS Service
=======
//Essentially it is a safe interface to NetDnsRequest

///DNS Request error codes
enum DNSRequestErr
{
  __DNS_MIN = -0xFFFF,
  DNS_SETUP, ///<DNSRequest not properly configured
  DNS_IF, ///<Interface has problems, does not exist or is not initialized
  DNS_MEM, ///<Not enough mem
  DNS_INUSE, ///<Interface / Port is in use
  DNS_PROCESSING, ///<Request has not completed
//...
  DNS_OK = 0 ///<Success
};

///DNS Request Result Events
enum DNSReply
{
  DNS_PRTCL,
  DNS_NOTFOUND, ///Hostname is unknown
  DNS_ERROR, ///Problem with DNS Service
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  //...
  DNS_FOUND,
};

class NetDnsRequest;
enum NetDnsReply;

<<<<<<< HEAD
/// This is a simple DNS Request class
=======
///This is a simple DNS Request class
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
/**
  This class exposes an API to deal with DNS Requests
*/
class DNSRequest
{
public:
<<<<<<< HEAD
  /// Creates a new request
  DNSRequest();

  /// Terminates and closes request
  ~DNSRequest();

  /// Resolves an hostname
=======
  ///Creates a new request
  DNSRequest();
  
  ///Terminates and closes request
  ~DNSRequest();
  
  ///Resolves an hostname
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  /**
  @param hostname : hostname to resolve
  */
  DNSRequestErr resolve(const char* hostname);
<<<<<<< HEAD

  /// Resolves an hostname
=======
  
  ///Resolves an hostname
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  /**
  @param host : hostname to resolve, the result will be stored in the IpAddr field of this object
  */
  DNSRequestErr resolve(Host* pHost);
<<<<<<< HEAD

  /// Setups callback
  /**
  The callback function will be called on result.
  @param pMethod : callback function
  */
  void setOnReply(void (*pMethod)(DNSReply));

  class CDummy;
  /// Setups callback
=======
  
  ///Setups callback
  /**
  The callback function will be called on result.
  @param pMethod : callback function
  */  
  void setOnReply( void (*pMethod)(DNSReply) );
  
  class CDummy;
  ///Setups callback
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  /**
  The callback function will be called on result.
  @param pItem : instance of class on which to execute the callback method
  @param pMethod : callback method
  */
<<<<<<< HEAD
  template < class T >
  void setOnReply(T* pItem, void (T::*pMethod)(DNSReply))
  {
    m_pCbItem = (CDummy*)pItem;
    m_pCbMeth = (void (CDummy::*)(DNSReply))pMethod;
  }

  /// Gets IP address once it has been resolved
=======
  template<class T> 
  void setOnReply( T* pItem, void (T::*pMethod)(DNSReply) )
  {
    m_pCbItem = (CDummy*) pItem;
    m_pCbMeth = (void (CDummy::*)(DNSReply)) pMethod;
  }
  
  ///Gets IP address once it has been resolved
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  /**
  @param pIp : pointer to an IpAddr instance in which to store the resolved IP address
  */
  DNSRequestErr getResult(IpAddr* pIp);
<<<<<<< HEAD

  /// Closes DNS Request before completion
  DNSRequestErr close();

=======
  
  ///Closes DNS Request before completion
  DNSRequestErr close();
  
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
protected:
  void onNetDnsReply(NetDnsReply r);
  DNSRequestErr checkInst();

private:
  NetDnsRequest* m_pNetDnsRequest;
<<<<<<< HEAD

  CDummy* m_pCbItem;
  void (CDummy::*m_pCbMeth)(DNSReply);

  void (*m_pCb)(DNSReply);
=======
  
  CDummy* m_pCbItem;
  void (CDummy::*m_pCbMeth)(DNSReply);
  
  void (*m_pCb)(DNSReply);

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};

#endif
