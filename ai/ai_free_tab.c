/*
** free_tab.c for free_tab in /home/deneub_s/PSU_2016_zappy/ai
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Thu Jun 22 11:19:13 2017 Stanislas Deneubourg
** Last update Mon Jun 26 16:01:55 2017 Stanislas Deneubourg
*/

#include "ai.h"

void            free_tab(char **tab)
{
  int           i;

  i = 0;
  while (tab[i])
    {
      if (tab[i])
	free(tab[i]);
      i++;
    }
  free(tab);
}
