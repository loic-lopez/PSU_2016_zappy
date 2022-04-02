/*
** ai_look.c for ai_look in /home/jabbar_y/rendu/PSU_2016_zappy
** 
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
** 
** Started on  Wed Jun 21 11:28:45 2017 Jabbari Yassir
** Last update Fri Jun 30 15:54:39 2017 Stanislas Deneubourg
*/

#include "ai.h"

void		fill_look(t_look *look, char *data, int i)
{
  look->coor = i;
  if (strstr(data, "player") != NULL)
    look->player += 1;
  if (strstr(data, "thystame") != NULL)
    look->ahead.thystame += 1;
  if (strstr(data, "food") != NULL)
    look->ahead.food += 1;
  if (strstr(data, "linemate") != NULL)
    look->ahead.linemate += 1;
  if (strstr(data, "deraumere") != NULL)
    look->ahead.deraumere += 1;
  if (strstr(data, "sibur") != NULL)
    look->ahead.sibur += 1;
  if (strstr(data, "mendiane") != NULL)
    look->ahead.mendiane += 1;
  if (strstr(data, "phiras") != NULL)
    look->ahead.phiras += 1;
}

void		parse_look(t_client *trantorian, char **tab)
{
  int		i;

  i = 0;
  trantorian->look = NULL;
  while (tab[i])
    {
      link_list(&trantorian->look, tab[i], i);
      i++;
    }
}

void		init_look(t_look *look)
{
  look->player = 0;
  look->coor = 0;
  init_inventory(&look->ahead);
}

void		ai_treat_look(t_client *trantorian, char *buffer)
{
  int		i;
  int		nb;
  char		**tab;

  i = 0;
  nb = 0;
  while (buffer[i])
    {
      if (buffer[i] == ',')
	nb += 1;
      i++;
    }
  trantorian->nb_cases = nb;
  tab = my_str_to_wordtab(buffer, ',');
  parse_look(trantorian, tab);
  free_tab(tab);
}

void		ai_look(t_client *client)
{
  char  first_recv[40960];

  dprintf(client->sd, "%s\n", "Look");
  get_receive(client, first_recv);
  ai_treat_look(client, first_recv);
}
