/*
** execute_client_utils.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_utils.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:40:16 2017 Loic Lopez
** Last update Mon Jun 26 16:52:53 2017 Eric Deschodt
*/

#include "server.h"

bool		find_stop(char *sound,
			  int *where,
			  int ite,
			  bool *stop)
{
  if (*sound != -1)
    {
      if (*sound == 0)
	*where = ite;
      *stop = true;
      return (true);
    }
  return (false);
}

int		init_diago_left_up(size_t *i, size_t *j,
				   t_pos destination,
				   t_serv *server)
{
  *i = ABSHEIGHT(destination.y - 1);
  *j = ABSWIDTH(destination.x - 1);
  return (ARENA[*i][*j].sound - 1);
}

void		diagonal_left_up_earch(t_pos destination,
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
  current = init_diago_left_up(&i, &j, destination, server);
  while (stop == false)
    {
      ite += 1;
      i = ABSHEIGHT(destination.y - 1);
      j = ABSWIDTH(destination.x - 1 - ite);
      while (stop == false &&i != ABSHEIGHT(destination.y - 1 - ite))
	{
	  find_stop(&(ARENA[i][j].sound), &(distance[current]), ite, &stop);
	  i = ABSHEIGHT(i - 1);
	}
      while (stop == false && j != ABSWIDTH(destination.x))
	{
	  find_stop(&(ARENA[i][j].sound), &(distance[current]), ite, &stop);
	  j = ABSWIDTH(j + 1);
	}
    }
}
