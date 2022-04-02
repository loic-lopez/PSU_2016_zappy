/*
** linkList.c for  in /home/descho_e/tek2/PSU_2016_myirc/sources_client
** 
** Made by Eric Deschodt
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Jun  5 12:22:31 2017 Eric Deschodt
** Last update Thu Jun 22 12:52:47 2017 Eric Deschodt
*/

#include "linkList.h"

void		push_back(t_vector **list, void *_data)
{
  t_vector	*new_elem;
  t_vector	*tmp;

  if ((new_elem = malloc(sizeof(t_vector))) == NULL)
    exit(-1);
  new_elem->data = _data;
  new_elem->next = NULL;
  new_elem->prev = NULL;
  if (*list == NULL)
    *list = new_elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_elem;
      new_elem->prev = tmp;
    }
}

void		show_list(t_vector *list, void (*fct)(void *))
{
  t_vector	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (fct != NULL)
	(*fct)(tmp->data);
      tmp = tmp->next;
    }
}

void		free_list(t_vector **list, void (*fct)(void *))
{
  t_vector	*tmp;

  tmp = *list;
  while (tmp->next != NULL)
    {
      if (fct != NULL)
	(*fct)(tmp->data);
      tmp->data = NULL;
      tmp = tmp->next;
      free(tmp->prev);
    }
  if (fct != NULL && tmp->data != NULL)
    (*fct)(tmp->data);
  free(tmp);
}

void		*get_elem_index(t_vector *list, int index)
{
  t_vector	*tmp;
  int		i;

  if (list == NULL)
    return (NULL);
  i = 0;
  tmp = list;
  while (tmp != NULL && i != index)
    {
      i++;
      tmp = tmp->next;
    }
  if (i != index)
    return (NULL);
  else
    return (tmp->data);
}

void		erase(t_vector **list, int index, void (*fct)(void *))
{
  t_vector	*tmp;
  int		i;
  t_vector	*prev;
  t_vector	*next;

  i = -1;
  tmp = *list;
  while (tmp != NULL && ++i != index)
    tmp = tmp->next;
  if (i == index)
    {
      prev = tmp->prev;
      next = tmp->next;
      if (prev != NULL)
	prev->next = next;
      else
	*list = next;
      if (next != NULL)
	next->prev = prev;
      if (fct != NULL)
	(*fct)(tmp->data);
      free(tmp);
    }
}
