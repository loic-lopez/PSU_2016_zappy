/*
** ai_inventory.c for ai inventory in /home/deneub_s/PSU_2016_zappy
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Thu Jun 22 10:09:06 2017 Stanislas Deneubourg
** Last update Fri Jun 30 15:36:18 2017 Stanislas Deneubourg
*/

#include "ai.h"

void            print_inventory(t_client *trantorian)
{
  printf("food : %zu\n", trantorian->inventory.food);
  printf("linemate : %zu\n", trantorian->inventory.linemate);
  printf("deraumere : %zu\n", trantorian->inventory.deraumere);
  printf("sibur : %zu\n", trantorian->inventory.sibur);
  printf("mendiane : %zu\n", trantorian->inventory.mendiane);
  printf("phiras : %zu\n", trantorian->inventory.phiras);
  printf("thystame : %zu\n", trantorian->inventory.thystame);
}

void		fill_inventory(t_client *trantorian, char **data)
{
  if (strcmp(data[0], "thystame") == 0)
    trantorian->inventory.thystame = atoi(data[1]);
  else if (strcmp(data[0], "food") == 0)
    trantorian->inventory.food = atoi(data[1]);
  else if (strcmp(data[0], "linemate") == 0)
    trantorian->inventory.linemate = atoi(data[1]);
  else if (strcmp(data[0], "deraumere") == 0)
    trantorian->inventory.deraumere = atoi(data[1]);
  else if (strcmp(data[0], "sibur") == 0)
    trantorian->inventory.sibur = atoi(data[1]);
  else if (strcmp(data[0], "mendiane") == 0)
    trantorian->inventory.mendiane = atoi(data[1]);
  else if (strcmp(data[0], "phiras") == 0)
    trantorian->inventory.phiras = atoi(data[1]);
}

void		parse_inventory(t_client *trantorian, char **tab)
{
  int		i;
  char		**tmp;

  i = 0;
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      tmp = my_str_to_wordtab(&tab[i][1], ' ');
      fill_inventory(trantorian, tmp);
      i++;
    }
}

void		ai_treat_inventory(t_client *trantorian, char *buffer)
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
  tab = my_str_to_wordtab(buffer, ',');
  parse_inventory(trantorian, tab);
  free_tab(tab);
}

void		ai_inventory(t_client *client)
{
  char	*server_answer;

  dprintf(client->sd, "%s\n", "Inventory");
  if ((server_answer = get_next_line(client->sd)) != NULL)
    {
      ai_treat_inventory(client, server_answer);
      free(server_answer);
    }
}
