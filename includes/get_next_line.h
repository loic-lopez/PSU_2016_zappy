/*
** get_next_line.h for get_next_line in /home/piazza_p/rendu/PSU_2016_myftp
** 
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
** 
** Started on  Tue May 16 17:21:32 2017 pierre piazza
** Last update Thu May 18 12:17:09 2017 pierre piazza
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef READ_SIZE
#  define READ_SIZE (8)
# endif

# ifndef BUF
#  define BUF (READ_SIZE + 1)
# endif

char   	*get_next_line(const int fd);

#endif
