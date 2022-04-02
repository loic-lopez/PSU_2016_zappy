/*
** ai_treatement_text.c for treatement_text in /home/deneub_s/PSU_2016_zappy
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Fri Jun 30 15:09:40 2017 Stanislas Deneubourg
** Last update Sat Jul  1 14:55:38 2017 Stanislas Deneubourg
*/

#include "ai.h"

void		assemble_buffer(char builder[40960], char buffer[40960])
{
  int	i;

  i = 0;
  while (i < 40960)
    {
      strcat(builder, &buffer[i]);
      i++;
    }
}

int		is_buffer_full(int reception,
			       char buffer[40960], char builder[40960])
{
  int end;

  end = 0;
  while (end < reception && buffer[end] != '\0')
    {
      strcat(builder, &buffer[end]);
      ++end;
    }
  if (buffer[end] == '\0')
    return (0);
  else
    return (-1);
}

int		receive_failed(char builder[40960])
{
  memset(builder, 0, 40960);
  return (-1);
}
