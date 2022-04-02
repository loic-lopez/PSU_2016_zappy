/*
** execute_client_demand.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_demand.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:21:45 2017 Loic Lopez
** Last update Sun Jul  2 22:46:46 2017 pierre piazza
*/

#include "server.h"

void		bump_client(t_client *client,
			    t_serv *server,
			    client_orientation orientation)
{
  void (*execute_forwards[])(t_serv *, t_client *) =
   {
    execute_forward_north, execute_forward_east,
    execute_forward_south, execute_forward_west
   };
  t_vector	*graph_clients;
  t_client	*graph_client;

  execute_forwards[orientation](server, client);
  dprintf(client->sd, "eject: %d\n", (int)orientation + 1);
  graph_clients = ((t_team *)server->teams->data)->clients;
  while (graph_clients != NULL)
    {
      graph_client = graph_clients->data;
      if (graph_client)
	dprintf(graph_client->sd, "pex %zu\n", client->id);
      graph_clients = graph_clients->next;
    }
}

bool		find_clients(t_vector *clients,
			     t_serv *server,
			     t_client *current_client)
{
  t_vector	*tmp_client;
  t_client	*client;
  bool		found;

  found = false;
  tmp_client = clients;
  while (tmp_client)
    {
      client = ((t_client *)tmp_client->data);
      if (client != current_client)
	{
	  if (client->pos_x == current_client->pos_x
	      && client->pos_y == current_client->pos_y)
	    {
	      found = true;
	      bump_client(client, server, current_client->orientation);
	    }
	}
      tmp_client = tmp_client->next;
    }
  return (found);
}

void		execute_eject(t_serv *server,
			      t_client *current_client, char *cmd)
{
  t_vector	*tmp_team;
  bool		found;

  found = false;
  (void)cmd;
  tmp_team = server->teams->next;
  while (tmp_team)
    {
      if ((find_clients(((t_team *)tmp_team->data)->clients,
			server, current_client)) == true)
	found = true;
      tmp_team = tmp_team->next;
    }
  if (found == true)
    dprintf(current_client->sd, "ok\n");
  else
    dprintf(current_client->sd, "ko\n");
}
