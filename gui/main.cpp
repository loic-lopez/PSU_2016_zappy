//
// main.cpp for main in /home/jabbar_y/rendu/PSU_2016_zappy/gui
// 
// Made by Jabbari Yassir
// Login   <jabbar_y@epitech.net>
// 
// Started on  Mon Jun 26 13:47:53 2017 Jabbari Yassir
// Last update Thu Jun 29 12:49:08 2017 Eric Deschodt
//

#include "gui.hpp"

int		main(int ac, char **av)
{

  if (ac >= 3)
    {
      SocketConnection socketConnection(av[1], av[2]);
      socketConnection.startConnection();
      Parser	parser(&socketConnection);
      parser.connectToServer(socketConnection.receive());
      SocketReader	socketReader(&parser, &socketConnection);
      Graphics	graphics(&parser, &socketConnection, &socketReader);
      graphics.mainloop();
    }
  return (0);
} 
