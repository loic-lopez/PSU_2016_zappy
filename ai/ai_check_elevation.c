/*
** ai_check_elevation.c for check elevation in /home/deneub_s/PSU_2016_zappy
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Thu Jun 22 10:38:00 2017 Stanislas Deneubourg
** Last update Thu Jun 22 13:38:39 2017 Stanislas Deneubourg
*/

#include "ai.h"

void	ai_check_elevation(t_client *client)
{
  client->level == 1 ? ai_try_elevation_to_level_2(client) :
    client->level == 2 ? ai_try_elevation_to_level_3(client) :
    client->level == 3 ? ai_try_elevation_to_level_4(client) :
    client->level == 4 ? ai_try_elevation_to_level_5(client) :
    client->level == 5 ? ai_try_elevation_to_level_6(client) :
    client->level == 6 ? ai_try_elevation_to_level_7(client) :
    client->level == 7 ? ai_try_elevation_to_level_8(client) :
    0;
}
