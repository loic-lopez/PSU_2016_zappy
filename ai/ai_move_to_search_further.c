/*
** ai_move_to_search_forward.c for move to search forward in /home/deneub_s/PSU_2016_zappy
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Mon Jun 26 14:41:34 2017 Stanislas Deneubourg
** Last update Sat Jul  1 14:51:57 2017 Stanislas Deneubourg
*/

#include "ai.h"

void	move_farther_than_view_range_to_search_further(t_client *client)
{
  size_t	i;
  char		*server_answer;

  i = 0;
  while (i <= client->level)
    {
      dprintf(client->sd, "%s\n", "Forward");
      if ((server_answer = get_next_line(client->sd)) != NULL)
	{
	  if (strcmp(server_answer, "ok") == 0)
	    free(server_answer);
	}
      i++;
    }
}

void	turn_left_front_to_object(t_client *client, int pos)
{
  int	diff_distance_in_list;
  char	*server_answer;

  dprintf(client->sd, "%s\n", "Left");
  if ((server_answer = get_next_line(client->sd)) != NULL)
    {
      if (strcmp(server_answer, "ok") == 0)
	free(server_answer);
    }
  diff_distance_in_list = client->look->coor - pos;
  while (diff_distance_in_list > 0)
    {
      dprintf(client->sd, "%s\n", "Forward");
      if ((server_answer = get_next_line(client->sd)) != NULL)
	{
	  if (strcmp(server_answer, "ok") == 0)
	    free(server_answer);
	}
      client->look = client->look->prev;
      diff_distance_in_list--;
    }
}

void	turn_right_front_to_object(t_client *client, int pos)
{
  int   diff_distance_in_list;
  char  *server_answer;

  dprintf(client->sd, "%s\n", "Right");
  if ((server_answer = get_next_line(client->sd)) != NULL)
    {
      if (strcmp(server_answer, "ok") == 0)
	free(server_answer);
    }
  diff_distance_in_list = pos - client->look->coor;
  while (diff_distance_in_list > 0)
    {
      dprintf(client->sd, "%s\n", "Forward");
      if ((server_answer = get_next_line(client->sd)) != NULL)
	{
	  if (strcmp(server_answer, "ok") == 0)
	    free(server_answer);
	}
      client->look = client->look->next;
      diff_distance_in_list--;
    }
}
