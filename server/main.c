/*
** main.c for main in /home/piazza_p/rendu/PSU_2016_zappy
** 
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
** 
** Started on  Mon May 29 15:28:46 2017 pierre piazza
** Last update Thu Jun 29 12:47:28 2017 pierre piazza
*/

#include "server.h"

void 	error()
{
  fprintf(stderr, "%s\n", strerror(errno));
  exit(EXIT_FAILURE);
}

void		init_server(t_serv *server)
{
  int 		opt;

  opt = 1;
  if ((server->master_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    error();
  if (setsockopt(server->master_socket, SOL_SOCKET,
		 SO_REUSEADDR, (char *)&opt, sizeof(int)) < 0)
    {
      close(server->master_socket);
      error();
    }
  server->addr.sin_family = AF_INET;
  server->addr.sin_addr.s_addr = INADDR_ANY;
  server->addr.sin_port = htons(server->port);
  if ((bind(server->master_socket, (struct sockaddr *)&server->addr,
	   sizeof(server->addr)) < 0)
      || (listen(server->master_socket, 10) < 0))
    {
      close(server->master_socket);
      error();
    }
  server->addrlen = sizeof(server->addr);
  server->max_sd = 3;
  server->max_id = 0;
}

int		main(int ac, char **av)
{
  t_serv	serv;

  srand(time(NULL));
  check_args(ac, av, &serv);
  init_server(&serv);
  if ((init_map(&serv.map, serv.map.width, serv.map.height)) == -1)
    return (-1);
  signal(SIGINT, sig_handler);
  launch_server(&serv);
  free_map(&serv.map);
  return (0);
}
