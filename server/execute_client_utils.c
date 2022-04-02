/*
** execute_client_utils.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_utils.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:40:16 2017 Loic Lopez
** Last update Sun Jul  2 23:17:58 2017 pierre piazza
*/

#include "server.h"

void	execute_inventory(t_serv *server, t_client *current_client, char *cmd)
{
  (void)cmd;
  (void)server;
  dprintf(current_client->sd,
	  "[food %zu, linemate %zu, deraumere %zu, sibur %zu, mendiane %zu,"
	  " phiras %zu, thystame %zu]\n",
	  current_client->inv.ressources[FOOD],
	  current_client->inv.ressources[LINEMATE],
	  current_client->inv.ressources[DERAUMERE],
	  current_client->inv.ressources[SIBUR],
	  current_client->inv.ressources[MENDIANE],
	  current_client->inv.ressources[PHIRAS],
	  current_client->inv.ressources[THYSTAME]);
}

void	execute_connect_nbr(t_serv *server,
			    t_client *current_client, char *cmd)
{
  t_vector      *tmp_team;
  t_vector      *tmp_client;
  t_client      *client;

  tmp_team = server->teams->next;
  while (tmp_team)
    {
      tmp_client = ((t_team *)tmp_team->data)->clients;
      while (tmp_client)
        {
          client = ((t_client *)tmp_client->data);
	  if (client == current_client)
	    {
	      dprintf(current_client->sd, "%d\n",
		      (((t_team *)tmp_team->data)->nbr_clients_remaining));
	      return;
	    }
          tmp_client = tmp_client->next;
        }
      tmp_team = tmp_team->next;
    }
  (void)cmd;
}
