/*
** ai_search_for.c for search for in /home/deneub_s/PSU_2016_zappy/ai
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Thu Jun 22 14:57:47 2017 Stanislas Deneubourg
** Last update Sat Jul  1 14:52:54 2017 Stanislas Deneubourg
*/

#include "ai.h"

int		ai_search_for(t_client *client, char *to_find)
{
  int	i;
  int	found;

  if (client->search_player == true)
    return (follow_broadcast(client));
  reset_list(client);
  i = 0;
  found = -1;
  while (i < client->nb_cases)
    {
      found = is_object_found(client, to_find, found, i);
      if (found != -1)
	break;
      i++;
      if (client->look->next != NULL)
	client->look = client->look->next;
    }
  if (found != -1)
    {
      to_find_line(client, to_find, found);
      reset_list(client);
      return (0);
    }
  else
    return (-1);
}

void	ai_locate_seen_object(t_client *client, char *to_find,
			      int pos, int line)
{
  int	i;
  int	j;
  char	direction;
  char	*server_answer;

  i = j = 0;
  reset_list(client);
  while (i < line)
    {
      dprintf(client->sd, "%s\n", "Forward");
      if ((server_answer = get_next_line(client->sd)) != NULL)
	if (strcmp(server_answer, "ok") == 0)
	  free(server_answer);
      i++;
    }
  while (j < ai_get_line_center(line))
    {
      client->look = client->look->next;
      j++;
    }
  direction = ai_get_object_direction(pos, line);
  move_to_object(client, direction, pos);
  ai_take_object(client, to_find);
}

int	ai_get_line_center(int line)
{
  int middle;

  middle = 0;

  line == 0 ? middle = 0 :
    line == 1 ? middle = 2 :
    line == 2 ? middle = 6 :
    line == 3 ? middle = 12 :
    line == 4 ? middle = 20 :
    line == 5 ? middle = 30 :
    line == 6 ? middle = 42 :
    line == 7 ? middle = 56 :
    line == 8 ? middle = 72 :
    0;
  return (middle);
}

char	ai_get_object_direction(int pos, int line)
{
  char	dir;

  line == 0 && pos == 0 ? dir = 'm' : line == 1 && pos < 2 ? dir = 'l' :
    line == 1 && pos == 2 ? dir = 'm' : line == 1 && pos > 2 ? dir = 'r' :
    line == 2 && pos < 6 ? dir = 'l' : line == 2 && pos == 6 ? dir = 'm' :
    line == 2 && pos > 6 ? dir = 'r' : line == 3 && pos < 12 ? dir = 'l' :
    line == 3 && pos == 12 ? dir = 'm' : line == 3 && pos > 12 ? dir = 'r' :
    line == 4 && pos < 20 ? dir = 'l' : line == 4 && pos == 20 ? dir = 'm' :
    line == 4 && pos > 20 ? dir = 'r' : line == 5 && pos < 30 ? dir = 'l' :
    line == 5 && pos == 30 ? dir = 'm' : line == 5 && pos > 30 ? dir = 'r' :
    line == 6 && pos < 42 ? dir = 'l' : line == 6 && pos == 42 ? dir = 'm' :
    line == 6 && pos > 42 ? dir = 'r' : line == 7 && pos < 56 ? dir = 'l' :
    line == 7 && pos == 56 ? dir = 'm' : line == 7 && pos > 56 ? dir = 'r' :
    line == 8 && pos < 72 ? dir = 'l' : line == 8 && pos == 72 ? dir = 'm' :
    line == 8 && pos > 72 ? dir = 'r' : 0;
  return (dir);
}

void            ai_take_object(t_client *client, char *to_find)
{
  char	*server_answer;

  (client->look->ahead.food > 0 && strcmp(to_find, "food") == 0)
    ? dprintf(client->sd, "%s\n", "Take Food") :
    (client->look->ahead.linemate > 0 && strcmp(to_find,"linemate") == 0)
    ? dprintf(client->sd, "%s\n", "Take Linemate") :
    (client->look->ahead.deraumere > 0 && strcmp(to_find,"deraumere") == 0)
    ? dprintf(client->sd, "%s\n", "Take Deraumere") :
    (client->look->ahead.sibur > 0 && strcmp(to_find, "sibur") == 0)
    ? dprintf(client->sd, "%s\n", "Take Sibur") :
    (client->look->ahead.mendiane > 0 && strcmp(to_find,"mendiane") == 0)
    ? dprintf(client->sd, "%s\n", "Take Mendiane") :
    (client->look->ahead.phiras > 0 && strcmp(to_find, "phiras") == 0)
    ? dprintf(client->sd, "%s\n", "Take Phiras") :
    (client->look->ahead.thystame > 0 && strcmp(to_find, "thystame") == 0)
    ? dprintf(client->sd, "%s\n", "Take Thystame") : 0;
  if ((server_answer = get_next_line(client->sd)) != NULL)
    free(server_answer);
}
