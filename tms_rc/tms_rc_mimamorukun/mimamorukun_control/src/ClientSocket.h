// Definition of the ClientSocket class

#ifndef ClientSocket_class
#define ClientSocket_class

#include "Socket.h"

<<<<<<< HEAD
class ClientSocket : private Socket
{
public:
  ClientSocket(std::string host, int port);
  virtual ~ClientSocket(){};
=======
class ClientSocket : private Socket {
 public:
  ClientSocket(std::string host, int port);
  virtual ~ClientSocket() {};
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  void init(std::string host, int port);

  const ClientSocket& operator<<(const std::string&) const;
  const ClientSocket& operator>>(std::string&) const;

<<<<<<< HEAD
private:
=======
 private:
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  std::string hostIP_s;
  int port;
};

#endif
