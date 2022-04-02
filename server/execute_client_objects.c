/*
** execute_client_demand.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_demand.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:21:45 2017 Loic Lopez
** Last update Sun Jul  2 23:17:22 2017 pierre piazza
*/

#include "server.h"

int	find_which_ressource(char *cmd)
{
  char		*availables[7];
  int		i;

  i = -1;
  availables[0] = "Food";
  availables[1] = "Linemate";
  availables[2] = "Deraumere";
  availables[3] = "Sibur";
  availables[4] = "Mendiane";
  availables[5] = "Phiras";
  availables[6] = "Thystame";
  while (++i < 7)
    if (strcmp(cmd, availables[i]) == 0)
      return (i);
  return (-1);
}

void	print_graphical_take_object(t_serv *server,
				       t_client *current_client, size_t
				       ressource)
{
  t_vector	*graph_clients;
  t_client	*graph_client;

  graph_clients = ((t_team *)server->teams->data)->clients;
  while (graph_clients != NULL)
    {
      graph_client = graph_clients->data;
      if (graph_client)
	{
	  dprintf(graph_client->sd, "pgt %zu %zu\n",
		  current_client->id, ressource);
	  print_graphical_modify_ressources(server,
					    current_client, graph_client);
	}
      graph_clients = graph_clients->next;
    }
}

void	execute_take_object(t_serv *server,
			    t_client *current_client, char *cmd)
{
  int	res;

  if ((res = find_which_ressource(&cmd[5])) == -1)
    dprintf(current_client->sd, "ko\n");
  else
    {
      if ((server->map.field[current_client->pos_y]
	   [current_client->pos_x]).ressources[res] > 0)
	{
	  (server->map.field[current_client->pos_y]
	   [current_client->pos_x]).ressources[res]--;
	  current_client->inv.ressources[res]++;
	  dprintf(current_client->sd, "ok\n");
	  print_graphical_take_object(server, current_client, res);
	}
      else
	dprintf(current_client->sd, "ko\n");
    }
}

void	print_graphical_set_object(t_serv *server,
				   t_client *current_client,
				   size_t ressource)
{
  t_vector	*graph_clients;
  t_client	*graph_client;

  graph_clients = ((t_team *)server->teams->data)->clients;
  while (graph_clients != NULL)
    {
      graph_client = graph_clients->data;
      if (graph_client)
	{
	  dprintf(graph_client->sd, "pdr %zu %zu\n",
		  current_client->id, ressource);
	  print_graphical_modify_ressources(server,
					    current_client, graph_client);
	}
      graph_clients = graph_clients->next;
    }
}

void	execute_set_object(t_serv *server,
			   t_client *current_client, char *cmd)
{
  int 	is_ok;

  is_ok = find_which_ressource(&cmd[4]);
  if (is_ok == -1)
    dprintf(current_client->sd, "ko\n");
  else
    {
      if (current_client->inv.ressources[is_ok] > 0)
	{
	  current_client->inv.ressources[is_ok]--;
	  server->map.field[current_client->pos_y][current_client->pos_x]
	   .ressources[is_ok]++;
	  dprintf(current_client->sd, "ok\n");
	  print_graphical_set_object(server, current_client, is_ok);
	}
      else
	dprintf(current_client->sd, "ko\n");
    }
}
