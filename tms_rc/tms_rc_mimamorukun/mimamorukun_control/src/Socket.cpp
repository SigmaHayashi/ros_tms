// Implementation of the Socket class.

#include "Socket.h"
#include "string.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>

<<<<<<< HEAD
Socket::Socket() : m_sock(-1)
{
  memset(&m_addr, 0, sizeof(m_addr));
}

Socket::~Socket()
{
  if (is_valid())
    ::close(m_sock);
}

bool Socket::create()
{
  m_sock = socket(AF_INET, SOCK_STREAM, 0);

  if (!is_valid())
    return false;
=======
Socket::Socket() : m_sock(-1) { memset(&m_addr, 0, sizeof(m_addr)); }

Socket::~Socket() {
  if (is_valid()) ::close(m_sock);
}

bool Socket::create() {
  m_sock = socket(AF_INET, SOCK_STREAM, 0);

  if (!is_valid()) return false;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  // TIME_WAIT - argh
  int on = 1;
  if (setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on)) == -1)
    return false;

  return true;
}

<<<<<<< HEAD
bool Socket::bind(const int port)
{
  if (!is_valid())
  {
=======
bool Socket::bind(const int port) {

  if (!is_valid()) {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    return false;
  }

  m_addr.sin_family = AF_INET;
  m_addr.sin_addr.s_addr = INADDR_ANY;
  m_addr.sin_port = htons(port);

  int bind_return = ::bind(m_sock, (struct sockaddr*)&m_addr, sizeof(m_addr));

<<<<<<< HEAD
  if (bind_return == -1)
  {
=======
  if (bind_return == -1) {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    return false;
  }

  return true;
}

<<<<<<< HEAD
bool Socket::listen() const
{
  if (!is_valid())
  {
=======
bool Socket::listen() const {
  if (!is_valid()) {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    return false;
  }

  int listen_return = ::listen(m_sock, MAXCONNECTIONS);

<<<<<<< HEAD
  if (listen_return == -1)
  {
=======
  if (listen_return == -1) {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    return false;
  }

  return true;
}

<<<<<<< HEAD
bool Socket::accept(Socket& new_socket) const
{
=======
bool Socket::accept(Socket& new_socket) const {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  int addr_length = sizeof(m_addr);
  new_socket.m_sock = ::accept(m_sock, (sockaddr*)&m_addr, (socklen_t*)&addr_length);

  if (new_socket.m_sock <= 0)
    return false;
  else
    return true;
}

<<<<<<< HEAD
bool Socket::send(const std::string s) const
{
  int status = ::send(m_sock, s.c_str(), s.size(), MSG_NOSIGNAL);
  if (status == -1)
  {
    return false;
  }
  else
  {
=======
bool Socket::send(const std::string s) const {
  int status = ::send(m_sock, s.c_str(), s.size(), MSG_NOSIGNAL);
  if (status == -1) {
    return false;
  } else {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    return true;
  }
}

<<<<<<< HEAD
int Socket::recv(std::string& s) const
{
=======
int Socket::recv(std::string& s) const {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  char buf[MAXRECV + 1];

  s = "";

  memset(buf, 0, MAXRECV + 1);

  int status = ::recv(m_sock, buf, MAXRECV, 0);

<<<<<<< HEAD
  if (status == -1)
  {
    std::cout << "status == -1   errno == " << errno << "  in Socket::recv\n";
    return 0;
  }
  else if (status == 0)
  {
    return 0;
  }
  else
  {
=======
  if (status == -1) {
    std::cout << "status == -1   errno == " << errno << "  in Socket::recv\n";
    return 0;
  } else if (status == 0) {
    return 0;
  } else {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    s = buf;
    return status;
  }
}

<<<<<<< HEAD
bool Socket::connect(const std::string host, const int port)
{
  if (!is_valid())
    return false;
=======
bool Socket::connect(const std::string host, const int port) {
  if (!is_valid()) return false;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  m_addr.sin_family = AF_INET;
  m_addr.sin_port = htons(port);

  int status = inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);

<<<<<<< HEAD
  if (errno == EAFNOSUPPORT)
    return false;
=======
  if (errno == EAFNOSUPPORT) return false;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  status = ::connect(m_sock, (sockaddr*)&m_addr, sizeof(m_addr));

  if (status == 0)
    return true;
  else
    return false;
}

<<<<<<< HEAD
void Socket::set_non_blocking(const bool b)
{
=======
void Socket::set_non_blocking(const bool b) {

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  int opts;

  opts = fcntl(m_sock, F_GETFL);

<<<<<<< HEAD
  if (opts < 0)
  {
=======
  if (opts < 0) {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    return;
  }

  if (b)
    opts = (opts | O_NONBLOCK);
  else
    opts = (opts & ~O_NONBLOCK);

  fcntl(m_sock, F_SETFL, opts);
}
