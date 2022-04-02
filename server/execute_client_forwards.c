/*
** execute_forwards.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_forwards.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  mer. juin 21 12:48:55 2017 Loic Lopez
** Last update Fri Jun 30 16:14:00 2017 Eric Deschodt
*/

#include "server.h"

void	execute_forward_north(t_serv *server, t_client *current_client)
{
  server->map.field[current_client->pos_y][current_client->pos_x].player--;
  if (current_client->pos_y == 0)
      current_client->pos_y = server->map.height - 1;
  else
      current_client->pos_y--;
  server->map.field[current_client->pos_y][current_client->pos_x].player++;
}

void	execute_forward_south(t_serv *server, t_client *current_client)
{
  server->map.field[current_client->pos_y][current_client->pos_x].player--;
  if (current_client->pos_y == server->map.height - 1)
    current_client->pos_y = 0;
  else
    current_client->pos_y++;
  server->map.field[current_client->pos_y][current_client->pos_x].player++;
}

void	execute_forward_west(t_serv *server, t_client *current_client)
{
  server->map.field[current_client->pos_y][current_client->pos_x].player--;
  if (current_client->pos_x == 0)
    current_client->pos_x = server->map.width - 1;
  else
    current_client->pos_x--;
  server->map.field[current_client->pos_y][current_client->pos_x].player++;
}

void	execute_forward_east(t_serv *server, t_client *current_client)
{
  server->map.field[current_client->pos_y][current_client->pos_x].player--;
  if (current_client->pos_x == server->map.width - 1)
    current_client->pos_x = 0;
  else
    current_client->pos_x++;
  server->map.field[current_client->pos_y][current_client->pos_x].player++;
}

void	execute_forward(t_serv *server, t_client *current_client, char *cmd)
{
  void (*execute_forwards[])(t_serv *, t_client *) =
   {
    execute_forward_north, execute_forward_east,
    execute_forward_south, execute_forward_west
   };
  execute_forwards[current_client->orientation](server, current_client);
  dprintf(current_client->sd, "ok\n");
  (void)cmd;
}
