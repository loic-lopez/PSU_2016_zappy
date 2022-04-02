/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/jabbar_y/rendu/PSU_2016_zappy/ai
** 
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
** 
** Started on  Wed Jun 21 11:31:36 2017 Jabbari Yassir
** Last update Mon Jun 26 11:59:19 2017 Stanislas Deneubourg
*/

#include "ai.h"

int	countword(char *str, char c)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i])
    {
      while (str[i] == c && str[i] != '\0')
	i++;
      if (str[i])
	n++;
      while (str[i] != c && str[i] != 0)
	i++;
    }
  return (n);
}

int	current(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != c && str[i])
    {
      i += 1;
    }
  return (i);
}

char	**my_str_to_wordtab(char *str, char c)
{
  int	i;
  int	l;
  int	t;
  char	**tab;

  i = 0;
  l = 0;
  if (str == NULL)
    return (NULL);
  if ((tab = malloc((countword(str, c) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      if ((tab[l] = malloc((current(&str[i], c) + 1) * sizeof(char))) == NULL)
	return (NULL);
      t = 0;
      while (str[i] != c && str[i] != '\0')
	tab[l][t++] = str[i++];
      tab[l++][t] = '\0';
      while (str[i] == c )
	i++;
    }
  tab[l] = NULL;
  return (tab);
}
