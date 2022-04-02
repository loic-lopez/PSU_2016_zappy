/*
** print_info_graphic_clients.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/print_info_graphic_clients.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. juin 29 12:54:44 2017 Loic Lopez
** Last update Fri Jun 30 15:06:44 2017 Eric Deschodt
*/

#include "server.h"

void	print_infos_on_graphic_clients(t_client *new_client,
					   t_serv *server, t_team *team)
{
  t_vector	*tmp_client;
  t_client	*client;
  t_vector	*tmp_team;

  tmp_team = server->teams;
  tmp_client = ((t_team *)tmp_team->data)->clients;
  while (tmp_client)
    {
      client = ((t_client *)tmp_client->data);
      dprintf(client->sd, "pnw %zu %zu %zu %zu %d %s\n",
	      new_client->id, new_client->pos_x, new_client->pos_y,
	      (size_t)(new_client->orientation + 1), new_client->lvl,
	      team->name);
      tmp_client = tmp_client->next;
    }
}

void	print_team(t_vector *teams, t_client *graph_client)
{
  t_vector	*clients;
  t_client	*client;

  while (teams != NULL)
    {
      clients = ((t_team *)teams->data)->clients;
      while (clients != NULL)
	{
	  client = clients->data;
	  dprintf(graph_client->sd, "pnw %zu %zu %zu %zu %d %s\n",
		  client->id, client->pos_x, client->pos_y,
		  (size_t)(client->orientation + 1), client->lvl,
		  ((t_team *)teams->data)->name);
	  clients = clients->next;
	}
      teams = teams->next;
    }
}

void	print_graphic_connected_clients(t_serv *server, t_client *new_client)
{
  t_vector	*teams;

  if (server->teams->data == NULL)
    return;
  teams = server->teams->next;
  print_team(teams, new_client);
}
