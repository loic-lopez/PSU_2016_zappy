/*
** execute_client_demand.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_demand.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:21:45 2017 Loic Lopez
** Last update Sun Jul  2 23:06:59 2017 pierre piazza
*/

#include "server.h"

bool	lvl1_2(t_serv *server, t_client *current_client, bool erase)
{
  t_tile	tile;

  tile = server->map.field[current_client->pos_y][current_client->pos_x];
  if (how_many_players(server, current_client) == 1
      && tile.ressources[LINEMATE] >= 1)
    {

      if (erase == true)
	{
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[LINEMATE] -= 1;
	  print_all_graphical_modify_ressources(server, current_client);
	  execute_pie(server, current_client, 1);
	}
      return (true);
    }
  execute_pie(server, current_client, 0);
  return (false);
}

bool	lvl2_3(t_serv *server, t_client *current_client, bool erase)
{
  t_tile	tile;

  tile = server->map.field[current_client->pos_y][current_client->pos_x];
  if (how_many_players(server, current_client) == 2
      && tile.ressources[LINEMATE] >= 1
      && tile.ressources[DERAUMERE] >= 1
      && tile.ressources[SIBUR] >= 1)
    {
      if (erase == true)
	{
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[LINEMATE] -= 1;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[DERAUMERE] -= 1;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[SIBUR] -= 1;
	  print_all_graphical_modify_ressources(server, current_client);
	  execute_pie(server, current_client, 1);
	}
      return (true);
    }
  execute_pie(server, current_client, 0);
  return (false);
}

bool	lvl3_4(t_serv *server, t_client *current_client, bool erase)
{
  t_tile	tile;

  tile = server->map.field[current_client->pos_y][current_client->pos_x];
  if (how_many_players(server, current_client) == 2
      && tile.ressources[LINEMATE] >= 2
      && tile.ressources[SIBUR] >= 1
      && tile.ressources[PHIRAS] >= 2)
    {
      if (erase == true)
	{
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[LINEMATE] -= 2;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[SIBUR] -= 1;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[PHIRAS] -= 2;
	  print_all_graphical_modify_ressources(server, current_client);
	  execute_pie(server, current_client, 1);
	}
      return (true);
    }
  execute_pie(server, current_client, 0);
  return (false);
}

bool	lvl4_5(t_serv *server, t_client *current_client, bool erase)
{
  t_tile	tile;

  tile = server->map.field[current_client->pos_y][current_client->pos_x];
  if (how_many_players(server, current_client) == 4
      && tile.ressources[LINEMATE] >= 1 && tile.ressources[DERAUMERE] >= 1
      && tile.ressources[SIBUR] >= 2 && tile.ressources[PHIRAS] >= 1)
    {
      if (erase == true)
	{
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[LINEMATE] -= 1;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[DERAUMERE] -= 1;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[SIBUR] -= 2;
	  server->map.field[current_client->pos_y][current_client->pos_x]
		  .ressources[PHIRAS] -= 1;
	  print_all_graphical_modify_ressources(server, current_client);
	  execute_pie(server, current_client, 1);
	}
      return (true);
    }
  execute_pie(server, current_client, 0);
  return (false);
}

bool	lvl5_6(t_serv *server, t_client *current_client, bool erase)
{
  t_tile	tile;

  tile = server->map.field[current_client->pos_y][current_client->pos_x];
  if (how_many_players(server, current_client) == 4
      && tile.ressources[LINEMATE] >= 1 && tile.ressources[DERAUMERE] >= 2
      && tile.ressources[SIBUR] >= 1 && tile.ressources[MENDIANE] >= 3)
    {
      if (erase == true)
	{
	  server->map.field[current_client->pos_y][current_client->pos_x]
	    .ressources[LINEMATE] -= 1;
	  server->map.field[current_client->pos_y][current_client->pos_x]
	    .ressources[DERAUMERE] -= 2;
	  server->map.field[current_client->pos_y][current_client->pos_x]
	    .ressources[SIBUR] -= 1;
	  server->map.field[current_client->pos_y][current_client->pos_x]
	    .ressources[MENDIANE] -= 3;
	  print_all_graphical_modify_ressources(server, current_client);
	  execute_pie(server, current_client, 1);
	}
      return (true);
    }
  execute_pie(server, current_client, 0);
  return (false);
}
