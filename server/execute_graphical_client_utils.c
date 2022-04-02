/*
** execute_graphical_client_utils.c for  in /home/descho_e/tek2/PSU_2016_zappy/server
** 
** Made by Eric Deschodt
** Login   <descho_e@epitech.net>
** 
** Started on  Fri Jun 30 15:03:08 2017 Eric Deschodt
** Last update Fri Jun 30 15:04:54 2017 Eric Deschodt
*/

#include "server.h"

void	execute_msz(t_serv *server, t_client *current_client, char *cmd)
{
  (void)cmd;
  dprintf(current_client->sd, "msz %zu %zu\n", server->map.width,
	  server->map.height);
}

void	execute_bct(t_serv *server, t_client *current_client, char *cmd)
{
  size_t x;
  size_t y;
  int 	i;

  i = 0;
  while (cmd[i] && cmd[i] != ' ')
    i++;
  i++;
  x = atoi(&cmd[i]);
  while (cmd[i] && cmd[i] != ' ')
    i++;
  i++;
  y = atoi(&cmd[i]);
  dprintf(current_client->sd,
	  "bct %zu %zu %zu %zu %zu %zu %zu %zu %zu\n", x, y,
	  ARENA[y][x].ressources[FOOD],
	  ARENA[y][x].ressources[LINEMATE],
	  ARENA[y][x].ressources[DERAUMERE],
	  ARENA[y][x].ressources[SIBUR],
	  ARENA[y][x].ressources[MENDIANE],
	  ARENA[y][x].ressources[PHIRAS],
	  ARENA[y][x].ressources[THYSTAME]);
}

void	execute_mct(t_serv *server, t_client *current_client, char *cmd)
{
  size_t x;
  size_t y;

  (void)cmd;
  y = 0;
  while (y < server->map.height)
    {
      x = 0;
      while (x < server->map.width)
	{
	  dprintf(current_client->sd,
		  "bct %zu %zu %zu %zu %zu %zu %zu %zu %zu\n", x, y,
		  ARENA[y][x].ressources[FOOD],
		  ARENA[y][x].ressources[LINEMATE],
		  ARENA[y][x].ressources[DERAUMERE],
		  ARENA[y][x].ressources[SIBUR],
		  ARENA[y][x].ressources[MENDIANE],
		  ARENA[y][x].ressources[PHIRAS],
		  ARENA[y][x].ressources[THYSTAME]);
	  x++;
	}
      y++;
    }
}

void	execute_tna(t_serv *server, t_client *current_client, char *cmd)
{
  t_vector	*tmp_team;

  (void)cmd;
  tmp_team = server->teams->next;
  while (tmp_team != NULL)
    {
      dprintf(current_client->sd, "tna %s\n",
	      ((t_team *)tmp_team->data)->name);
      tmp_team = tmp_team->next;
    }
}

void	execute_pic(t_serv *server, t_client *current_client)
{
  t_vector	*graph_clients;
  t_client	*graph_client;

  graph_clients = ((t_team *)server->teams->data)->clients;
  while (graph_clients != NULL)
    {
      graph_client = graph_clients->data;
      if (graph_client)
	dprintf(graph_client->sd, "pic %zu %zu %d %zu\n",
		current_client->pos_x, current_client->pos_y,
		current_client->lvl, current_client->id);
      graph_clients = graph_clients->next;
    }
}
