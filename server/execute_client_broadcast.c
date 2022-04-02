/*
** execute_client_utils.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_utils.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:40:16 2017 Loic Lopez
** Last update Sat Jul  1 16:59:03 2017 Stanislas Deneubourg
*/

#include "server.h"

int		compare_and_choose_destination(int *distance)
{
  int		i;
  int		min;
  int		found;

  i = 0;
  found = 0;
  while (i < 8 && distance[i] == -1)
    {
      if (distance[i] != -1)
	min = distance[i];
      i++;
    }
  i = 0;
  while (i < 8)
    {
      if (distance[i] != -1 && distance[i] < min)
	{
	  found = i;
	  min = distance[i];
	}
      i++;
    }
  return (found + 1);
}

int		send_wave(t_pos destination,
			  t_serv *server)
{
  int		distance[8];
  int		i;

  i = 0;
  while (i < 8)
    distance[i++] = -1;
  vertical_search(destination, server, distance);
  horizontal_search(destination, server, distance);
  diagonal_left_up_earch(destination, server, distance);
  diagonal_right_up_earch(destination, server, distance);
  diagonal_left_down_earch(destination, server, distance);
  diagonal_right_down_earch(destination, server, distance);
  return (compare_and_choose_destination(distance));
}

int	find_origin_sound(t_client *current_client,
			  t_client *client,
			  t_serv *server)
{
  t_pos destination;

  init_map_sound(server, client);
  if (ARENA[current_client->pos_y][current_client->pos_x].sound == -1)
    ARENA[current_client->pos_y][current_client->pos_x].sound = 0;
  else
    return (ARENA[current_client->pos_y][current_client->pos_x].sound);
  destination.x = client->pos_x;
  destination.y = client->pos_y;
  return (send_wave(destination, server));
}

void	print_broadcast_on_graphic_clients(t_serv *server,
					       t_client *current_client,
					       char *message)
{
  t_vector	*graph_clients;
  t_client	*graph_client;

  graph_clients = ((t_team *)server->teams->data)->clients;
  while (graph_clients != NULL)
    {
      graph_client = graph_clients->data;
      if (graph_client)
	{
	  dprintf(graph_client->sd, "pbc %zu %s\n",
		  current_client->id, message);
	}
      graph_clients = graph_clients->next;
    }
}

void	execute_broadcast_text(t_serv *server,
			       t_client *current_client, char *cmd)
{
  t_vector      *tmp_team;
  t_vector      *tmp_client;
  t_client      *client;

  print_broadcast_on_graphic_clients(server, current_client, &cmd[10]);
  tmp_team = server->teams->next;
  while (tmp_team)
    {
      tmp_client = ((t_team *)tmp_team->data)->clients;
      while (tmp_client)
        {
          client = ((t_client *)tmp_client->data);
          if (client != current_client)
	    {
	      dprintf(client->sd, "message %d, %s\n",
		      find_origin_sound(current_client, client, server),
		      &cmd[10]);
	    }
          tmp_client = tmp_client->next;
        }
      tmp_team = tmp_team->next;
    }
  dprintf(current_client->sd, "ok\n");
}
