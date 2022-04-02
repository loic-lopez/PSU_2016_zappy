/*
** server.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/server.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 15:45:05 2017 Loic Lopez
** Last update Sat Jul  1 16:54:43 2017 Stanislas Deneubourg
*/

#include "server.h"

void	set_fds(t_serv *server)
{
  FD_ZERO(&server->rs);
  FD_SET(server->master_socket, &server->rs);
  FD_ZERO(&server->ws);
  FD_SET(server->master_socket, &server->ws);
  FD_ZERO(&server->es);
  FD_SET(server->master_socket, &server->es);
}

void	update_cooldown(int *cooldown, t_serv *server)
{
  (*cooldown)++;
  if (*cooldown == 28)
    {
      *cooldown = 0;
      spawn_ressources(server);
    }
}

void	init_gettime(struct timespec *start,
		     struct timeval *delay,
		     t_serv *server)
{
  clock_gettime(CLOCK_MONOTONIC_RAW, start);
  delay->tv_usec = 900000 / server->freq;
  delay->tv_sec = 0;
  set_fds(server);
  server->max_sd = server->master_socket;
  loop_on_team(server);
}

bool	check_timer(struct timespec end,
		    struct timespec start, t_serv *server)
{
  return (((end.tv_sec - start.tv_sec) * 1000000
	   + (end.tv_nsec - start.tv_nsec) / 1000) >= 1000000 / server->freq);
}
