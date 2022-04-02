/*
** check_client_possibility.c for  in /home/descho_e/tek2/PSU_2016_zappy
** 
** Made by Eric Deschodt
** Login   <descho_e@epitech.net>
** 
** Started on  Thu Jun 22 12:08:35 2017 Eric Deschodt
** Last update Sun Jul  2 22:12:43 2017 pierre piazza
*/

#include "server.h"

bool	check_client_eject(t_serv *server,
			   t_client *current_client,
			   char *cmd __attribute__((unused)))
{
  if ((server->map.field[current_client->pos_y]
       [current_client->pos_x]).player <= 1)
    {
      dprintf(current_client->sd, "ko\n");
      return (false);
    }
  return (true);
}

bool	check_client_take(t_serv *server,
			  t_client *current_client,
			  char *cmd)
{
  int   res;

  if ((res = find_which_ressource(&cmd[5])) == -1)
    dprintf(current_client->sd, "ko\n");
  else
    {
      if ((server->map.field[current_client->pos_y]
           [current_client->pos_x]).ressources[res] > 0)
	return (true);
      else
        dprintf(current_client->sd, "ko\n");
    }
  return (false);
}

bool	check_client_set(t_serv *server __attribute__((unused)),
			 t_client *current_client,
			 char *cmd)
{
  int   is_ok;

  is_ok = find_which_ressource(&cmd[4]);
  if (is_ok == -1)
    dprintf(current_client->sd, "ko\n");
  else
    {
      if (current_client->inv.ressources[is_ok] > 0)
	return (true);
      else
	dprintf(current_client->sd, "ko\n");
    }
  return (false);
}

bool	check_client_incantation(t_serv *server,
				 t_client *current_client,
				 char *cmd __attribute__((unused)))
{
  bool  (*check_lvl_functions[])(t_serv *, t_client *, bool) =
    {
      lvl1_2, lvl2_3, lvl3_4, lvl4_5, lvl5_6, lvl6_7, lvl7_8
    };

  if (check_lvl_functions[(int)current_client->lvl - 1]
      (server, current_client, false) == true)
    {
      execute_pic(server, current_client);
      return (true);
    }
  else
    dprintf(current_client->sd, "ko\n");
  return (false);
}

bool	checking_client_possibility(t_serv *server,
				    t_client *current_client,
				    char *cmd,
				    server_command type)
{
  if (type == FORWARD || type == RIGHT
      || type == LEFT || type == LOOK
      || type == INVENTORY || type == BROADCAST_TEXT
      || type == CONNECT_NBR || type == FORK)
    return (true);
  if (type == EJECT)
    return (check_client_eject(server, current_client, cmd));
  else if (type == TAKE_OBJECT)
    return (check_client_take(server, current_client, cmd));
  else if (type == SET_OBJECT)
    return (check_client_set(server, current_client, cmd));
  else if (type == INCANTATION)
    return (check_client_incantation(server, current_client, cmd));
  return (true);
}
