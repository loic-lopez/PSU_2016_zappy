/*
** execute_client_move.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_move.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:36:31 2017 Loic Lopez
** Last update Wed Jun 21 17:05:56 2017 Eric Deschodt
*/

#include "server.h"

void	execute_right(t_serv *server, t_client *current_client, char *cmd)
{
  (void)server;
  if (current_client->orientation == WEST)
    current_client->orientation = NORTH;
  else
    current_client->orientation++;
  dprintf(current_client->sd, "ok\n");
  (void)cmd;
}

void	execute_left(t_serv *server, t_client *current_client, char *cmd)
{
  (void)server;
  if (current_client->orientation == NORTH)
    current_client->orientation = WEST;
  else
    current_client->orientation--;
  dprintf(current_client->sd, "ok\n");
  (void)cmd;
}
