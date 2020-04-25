// SocketException class

#ifndef SocketException_class
#define SocketException_class

#include <string>

<<<<<<< HEAD
class SocketException
{
public:
  SocketException(std::string s) : m_s(s){};
  ~SocketException(){};

  std::string description()
  {
    return m_s;
  }

private:
=======
class SocketException {
 public:
  SocketException(std::string s) : m_s(s) {};
  ~SocketException() {};

  std::string description() { return m_s; }

 private:
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  std::string m_s;
};

#endif
