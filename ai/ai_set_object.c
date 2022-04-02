/*
** ai_set_object.c for set object in /home/deneub_s/PSU_2016_zappy
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Tue Jun 27 15:02:15 2017 Stanislas Deneubourg
** Last update Tue Jun 27 15:07:58 2017 Stanislas Deneubourg
*/

#include "ai.h"

void	ai_set_object(t_client *client, char *cmd)
{
  char	*server_answer;

  dprintf(client->sd, "%s\n", cmd);
  if ((server_answer = get_next_line(client->sd)) != NULL)
    if (strcmp(server_answer, "ok") == 0)
      free(server_answer);
}
