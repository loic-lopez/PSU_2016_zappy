/*
** execute_graphical_client_position.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_graphical_client_position.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  mar. juin 27 14:31:12 2017 Loic Lopez
** Last update Fri Jun 30 14:54:38 2017 Eric Deschodt
*/

#include "server.h"

void	execute_ppo_print(t_client *current_client, t_client *client)
{
  dprintf(current_client->sd, "ppo %zu %zu %zu %zu\n",
	  client->id, client->pos_x, client->pos_y,
	  (size_t )(client->orientation + 1));
}

void            find_ppo_clients(t_vector *clients,
				 t_serv *server,
				 size_t client_to_found,
				 t_client *current)
{
  t_vector      *tmp_client;
  t_client      *client;
  (void) server;

  tmp_client = clients;
  while (tmp_client)
    {
      client = ((t_client *)tmp_client->data);
      if (client->id == client_to_found)
	{
	  execute_ppo_print(current, client);
	  break;
	}
      tmp_client = tmp_client->next;
    }
}

void	execute_ppo(t_serv *server, t_client *current_client, char *cmd)
{
  t_vector	*tmp_team;
  size_t	 client_to_found;
  int 		i;
  (void)server;

  i = -1;
  while (cmd[++i] && cmd[i] != '\n');
  client_to_found = (size_t)atoi(&cmd[--i]);
  tmp_team = server->teams->next;
  while (tmp_team != NULL)
    {
      find_ppo_clients(((t_team *)tmp_team->data)->clients,
		      server, client_to_found, current_client);
      tmp_team = tmp_team->next;
    }
}
