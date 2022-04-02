/*
** verify_connect.c for verify connect in /home/deneub_s/PSU_2016_zappy
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Thu Jun 22 09:43:19 2017 Stanislas Deneubourg
** Last update Thu Jun 22 09:43:50 2017 Stanislas Deneubourg
*/

#include "ai.h"

void    verify_connect(t_client *client, char *team_name)
{
  char  *server_answer;

  if ((server_answer = get_next_line(client->sd)) != NULL)
    {
      if (strcmp(server_answer, "WELCOME") == 0)
        dprintf(client->sd, "%s\n", team_name);
      free(server_answer);
      if ((server_answer = get_next_line(client->sd)) != NULL)
        {
          if (strcmp(server_answer, "ko") == 0)
            close(client->sd);
          else
            {
              free(server_answer);
              server_answer = get_next_line(client->sd);
            }
          free(server_answer);
        }
    }
}
