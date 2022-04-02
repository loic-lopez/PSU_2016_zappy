/*
** linkList.h for  in /home/descho_e/tek2/PSU_2016_myirc
** 
** Made by Eric Deschodt
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Jun  5 12:46:05 2017 Eric Deschodt
** Last update Mon Jun 19 15:25:08 2017 pierre piazza
*/

#ifndef VECTOR_C__
# define VECTOR_C__

# include <stdlib.h>

typedef struct          s_vector
{
  void                  *data;
  struct s_vector       *next;
  struct s_vector       *prev;
}			t_vector;

void            push_back(t_vector **list, void *_data);
void            show_list(t_vector *list, void (*fct)(void *));
void		free_list(t_vector **list, void (*fct)(void *));
void		*get_elem_index(t_vector *list,	int index);
void            erase(t_vector **list, int index, void (*fct)(void *));

#endif
