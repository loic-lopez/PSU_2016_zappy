/*
** execute_graphical_client_position.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_graphical_client_position.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  mar. juin 27 14:31:12 2017 Loic Lopez
** Last update Fri Jun 30 14:54:57 2017 Eric Deschodt
*/

#include "server.h"

void	execute_plv(t_serv *server, t_client *cu_client, char *cmd)
{
  t_vector	*tmp_team;
  t_vector	*tmp_client;
  t_client	*client;
  size_t 	client_to_found;
  int 		i;

  i = -1;
  while (cmd[++i] && cmd[i] != '\n');
  client_to_found = (size_t)atoi(&cmd[--i]);
  tmp_team = server->teams->next;
  while (tmp_team != NULL)
    {
      tmp_client = tmp_team->data;
      while (tmp_client)
	{
	  client = tmp_client->data;
	  if (client->id == client_to_found)
	    {
	      dprintf(cu_client->sd, "plv %zu %d\n", client->id, client->lvl);
	      break;
	    }
	  tmp_client = tmp_client->next;
	}
      tmp_team = tmp_team->next;
    }
}

void	execute_pin_print(t_client *current_client, t_client *client_found)
{
  dprintf(current_client->sd,
	  "pin %zu %zu %zu %zu %zu %zu %zu %zu %zu %zu\n",
	  client_found->id, client_found->pos_x, client_found->pos_y,
	  client_found->inv.ressources[FOOD],
	  client_found->inv.ressources[LINEMATE],
	  client_found->inv.ressources[DERAUMERE],
	  client_found->inv.ressources[SIBUR],
	  client_found->inv.ressources[MENDIANE],
	  client_found->inv.ressources[PHIRAS],
	  client_found->inv.ressources[THYSTAME]);
}

void	execute_pin(t_serv *server, t_client *current_client, char *cmd)
{
  t_vector	*tmp_team;
  t_vector	*tmp_client;
  t_client	*client;
  size_t 	client_to_found;
  int 		i;

  i = -1;
  while (cmd[++i] && cmd[i] != '\n');
  client_to_found = (size_t)atoi(&cmd[--i]);
  tmp_team = server->teams->next;
  while (tmp_team != NULL)
    {
      tmp_client = tmp_team->data;
      while (tmp_client)
	{
	  client = tmp_client->data;
	  if (client->id == client_to_found)
	    {
	      execute_pin_print(current_client, client);
	      break;
	    }
	  tmp_client = tmp_client->next;
	}
      tmp_team = tmp_team->next;
    }
}
