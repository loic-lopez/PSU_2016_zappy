/*
** server.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/server.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 15:45:05 2017 Loic Lopez
** Last update Sat Jul  1 16:54:25 2017 Stanislas Deneubourg
*/

#include "server.h"

#ifndef PUT_IN_EGG
# define PUT_IN_EGG put_client_in_team_if_not_egg_delay
#endif

void	incomming_connection(t_serv *server)
{
  int 		new_client_socket;
  char 		data[255];
  bool		team_found;

  memset(data, 0, 255);
  team_found = false;
  if (FD_ISSET(server->master_socket, &server->rs))
    {
      if ((new_client_socket =
	   accept(server->master_socket,
		  (struct sockaddr *)&server->addr,
		  (socklen_t*)&server->addrlen)) < 0)
	return;
      send(new_client_socket, "WELCOME\n", 8, 0);
      recv(new_client_socket, data, 255, 0);
      data[strlen(data) - 1] = 0;
      if (strcmp("GRAPHIC", data) == 0)
	add_graphical_user(server, new_client_socket);
      else
	{
	  add_user(server, &team_found, data, new_client_socket);
	  if (!team_found)
	    close(new_client_socket);
	}
    }
}

void	loop_on_team(t_serv *server)
{
  t_vector	*tmp_teams;
  t_vector	*tmp_clients;
  t_client	*client;

  tmp_teams = server->teams;
  while (tmp_teams != NULL)
    {
      tmp_clients = ((t_team *)tmp_teams->data)->clients;
      while (tmp_clients != NULL)
	{
	  client = ((t_client *)tmp_clients->data);
	  if (client->sd > 0)
	    FD_SET(client->sd, &server->rs);
	  if (client->sd > server->max_sd)
	    server->max_sd = client->sd;
	  tmp_clients = tmp_clients->next;
	}
      tmp_teams = tmp_teams->next;
    }
}

void			clients_actions(t_serv *server)
{
  t_vector		*tmp_client;
  t_vector		*tmp_team;
  t_client		*client;
  char 			cmd[255];

  tmp_team = server->teams;
  memset(cmd, 0, 255);
  while (tmp_team != NULL)
    {
      tmp_client = ((t_team *)tmp_team->data)->clients;
      while (tmp_client != NULL)
	{
	  client = ((t_client *)tmp_client->data);
	  if (FD_ISSET(client->sd, &server->rs))
	    {
	      recv(client->sd, cmd, 255, 0);
	      (client->is_graphical_client) ?
		launch_graphical_client_demand(server, client, cmd) :
		launch_client_demand(server, client, cmd);
	      break ;
	    }
	  tmp_client = tmp_client->next;
	}
      tmp_team = tmp_team->next;
    }
}

void	launch_server(t_serv *server)
{
  int			activity;
  struct timeval	delay;
  struct timespec	end;
  struct timespec	start;
  int			cooldown;

  cooldown = 0;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  wait_clients(server);
  while (sig_ret)
    {
      clock_gettime(CLOCK_MONOTONIC_RAW, &end);
      if (check_timer(end, start, server))
	{
	  init_gettime(&start, &delay, server);
	  if ((activity = select(server->max_sd + 1, &server->rs,
				 &server->ws, &server->es, &delay)) == -1)
	    break ;
	  activity >= 0 && errno != EINTR ?
	    (incomming_connection(server), clients_actions(server),
	     update_client_delay(server), PUT_IN_EGG(server),
	     update_cooldown(&cooldown, server)): 0;
	}
    }
  killall(server);
}
