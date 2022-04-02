/*
** wait_clients.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/wait_clients.c
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  ven. juin 30 17:01:28 2017 Loïc Lopez
** Last update Sat Jul  1 16:51:56 2017 Stanislas Deneubourg
*/

#include "server.h"

void	only_client_actions(t_serv *server)
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
	      if (client->is_graphical_client)
		launch_graphical_client_demand(server, client, cmd);
	      break ;
	    }
	  tmp_client = tmp_client->next;
	}
      tmp_team = tmp_team->next;
    }
}

void	for_ai(t_serv *server)
{
  t_vector		*tmp_client;
  t_vector		*tmp_team;
  t_client		*client;

  tmp_team = server->teams->next;
  while (tmp_team != NULL)
    {
      tmp_client = ((t_team *)tmp_team->data)->clients;
      while (tmp_client != NULL)
	{
	  client = ((t_client *)tmp_client->data);
	  if (client)
	    dprintf(client->sd, "str\n");
	  tmp_client = tmp_client->next;
	}
      tmp_team = tmp_team->next;
    }
}

int 	get_max_nbr_team(t_serv *server)
{
  t_vector		*tmp_team;
  int 			max_nbr_team;

  tmp_team = server->teams->next;
  max_nbr_team = 0;
  while (tmp_team != NULL)
    {
      max_nbr_team++;
      tmp_team = tmp_team->next;
    }
  return (max_nbr_team);
}

void	print_start_game(t_serv *server)
{
  t_vector	*graph_clients;
  t_client	*client;

  graph_clients = ((t_team *)server->teams->data)->clients;
  while (graph_clients != NULL)
    {
      client = graph_clients->data;
      if (client)
	dprintf(client->sd, "str\n");
      graph_clients = graph_clients->next;
    }
}

void	wait_clients(t_serv *server)
{
  int			activity;
  int 			max_nbr_team;

  spawn_ressources(server);
  max_nbr_team = get_max_nbr_team(server);
  while (sig_ret)
    {
      if (max_nbr_team * server->max_clients_per_team == (int)server->max_id)
	break;
      set_fds(server);
      server->max_sd = server->master_socket;
      loop_on_team(server);
      if ((activity = select(server->max_sd + 1, &server->rs,
			     &server->ws, &server->es, NULL)) == -1)
	break ;
      if (activity >= 0 && errno != EINTR)
	{
	  incomming_connection(server);
	  only_client_actions(server);
	}
    }
  print_start_game(server);
  for_ai(server);
}
