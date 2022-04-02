/*
** execute_client_demand.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_demand.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:21:45 2017 Loic Lopez
** Last update Fri Jun 30 14:51:15 2017 Eric Deschodt
*/

#include "server.h"

bool	lvl6_7(t_serv *server, t_client *current_client, bool erase)
{
  t_tile	tile;

  tile = server->map.field[current_client->pos_y][current_client->pos_x];
  if (how_many_players(server, current_client) == 6
      && tile.ressources[LINEMATE] >= 1
      && tile.ressources[DERAUMERE] >= 2
      && tile.ressources[SIBUR] >= 3
      && tile.ressources[PHIRAS] >= 1)
    {
      if (erase == true)
	{
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[LINEMATE] -= 1;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[DERAUMERE] -= 2;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[SIBUR] -= 3;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[PHIRAS] -= 1;
	}
      return (true);
    }
  return (false);
}

bool		lvl7_8(t_serv *server, t_client *cu_cli, bool erase)
{
  t_tile	tile;

  tile = server->map.field[cu_cli->pos_y][cu_cli->pos_x];
  if (how_many_players(server, cu_cli) == 6
      && tile.ressources[LINEMATE] >= 2 && tile.ressources[DERAUMERE] >= 2
      && tile.ressources[SIBUR] >= 2 && tile.ressources[MENDIANE] >= 2
      && tile.ressources[PHIRAS] >= 2 && tile.ressources[THYSTAME] >= 1)
    {
      if (erase == true)
	{
	  ARENA[cu_cli->pos_y][cu_cli->pos_x].ressources[LINEMATE] -= 2;
	  ARENA[cu_cli->pos_y][cu_cli->pos_x]
		  .ressources[DERAUMERE] -= 2;
	  ARENA[cu_cli->pos_y][cu_cli->pos_x]
		  .ressources[SIBUR] -= 2;
	  ARENA[cu_cli->pos_y][cu_cli->pos_x]
		  .ressources[MENDIANE] -= 2;
	  ARENA[cu_cli->pos_y][cu_cli->pos_x]
		  .ressources[PHIRAS] -= 2;
	  ARENA[cu_cli->pos_y][cu_cli->pos_x]
		  .ressources[THYSTAME] -= 1;
	}
      return (true);
    }
  return (false);
}

void	execute_incantation(t_serv *server,
			    t_client *current_client, char *cmd)
{
  (void)cmd;
  bool	(*check_lvl_functions[])(t_serv *, t_client *, bool) =
    {
      lvl1_2, lvl2_3, lvl3_4, lvl4_5, lvl5_6, lvl6_7, lvl7_8
    };
  if (check_lvl_functions[(int)current_client->lvl - 1]
      (server, current_client, true) == true)
    {
      dprintf(current_client->sd, "ok\n");
      current_client->lvl++;
    }
  else
    dprintf(current_client->sd, "ko\n");
}

void	execute_client_demand(t_serv *server,
				  t_client *current_client, char *cmd)
{
  void	(*server_functions[])(t_serv *, t_client *, char *) =
    {
      execute_forward, execute_right, execute_left, execute_look,
      execute_inventory, execute_broadcast_text, execute_connect_nbr,
      execute_fork, execute_eject, execute_take_object, execute_set_object,
      execute_incantation
    };
  server_functions[current_client->cmd](server, current_client, cmd);
}
