
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

#ifndef LWIPNETDNSREQUEST_H
#define LWIPNETDNSREQUEST_H

#define NET_LWIP_STACK 1
#include "if/net/netdnsrequest.h"

<<<<<<< HEAD
// struct ip_addr_t;
=======
//struct ip_addr_t;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#include "lwip/ip_addr.h"

class LwipNetDnsRequest : public NetDnsRequest
{
public:
<<<<<<< HEAD
  LwipNetDnsRequest(const char *hostname);
  LwipNetDnsRequest(Host *pHost);
  virtual ~LwipNetDnsRequest();

  // Execute request & return OK if found, NOTFOUND or ERROR on error, or PROCESSING if the request has not completed
  // yet
  virtual void poll();

=======
  LwipNetDnsRequest(const char* hostname);
  LwipNetDnsRequest(Host* pHost);
  virtual ~LwipNetDnsRequest();

  //Execute request & return OK if found, NOTFOUND or ERROR on error, or PROCESSING if the request has not completed yet
  virtual void poll();
  
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  virtual void close();

protected:
  void foundCb(const char *name, ip_addr_t *ipaddr);
<<<<<<< HEAD

=======
  
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
private:
  enum LwipNetDnsState
  {
    LWIPNETDNS_START,
<<<<<<< HEAD
    LWIPNETDNS_PROCESSING,  // Req has not completed
=======
    LWIPNETDNS_PROCESSING, //Req has not completed
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    LWIPNETDNS_NOTFOUND,
    LWIPNETDNS_ERROR,
    LWIPNETDNS_OK
  };

  LwipNetDnsState m_state;
  bool m_cbFired;
<<<<<<< HEAD

  // Static callbacks : Transforms into a C++ callback
  static void sFoundCb(const char *name, ip_addr_t *ipaddr, void *arg);

=======
  
  //Static callbacks : Transforms into a C++ callback
  static void sFoundCb(const char *name, ip_addr_t *ipaddr, void *arg);
  
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  bool m_closing;
};

#endif
