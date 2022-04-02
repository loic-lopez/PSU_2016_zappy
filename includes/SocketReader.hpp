//
// SocketReader.hpp for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/SocketReader.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  mer. juin 28 14:11:57 2017 Loïc Lopez
// Last update mer. juin 28 14:11:57 2017 Loïc Lopez
//
#ifndef PSU_2016_ZAPPY_SOCKETREADER_HPP
#define PSU_2016_ZAPPY_SOCKETREADER_HPP

#include <thread>
#include "Parser.hpp"

class SocketReader
{
 private:
  std::thread		 	threadReader;
  bool 				read;

 public:
  SocketReader(Parser *parser, SocketConnection *socketConnection);
  void	stopSocketReader();
  void	reader(Parser *parser, SocketConnection *socketConnection);
  ~SocketReader();
};


#endif //PSU_2016_ZAPPY_SOCKETREADER_HPP