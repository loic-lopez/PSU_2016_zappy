/*
** execute_client_looking.c for PSU_2016_zappy in /home/dupil_l/PSU_2016_zappy/execute_client_looking.c
**
** Made by Loic Dupil
** Login   <loic.dupil@epitech.eu>
**
** Started on  Thu Jun 22 10:10:20 2017 Loic Dupil
** Last update Sun Jul  2 23:16:29 2017 pierre piazza
*/

#include "server.h"

void 	list_elem(size_t thing, char *elem, t_client *client)
{
  size_t i;

  i = 0;
  while (++i <= thing)
    dprintf(client->sd, " %s", elem);
}

void 	check_tile(t_tile pos, t_client *current_client)
{
  if (pos.player >= 1)
    list_elem(pos.player, "player", current_client);
  if (pos.ressources[FOOD] >= 1)
    list_elem(pos.ressources[FOOD], "food", current_client);
  if (pos.ressources[LINEMATE] >= 1)
    list_elem(pos.ressources[LINEMATE], "linemate", current_client);
  if (pos.ressources[DERAUMERE] >= 1)
    list_elem(pos.ressources[DERAUMERE], "deraumere", current_client);
  if (pos.ressources[SIBUR] >= 1)
    list_elem(pos.ressources[SIBUR], "sibur", current_client);
  if (pos.ressources[MENDIANE] >= 1)
    list_elem(pos.ressources[MENDIANE], "mendiane", current_client);
  if (pos.ressources[PHIRAS] >= 1)
    list_elem(pos.ressources[PHIRAS], "phiras", current_client);
  if (pos.ressources[THYSTAME] >= 1)
    list_elem(pos.ressources[THYSTAME], "thystame", current_client);
  dprintf(current_client->sd, ",");
}

void	browse_tiles(t_serv *server, t_client *client, size_t i)
{
  int j;

  if (client->orientation == NORTH)
    {
      j = (int)(client->pos_x - i - 1);
      while (++j <= (int)(client->pos_x + i))
	check_tile(server->map.field
		   [(client->pos_y - i + server->map.height)
		    % server->map.height]
		   [(j + server->map.width) % server->map.width], client);
    }
  else
    {
      j = (int)(client->pos_x + i + 1);
      while (--j >= (int)(client->pos_x - i))
	check_tile(server->map.field
		   [(client->pos_y + i + server->map.height)
		    % server->map.height]
		   [(j + server->map.width) % server->map.width], client);
    }
}

void	execute_look_hor(t_serv *server, t_client *client)
{
  size_t i;
  int 	j;

  i = 0;
  while ((short)++i <= client->lvl)
    {
      if (client->orientation == EAST)
	{
	  j = (int)(client->pos_y - i - 1);
	  while (++j <= (int)(client->pos_y + i))
	    check_tile(server->map.field
		       [(j + server->map.height) % server->map.height]
		       [(client->pos_x + i + server->map.width)
			% server->map.width], client);
	}
      else
	{
	  j = (int)(client->pos_y + i + 1);
	  while (--j >= (int)(client->pos_y - i))
	    check_tile(server->map.field
		       [(j + server->map.height) % server->map.height]
		       [(client->pos_x - i + server->map.width)
			% server->map.width], client);
	}
    }
}

void	execute_look(t_serv *server, t_client *current_client, char *cmd)
{
  size_t i;

  (void)cmd;
  dprintf(current_client->sd, "[");
  check_tile(server->map.field[current_client->pos_y][current_client->pos_x],
	     current_client);
  if (current_client->orientation == EAST
      || current_client->orientation == WEST)
    execute_look_hor(server, current_client);
  else
    {
      i = 0;
      while ((short)++i <= current_client->lvl)
	{
	  browse_tiles(server, current_client, i);
	}
    }
  dprintf(current_client->sd, "]\n");
}
