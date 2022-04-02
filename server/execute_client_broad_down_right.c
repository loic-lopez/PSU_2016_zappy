/*
** execute_client_utils.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_utils.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:40:16 2017 Loic Lopez
** Last update Mon Jun 26 14:54:43 2017 Eric Deschodt
*/

#include "server.h"

int		init_diago_right_down(size_t *i, size_t *j,
				   t_pos destination,
				   t_serv *server)
{
  *i = ABSHEIGHT(destination.y - 1);
  *j = ABSWIDTH(destination.x + 1);
  return (ARENA[*i][*j].sound - 1);
}

void		diagonal_right_down_earch(t_pos destination,
					  t_serv *server,
					  int *distance)
{
  size_t	i;
  size_t	j;
  int		current;
  int		ite;
  bool		stop;

  stop = false;
  ite = 0;
  current = init_diago_right_down(&i, &j, destination, server);
  while (stop == false)
    {
      ite += 1;
      i = ABSHEIGHT(destination.y + 1);
      j = ABSWIDTH(destination.x + 1 + ite);
      while (stop == false && i != ABSHEIGHT(destination.y + 1 + ite))
	{
	  find_stop(&(ARENA[i][j].sound), &(distance[current]), ite, &stop);
	  i = ABSHEIGHT(i + 1);
	}
      while (stop == false && j != ABSWIDTH(destination.x))
	{
	  find_stop(&(ARENA[i][j].sound), &(distance[current]), ite, &stop);
	  j = ABSWIDTH(j - 1);
	}
    }
}
