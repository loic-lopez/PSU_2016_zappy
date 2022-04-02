/*
** trantorian.c for trantorian in /home/jabbar_y/rendu/PSU_2016_zappy
** 
** Made by Jabbari Yassir
** Login   <jabbar_y@epitech.net>
** 
** Started on  Mon Jun 19 18:16:38 2017 Jabbari Yassir
** Last update Thu Jun 29 14:49:08 2017 Stanislas Deneubourg
*/

#include "ai.h"

void		init_trantorian(t_client *trantorian)
{
  trantorian->level = 1;
  trantorian->turns_left = 1260;
  trantorian->search_player = false;
  init_inventory(&trantorian->inventory);
}

void		init_inventory(t_inventory *inventory)
{
  inventory->food = 12345;
  inventory->linemate = 0;
  inventory->deraumere = 0;
  inventory->sibur = 0;
  inventory->mendiane = 0;
  inventory->phiras = 0;
  inventory->thystame = 0;
}
