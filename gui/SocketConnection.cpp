//
// SocketConnection.cpp for SocketConnection in /home/jabbar_y/rendu/PSU_2016_zappy
// 
// Made by Jabbari Yassir
// Login   <jabbar_y@epitech.net>
// 
// Started on  Wed Jun 28 10:59:59 2017 Jabbari Yassir
// Last update Thu Jun 29 15:49:47 2017 Eric Deschodt
//

#include "SocketConnection.hpp"

SocketConnection::SocketConnection(std::string const &hostname, std::string const &port)
{
  this->hostname = hostname;
  this->port = std::stoi(port);
}

SocketConnection::~SocketConnection()
{
  this->_close();
}

int SocketConnection::_connect(int sockfd, const struct sockaddr *addr,
			       socklen_t addrlen)
{
  return (connect(sockfd, addr, addrlen));
}

int SocketConnection::_socket(int domain, int type, int protocol)
{
  return (socket(domain, type, protocol));
}

struct hostent *SocketConnection::getHostByName(std::string const &str)
{
  return (gethostbyname(str.c_str()));
}

uint16_t SocketConnection::_htons(uint16_t hostshort)
{
  return (htons(hostshort));
}

void SocketConnection::startConnection()
{
  if ((this->sd = this->_socket(AF_INET, SOCK_STREAM, 0)) <= 0)
    {
      std::cerr << "socket error" << std::endl;
      exit (EXIT_FAILURE);
    }
  if ((this->server = this->getHostByName(this->hostname)) == nullptr)
    {
      std::cerr << "can't get host" << std::endl;
      exit (EXIT_FAILURE);
    }
  std::memset(reinterpret_cast<char *>(&this->serverAddr), 0, sizeof(this->serverAddr));
  this->serverAddr.sin_family = AF_INET;
  std::memcpy(reinterpret_cast<char *>(&this->serverAddr.sin_addr.s_addr), this->server->h_addr, this->server->h_length);
  this->serverAddr.sin_port = this->_htons(this->port);
  if (this->_connect(this->sd, reinterpret_cast<struct sockaddr *>(&this->serverAddr), sizeof(this->serverAddr)) < 0)
    {
      std::cerr << "can't connect" << std::endl;
      exit (EXIT_FAILURE);
    }
}

const std::vector<std::string> &SocketConnection::getLog() const
{
  return this->log;
}

void SocketConnection::setLog(const std::vector<std::string> &log)
{
  this->log = log;
}

std::string SocketConnection::receive()
{
  char 		buff[4096];
  std::string	cmd;

  if (this->cmdToExecute.empty())
    {
      memset(&buff, 0, sizeof(buff));
      this->recvCode = recv(this->sd, &buff, sizeof(buff), 0);
      if (this->recvCode == -1)
	return ("");
      for (size_t i = 0; buff[i]; i++)
	{
	  if (buff[i] == '\n')
	    {
	      this->cmdToExecute.push_back(cmd);
	      cmd.clear();
	    }
	  else
	    cmd.push_back(buff[i]);
	}
    }
  if (!this->cmdToExecute.empty())
    {
      cmd = this->cmdToExecute.at(0);
      this->cmdToExecute.erase(this->cmdToExecute.begin());
      if (cmd.substr(0, 3) != "ppo"
	  && cmd.substr(0, 3) != "bct")
	this->log.insert(log.begin(), cmd);
      return (cmd);
    }
  return ("");
}

ssize_t SocketConnection::_send(std::string const &msg)
{
  return (send(this->sd, msg.c_str(), msg.size(), 0));
}

void SocketConnection::socketReader()
{
  while (42)
    this->receive();
}

std::string SocketConnection::sendAndReceive(std::string const &msg)
{
  this->_send(msg);
  return (this->receive());
}

ssize_t	SocketConnection::getRecvCode() const
{
  return this->recvCode;
}

void	SocketConnection::setRecvCode(ssize_t recvCode)
{
  this->recvCode = recvCode;
}

int 	SocketConnection::_close()
{
  return (close(this->sd));
}

int	SocketConnection::getSd()
{
  return (sd);
}
