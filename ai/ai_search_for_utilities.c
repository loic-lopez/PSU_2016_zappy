/*
** ai_search_for_utilities.c for utilities in /home/deneub_s/PSU_2016_zappy
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Mon Jun 26 10:29:03 2017 Stanislas Deneubourg
** Last update Sat Jul  1 14:54:36 2017 Stanislas Deneubourg
*/

#include "ai.h"

void	reset_list(t_client *client)
{
  while (client->look->coor != 0 && client->look->prev != NULL)
    client->look = client->look->prev;
}

void	to_find_line(t_client *client, char *to_find, int fund)
{
  int	line;

  fund == 0 ? line = 0 : fund > 0 && fund < 4 ? line = 1 :
    fund > 3 && fund < 9 ? line = 2 : fund > 8 && fund < 16 ? line = 3 :
    fund > 15 && fund < 25 ? line = 4 : fund > 24 && fund < 36 ? line = 5 :
    fund > 35 && fund < 49 ? line = 6 : fund > 48 && fund < 64 ? line = 7 :
    fund > 64 && fund < 81 ? line = 8 : 0;
  ai_locate_seen_object(client, to_find, fund, line);
}

int	is_object_found(t_client *client, char *to_find, int found, int i)
{
  (client->look->ahead.food > 0 && strcmp(to_find, "food") == 0)
    ? found = i :
    (client->look->ahead.linemate > 0 && strcmp(to_find, "linemate") == 0)
    ? found = i :
    (client->look->ahead.deraumere > 0 && strcmp(to_find, "deraumere") == 0)
    ? found = i :
    (client->look->ahead.sibur > 0 && strcmp(to_find, "sibur") == 0)
    ? found = i :
    (client->look->ahead.mendiane > 0 && strcmp(to_find, "mendiane") == 0)
    ? found = i :
    (client->look->ahead.phiras > 0 && strcmp(to_find, "phiras") == 0)
    ? found = i :
    (client->look->ahead.thystame > 0 && strcmp(to_find, "thystame") == 0)
    ? found = i : 0;
  return (found);
}

void	move_to_object(t_client *client, char direction, int pos)
{
  if (direction == 'l')
    turn_left_front_to_object(client, pos);
  else if (direction == 'r')
    turn_right_front_to_object(client, pos);
}
