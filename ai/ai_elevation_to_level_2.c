/*
** ai_elevation_to_2.c for elevation 2 in /home/deneub_s/PSU_2016_zappy/ai
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Thu Jun 22 10:46:58 2017 Stanislas Deneubourg
** Last update Sat Jul  1 16:59:21 2017 Stanislas Deneubourg
*/

#include "ai.h"

void		ai_try_elevation_to_level_2(t_client *client)
{
  char		*server_answer;

  if (client->inventory.linemate >= 1)
    {
      ai_put_ressources_to_level_2(client);
      dprintf(client->sd, "%s\n", "Incantation");
      if ((server_answer = get_next_line(client->sd)) != NULL)
	{
	  if (strcmp(server_answer, "ko") != 0)
	    ai_execute_elevation_to_level_2(client);
	  free(server_answer);
	}
    }
}

void		ai_execute_elevation_to_level_2(t_client *client)
{
  client->level = 2;
}

void		ai_put_ressources_to_level_2(t_client *client)
{
  int	i;

  i = 0;
  while (i < 1)
    {
      ai_set_object(client, "Set Linemate");
      i++;
    }
}
