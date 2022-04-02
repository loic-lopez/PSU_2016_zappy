//
// SocketConnection.hpp for SocketConnection in /home/jabbar_y/rendu/PSU_2016_zappy
// 
// Made by Jabbari Yassir
// Login   <jabbar_y@epitech.net>
// 
// Started on  Wed Jun 28 10:55:55 2017 Jabbari Yassir
// Last update Thu Jun 29 09:59:25 2017 Eric Deschodt
//

#ifndef SOCKETCONNECTION_HPP
#define SOCKETCONNECTION_HPP

# include <arpa/inet.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <sys/types.h>
# include <string>
# include <cstring>
# include <iostream>
# include <vector>
# include <unistd.h>

class		SocketConnection
{
public:
  SocketConnection(std::string const &hostname, std::string const &port);
  ~SocketConnection();
  int _connect(int sockfd, const struct sockaddr *addr,
	       socklen_t addrlen);
  int _socket(int domain, int type, int protocol);
  struct hostent *getHostByName(std::string const &str);
  uint16_t _htons(uint16_t hostshort);
  void startConnection();
  const std::vector<std::string> &getLog() const;
  void setLog(const std::vector<std::string> &log);
  std::string receive();
  ssize_t _send(std::string const &msg);
  void socketReader();
  std::string sendAndReceive(std::string const &msg);
  ssize_t getRecvCode() const;
  void 	setRecvCode(ssize_t recvCode);
  int 	_close();
  int getSd();

 private:
  int				sd;
  struct sockaddr_in		serverAddr;
  struct hostent		*server;
  int				port;
  std::string			hostname;
  std::vector<std::string> 	log;
  ssize_t 			recvCode;
  std::vector<std::string>	cmdToExecute;
};

#endif // SOCKETCONNECTION_HPP
