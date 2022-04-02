/*
** put_client_in_team_if_not_egg_delay.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/put_client_in_team_if_not_egg_delay.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  ven. juin 23 16:08:43 2017 Loic Lopez
** Last update Fri Jun 30 15:09:41 2017 Eric Deschodt
*/

#include "server.h"

void	init_fields_client_in_egg(t_client *new_client,
				  t_egg **egg,
				  t_serv *server)
{
  int	i;

  i = 0;
  new_client->id = ++(server->max_id);
  new_client->pos_y = (*egg)->pos_y;
  new_client->pos_x = (*egg)->pos_x;
  new_client->inv.ressources[i++] = 1260;
  while (i < 7)
    new_client->inv.ressources[i++] = 0;
  new_client->orientation = (client_orientation) (rand() % 4);
  new_client->cmds = NULL;
  new_client->lvl = 1;
}

void	put_client_in_team_if_not_egg_delay(t_serv *server)
{
  t_vector	*tmp_team;
  t_egg		*egg;
  t_vector	*eggs;
  t_client	*client_waiting;

  tmp_team = server->teams->next;
  while (tmp_team != NULL)
    {
      eggs = ((t_team *)tmp_team->data)->eggs;
      if (eggs != NULL && eggs->data != NULL)
	{
	  egg = get_elem_index(eggs, 0);
	  client_waiting = get_elem_index
	    (((t_team *)tmp_team->data)->clients_waiting, 0);
	  if (egg != NULL && client_waiting != NULL && egg->delay == 0)
	    {
	      init_fields_client_in_egg(client_waiting, &egg, server);
	      push_back(&((t_team *)tmp_team->data)->clients, client_waiting);
	      erase(&((t_team *)tmp_team->data)->eggs, 0, NULL);
	      erase(&((t_team *)tmp_team->data)->clients_waiting, 0, NULL);
	      ARENA[client_waiting->pos_y][client_waiting->pos_x].player++;
	    }
	}
      tmp_team = tmp_team->next;
    }
}
