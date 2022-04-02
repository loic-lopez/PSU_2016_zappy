/*
** execute_client_utils.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_utils.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:40:16 2017 Loic Lopez
** Last update Wed Jun 28 16:42:48 2017 pierre piazza
*/

#include "server.h"

void	init_pos_n(t_pos point, t_serv *server)
{
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x)].sound = 0;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x)].sound = 1;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x - 1)].sound = 2;
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x - 1)].sound = 3;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x - 1)].sound = 4;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x)].sound = 5;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x + 1)].sound = 6;
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x + 1)].sound = 7;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x + 1)].sound = 8;
}

void	init_pos_e(t_pos point, t_serv *server)
{
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x)].sound = 0;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x)].sound = 3;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x - 1)].sound = 4;
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x - 1)].sound = 5;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x - 1)].sound = 6;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x)].sound = 7;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x + 1)].sound = 8;
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x + 1)].sound = 1;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x + 1)].sound = 2;
}

void	init_pos_s(t_pos point, t_serv *server)
{
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x)].sound = 0;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x)].sound = 5;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x - 1)].sound = 6;
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x - 1)].sound = 7;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x - 1)].sound = 8;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x)].sound = 1;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x + 1)].sound = 2;
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x + 1)].sound = 3;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x + 1)].sound = 4;
}

void	init_pos_w(t_pos point, t_serv *server)
{
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x)].sound = 0;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x)].sound = 7;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x - 1)].sound = 8;
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x - 1)].sound = 1;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x - 1)].sound = 2;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x)].sound = 3;
  ARENA[ABSHEIGHT(point.y + 1)][ABSWIDTH(point.x + 1)].sound = 4;
  ARENA[ABSHEIGHT(point.y)][ABSWIDTH(point.x + 1)].sound = 5;
  ARENA[ABSHEIGHT(point.y - 1)][ABSWIDTH(point.x + 1)].sound = 6;
}

void	init_map_sound(t_serv *server,
		       t_client *client)
{
  size_t	i;
  size_t	j;
  t_pos	point;
  void (*init_pos_sound[])(t_pos, t_serv *) =
    {
      init_pos_n, init_pos_e, init_pos_s, init_pos_w
    };

  i = 0;
  while (i < HEIGHT)
    {
      j = 0;
      while (j < WIDTH)
	{
	  server->map.field[i][j].sound = -1;
	  j++;
	}
      i++;
    }
  point.x = client->pos_x;
  point.y = client->pos_y;
  init_pos_sound[client->orientation](point, server);
}
