/*
** map.c for  in /home/descho_e/tek2/PSU_2016_zappy
** 
** Made by Eric Deschodt
** Login   <descho_e@epitech.net>
** 
** Started on  Thu Jun 15 17:06:38 2017 Eric Deschodt
** Last update Fri Jun 30 15:05:13 2017 Eric Deschodt
*/

#include "map.h"

void		init_tile(t_tile *tile)
{
  int		i;

  i = 0;
  while (i < 7)
    tile->ressources[i++] = 0;
  tile->player = 0;
}

int		init_map(t_map *map, size_t width, size_t height)
{
  size_t	i;
  size_t	j;

  map->width = width;
  map->height = height;
  if ((map->field = malloc(sizeof(t_tile *) * height)) == NULL)
    return (-1);
  i = 0;
  while (i < height)
    {
      if ((map->field[i] = malloc(sizeof(t_tile) * width)) == NULL)
	return (-1);
      j = 0;
      while (j < width)
	{
	  init_tile(&(map->field[i][j]));
	  j++;
	}
      i++;
    }
  return (0);
}

void		aff_map(t_map map)
{
  size_t	i;
  size_t	j;

  i = 0;
  while (i < map.height)
    {
      j = 0;
      while (j < map.width)
	{
	  dprintf(1, "%zu", map.field[i][j].player);
	  j++;
	}
      dprintf(1, "\n");
      i++;
    }
  dprintf(1, "\n");
}

void		free_map(t_map *map)
{
  size_t	i;

  i = 0;
  while (i < map->height)
    free(map->field[i++]);
  free(map->field);
}
