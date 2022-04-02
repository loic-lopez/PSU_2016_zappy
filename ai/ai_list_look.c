/*
** listLook.c for listLook in /home/jabbar_y/rendu/PSU_2016_zappy
** 
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
** 
** Started on  Thu Jun 22 13:45:30 2017 Jabbari Yassir
** Last update Tue Jun 27 09:25:25 2017 Stanislas Deneubourg
*/

#include "ai.h"

void            print_list(t_look *look)
{
  int	i;
  t_look	*tmp;

  tmp = look;
  i = 0;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp->next != NULL)
    {
      printf("-----------Case n°%i------------\n", i);
      printf("Player : %d\n", tmp->player);
      printf("Coor : %d\n", tmp->coor);
      printf("food : %zu\n", tmp->ahead.food);
      printf("linemate : %zu\n", tmp->ahead.linemate);
      printf("deraumere : %zu\n", tmp->ahead.deraumere);
      printf("sibur : %zu\n", tmp->ahead.sibur);
      printf("mendiane : %zu\n", tmp->ahead.mendiane);
      printf("phiras : %zu\n", tmp->ahead.phiras);
      printf("thystame : %zu\n", tmp->ahead.thystame);
      tmp = tmp->next;
      i++;
    }
}

void            link_list(t_look **look, char *data, int i)
{
  t_look        *new_elem;

  if ((new_elem = malloc(sizeof(t_look))) == NULL)
    return;
  new_elem->next = NULL;
  new_elem->prev = NULL;
  init_look(new_elem);
  fill_look(new_elem, data, i);
  if ((*look) != NULL)
    {
      new_elem->prev = (*look);
      (*look)->next = new_elem;
    }
  (*look) = new_elem;
}
