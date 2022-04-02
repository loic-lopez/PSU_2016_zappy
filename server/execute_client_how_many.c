/*
** execute_client_demand.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_demand.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:21:45 2017 Loic Lopez
** Last update Wed Jun 28 17:25:02 2017 pierre piazza
*/

#include "server.h"

int	        find_lvl_clients(t_vector *clients,
				 t_client *current_client)
{
  t_vector      *tmp_client;
  t_client      *client;
  int		result;

  result = 0;
  tmp_client = clients;
  while (tmp_client)
    {
      client = ((t_client *)tmp_client->data);
      if (client->lvl == current_client->lvl
	  && client->pos_x == current_client->pos_x
	  && client->pos_y == current_client->pos_y)
	result++;
      tmp_client = tmp_client->next;
    }
  return (result);
}

int		how_many_players(t_serv *server,
				 t_client *current_client)
{
  t_vector      *tmp_team;
  int		result;

  result = 0;
  tmp_team = server->teams->next;
  while (tmp_team)
    {
      result += find_lvl_clients(((t_team *)tmp_team->data)->clients,
				 current_client);
      tmp_team = tmp_team->next;
    }
  return (result);
}
