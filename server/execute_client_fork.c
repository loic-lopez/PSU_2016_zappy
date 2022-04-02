/*
** execute_client_utils.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_utils.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:40:16 2017 Loic Lopez
** Last update Sun Jul  2 22:53:48 2017 pierre piazza
*/

#include "server.h"

void    add_eggs(t_team *team, t_client *current_client, t_serv *server)
{
  t_egg    *new_egg;
  t_vector	*graph_clients;
  t_client	*graph_client;

  if ((new_egg = malloc(sizeof(t_egg))) != NULL)
    {
      new_egg->pos_x = current_client->pos_x;
      new_egg->pos_y = current_client->pos_y;
      new_egg->delay = 300;
      graph_clients = ((t_team *)server->teams->data)->clients;
      while (graph_clients != NULL)
	{
	  graph_client = graph_clients->data;
	  if (graph_client)
	    dprintf(graph_client->sd, "pfk %zu\n", current_client->id);
	  graph_clients = graph_clients->next;
	}
      push_back(&team->eggs, new_egg);
    }
}

void    execute_fork(t_serv *server, t_client *current_client, char *cmd)
{
  t_vector      *tmp_team;
  t_vector      *tmp_client;
  t_client      *client;

  (void)cmd;
  tmp_team = server->teams->next;
  while (tmp_team)
    {
      tmp_client = ((t_team *)tmp_team->data)->clients;
      while (tmp_client)
        {
          client = ((t_client *)tmp_client->data);
          if (client == current_client)
            {
              dprintf(current_client->sd, "ok\n");
	      add_eggs(((t_team *)tmp_team->data), current_client, server);
              return;
            }
          tmp_client = tmp_client->next;
        }
      tmp_team = tmp_team->next;
    }
}
