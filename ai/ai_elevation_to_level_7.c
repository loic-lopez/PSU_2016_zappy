/*
** ai_elevation_to_level_7.c for 7 in /home/deneub_s/PSU_2016_zappy/ai
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Thu Jun 22 11:02:57 2017 Stanislas Deneubourg
** Last update Sat Jul  1 14:49:08 2017 Stanislas Deneubourg
*/

#include "ai.h"

void		ai_try_elevation_to_level_7(t_client *client)
{
  char          *server_answer;

  if (client->inventory.linemate >= 1 && client->inventory.deraumere
      >= 2 && client->inventory.sibur >= 3 &&
      client->inventory.phiras >= 1)
    {
      ai_put_ressources_to_level_7(client);
      dprintf(client->sd, "%s\n", "Incantation");
      if ((server_answer = get_next_line(client->sd)) != NULL)
	{
	  if (strcmp(server_answer, "ko") != 0)
	    ai_execute_elevation_to_level_7(client);
	  else
	    ai_send_broadcast_text(client, "Broadcast IncantationTo7");
	  free(server_answer);
	}
    }
}

void		ai_execute_elevation_to_level_7(t_client *client)
{
  client->level = 7;
}

void            ai_put_ressources_to_level_7(t_client *client)
{
  int   i;

  i = 0;
  while (i < 1)
    {
      ai_set_object(client, "Set Linemate");
      ai_set_object(client, "Set Deraumere");
      ai_set_object(client, "Set Sibur");
      ai_set_object(client, "Set Phiras");
      i++;
    }
  while (i < 2)
    {
      ai_set_object(client, "Set Deraumere");
      ai_set_object(client, "Set Sibur");
      i++;
    }
  while (i < 3)
    {
      ai_set_object(client, "Set Deraumere");
      i++;
    }
}
