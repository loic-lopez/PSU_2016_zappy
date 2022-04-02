//
// SocketReader.cpp for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/SocketReader.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  mer. juin 28 14:11:57 2017 Loïc Lopez
// Last update Fri Jun 30 15:58:01 2017 Eric Deschodt
//

#include "SocketReader.hpp"

SocketReader::SocketReader(Parser *parser, SocketConnection *socketConnection)
{
  this->threadReader = std::thread(&SocketReader::reader, this, parser, socketConnection);
  this->read = true;
}

SocketReader::~SocketReader()
{
  this->threadReader.join();
}

void	SocketReader::reader(Parser *parser, SocketConnection *socketConnection)
{
  std::string	cmd;

  while (this->read)
    {
      if (socketConnection->getRecvCode() == -1)
	break;
      cmd = socketConnection->receive();
      if (this->read)
	{
	  parser->launchCommand(cmd);
	}
    }
}

void	SocketReader::stopSocketReader()
{
  this->read = false;
}
