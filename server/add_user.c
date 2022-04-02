/*
** server.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/server.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 15:45:05 2017 Loic Lopez
** Last update Thu Jun 29 14:12:45 2017 Eric Deschodt
*/

#include "server.h"

void	init_fields_clients(t_client *new_client,
			    t_serv *server, t_team *team)
{
  int	i;

  i = 0;
  new_client->id = ++(server->max_id);
  new_client->lvl = 1;
  new_client->pos_x = rand() % server->map.width;
  new_client->pos_y = rand() % server->map.height;
  new_client->orientation = (client_orientation) (rand() % 4);
  new_client->cmds = NULL;
  server->map.field[new_client->pos_y][new_client->pos_x].player++;
  new_client->inv.ressources[i++] = 1260;
  while (i < 7)
    new_client->inv.ressources[i++] = 0;
  team->nbr_clients_remaining--;
  print_infos_on_graphic_clients(new_client, server, team);
  push_back(&team->clients, new_client);
}

void	check_user_and_remaining_clients(t_vector *tmp, t_client *new_client,
					     t_serv *server)
{
  if (((t_team *)tmp->data)->nbr_clients_remaining == 0)
    push_back(&((t_team *) tmp->data)->clients_waiting, new_client);
  else
    init_fields_clients(new_client, server, ((t_team *)tmp->data));
}

void	add_graphical_user(t_serv *server, int new_client_socket)
{
  t_client	*new_client;

  if ((new_client = malloc(sizeof(t_client))) == NULL)
    return;
  new_client->sd = new_client_socket;
  new_client->is_graphical_client = true;
  execute_msz(server, new_client, NULL);
  execute_sgt(server, new_client, NULL);
  execute_mct(server, new_client, NULL);
  execute_tna(server, new_client, NULL);
  print_graphic_connected_clients(server, new_client);
  push_back(&((t_team *)server->teams->data)->clients, new_client);
}

void	add_user(t_serv *server, bool *team_found, char *team_name,
		 int new_client_socket)
{
  t_client	*new_client;
  t_vector	*tmp;

  tmp = server->teams->next;
  while (tmp != NULL)
    {
      if (strcmp(((t_team *)tmp->data)->name, team_name) == 0)
	{
	  if ((new_client = malloc(sizeof(t_client))) == NULL)
	    break;
	  *team_found = true;
	  new_client->sd = new_client_socket;
	  new_client->is_graphical_client = false;
	  check_user_and_remaining_clients(tmp, new_client, server);
	  dprintf(new_client->sd, "%d\n",
		  ((t_team *)tmp->data)->nbr_clients_remaining);
	  dprintf(new_client->sd, " %zu %zu\n", server->map.width,
		  server->map.height);
	  break;
	}
      tmp = tmp->next;
    }
}
