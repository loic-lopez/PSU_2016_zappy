/*
** execute_client_utils.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/execute_client_utils.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 18:40:16 2017 Loic Lopez
** Last update Mon Jun 26 15:28:58 2017 Eric Deschodt
*/

#include "server.h"

void		printsoundtable(t_serv *server)
{
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  while (i < HEIGHT)
    {
      j = 0;
      while (j < WIDTH)
	{
	  if (ARENA[i][j].sound == -1)
	    dprintf(1, ".");
	  else
	    dprintf(1, "%d", ARENA[i][j].sound);
	  j++;
	}
      dprintf(1, "\n");
      i++;
    }
  dprintf(1, "\n");
}

void		horizontal_search(t_pos destination,
				  t_serv *server,
				  int *distance)
{
  int		i;
  int		j;
  int		dist;
  int		current;

  dist = 0;
  i = ABSHEIGHT(destination.y);
  j = ABSWIDTH(destination.x + 1);
  current = ARENA[i][j].sound - 1;
  while (ARENA[i][j].sound == -1)
    j = ABSHEIGHT(j + 1) + (dist++ * 0);
  if (ARENA[i][j].sound == 0)
    distance[current] = dist;
  dist = 0;
  i = ABSHEIGHT(destination.y);
  j = ABSWIDTH(destination.x - 1);
  current = ARENA[i][j].sound - 1;
  while (ARENA[i][j].sound == -1)
    j = ABSHEIGHT(j - 1) + (dist++ * 0);
  if (ARENA[i][j].sound == 0)
    distance[current] = dist;
}

void		vertical_search(t_pos destination,
				t_serv *server,
				int *distance)
{
  int		i;
  int		j;
  int		dist;
  int		current;

  dist = 0;
  i = ABSHEIGHT(destination.y - 1);
  j = ABSWIDTH(destination.x);
  current = ARENA[i][j].sound - 1;
  i = ABSHEIGHT(i - 1) + (dist++ * 0);
  while (ARENA[i][j].sound == -1)
    i = ABSHEIGHT(i - 1) + (dist++ * 0);
  if (ARENA[i][j].sound == 0)
    distance[current] = dist;
  dist = 0;
  i = ABSHEIGHT(destination.y + 1);
  j = ABSWIDTH(destination.x);
  current = ARENA[i][j].sound - 1;
  i = ABSHEIGHT(i + 1) + (dist++ * 0);
  while (ARENA[i][j].sound == -1)
    i = ABSHEIGHT(i + 1) + (dist++ * 0);
  if (ARENA[i][j].sound == 0)
    distance[current] = dist;
}
