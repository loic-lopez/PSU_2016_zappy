/*
** print_graphical_modify_ressources.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/print_graphical_modify_ressources.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. juin 29 15:10:39 2017 Loic Lopez
** Last update Sun Jul  2 23:38:27 2017 pierre piazza
*/

#include "server.h"

void	print_graphical_modify_ressources(t_serv *server,
					      t_client *current_client,
						t_client *graph_client)
{
  char 		cmd[255];

  memset(cmd, 0, 255);
  sprintf(cmd, "bct %zu %zu\n",
	  current_client->pos_x, current_client->pos_y);
  execute_bct(server, graph_client, cmd);
}

void	print_all_graphical_modify_ressources(t_serv *server,
					      t_client *current_client)
{
  t_vector	*graph_clients;
  t_client	*graph_client;

  graph_clients = ((t_team *)server->teams->data)->clients;
  while (graph_clients != NULL)
    {
      graph_client = graph_clients->data;
      if (graph_client)
	print_graphical_modify_ressources(server,
					  current_client, graph_client);
      graph_clients = graph_clients->next;
    }
}

void	execute_pie(t_serv *server,
			t_client *current_client, int status)
{
  t_vector	*graph_clients;
  t_client	*graph_client;

  graph_clients = ((t_team *)server->teams->data)->clients;
  while (graph_clients != NULL)
    {
      graph_client = graph_clients->data;
      if (graph_client)
	dprintf(graph_client->sd, "pie %zu %zu %d\n",
		current_client->pos_x, current_client->pos_y, status);
      graph_clients = graph_clients->next;
    }
}

