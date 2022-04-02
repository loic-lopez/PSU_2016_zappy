/*
** execute_graphical_client_time.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_graphical_client_time.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  mar. juin 27 14:23:34 2017 Loic Lopez
** Last update Fri Jun 30 14:55:41 2017 Eric Deschodt
*/

#include "server.h"

void	execute_sgt(t_serv *server, t_client *current_client, char *cmd)
{
  (void)cmd;
  dprintf(current_client->sd, "sgt %f\n", server->freq);
}

void	execute_sst(t_serv *server, t_client *current_client, char *cmd)
{
  int 	i;
  float	freq;

  i = 0;
  while (cmd[i] && cmd[i] != '\n')
    i++;
  i--;
  freq = (float)atof(&cmd[i]);
  server->freq = freq;
  dprintf(current_client->sd, "msz %zu %zu\n", server->map.width,
	  server->map.height);
}
