/*
** map.h for  in /home/descho_e/tek2/PSU_2016_zappy
** 
** Made by Eric Deschodt
** Login   <descho_e@epitech.net>
** 
** Started on  Thu Jun 15 16:51:56 2017 Eric Deschodt
** Last update Fri Jun 30 15:40:07 2017 Eric Deschodt
*/

#ifndef		MAP_
# define	MAP_

# include	<stdio.h>
# include	<stdlib.h>

typedef enum            ressources
{
  FOOD		=       0,
  LINEMATE      =       1,
  DERAUMERE     =       2,
  SIBUR		=       3,
  MENDIANE	=       4,
  PHIRAS	=       5,
  THYSTAME      =       6
}                       ressources;

typedef struct s_tile
{
  size_t	ressources[7];
  size_t	player;
  char		sound;
}		t_tile;

typedef struct	s_map
{
  size_t	width;
  size_t	height;
  t_tile       	**field;
}		t_map;

void            init_tile(t_tile *tile);
int             init_map(t_map *map, size_t width, size_t height);
void            aff_map(t_map map);
void            free_map(t_map *map);

#endif
