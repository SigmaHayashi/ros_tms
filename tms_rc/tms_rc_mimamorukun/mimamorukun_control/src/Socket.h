// Definition of the Socket class

#ifndef Socket_class
#define Socket_class

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>
#include <iostream>

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

<<<<<<< HEAD
class Socket
{
public:
=======
class Socket {
 public:
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  Socket();
  virtual ~Socket();

  // Server initialization
  bool create();
  bool bind(const int port);
  bool listen() const;
<<<<<<< HEAD
  bool accept(Socket &) const;
=======
  bool accept(Socket&) const;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  // Client initialization
  bool connect(const std::string host, const int port);

  // Data Transimission
  bool send(const std::string) const;
<<<<<<< HEAD
  int recv(std::string &) const;

  void set_non_blocking(const bool);

  bool is_valid() const
  {
    return m_sock != -1;
  }

private:
=======
  int recv(std::string&) const;

  void set_non_blocking(const bool);

  bool is_valid() const { return m_sock != -1; }

 private:
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  int m_sock;
  sockaddr_in m_addr;
};

#endif
