// Implementation of the ClientSocket class

#include "ClientSocket.h"
#include "SocketException.h"
#include <ros/ros.h>

<<<<<<< HEAD
ClientSocket::ClientSocket(std::string host, int port)
{
  this->init(host, port);
}

void ClientSocket::init(std::string host, int port)
{
  this->hostIP_s = host;
  this->port = port;
  if (!Socket::create())
  {
    throw SocketException("Could not create client socket.");
  }
  if (this->hostIP_s.empty())
  {
    ROS_ERROR("host IP enmpty");
    return;
  }
  if (!Socket::connect(host, port))
  {
=======
ClientSocket::ClientSocket(std::string host, int port) { this->init(host, port); }

void ClientSocket::init(std::string host, int port) {
  this->hostIP_s = host;
  this->port = port;
  if (!Socket::create()) {
    throw SocketException("Could not create client socket.");
  }
  if (this->hostIP_s.empty()) {
    ROS_ERROR("host IP enmpty");
    return;
  }
  if (!Socket::connect(host, port)) {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    throw SocketException("Could not bind to port.");
  }
}

<<<<<<< HEAD
const ClientSocket& ClientSocket::operator<<(const std::string& s) const
{
  if (this->hostIP_s.empty())
  {
    ROS_ERROR("host IP enmpty");
    return *this;
  }
  if (!Socket::send(s))
  {
=======
const ClientSocket& ClientSocket::operator<<(const std::string& s) const {
  if (this->hostIP_s.empty()) {
    ROS_ERROR("host IP enmpty");
    return *this;
  }
  if (!Socket::send(s)) {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    throw SocketException("Could not write to socket.");
  }

  return *this;
}

<<<<<<< HEAD
const ClientSocket& ClientSocket::operator>>(std::string& s) const
{
  if (this->hostIP_s.empty())
  {
    ROS_ERROR("host IP enmpty");
    return *this;
  }
  if (!Socket::recv(s))
  {
=======
const ClientSocket& ClientSocket::operator>>(std::string& s) const {
  if (this->hostIP_s.empty()) {
    ROS_ERROR("host IP enmpty");
    return *this;
  }
  if (!Socket::recv(s)) {
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    throw SocketException("Could not read from socket.");
  }

  return *this;
}
