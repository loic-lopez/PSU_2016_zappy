/*
** execute_client_delay.c for  in /home/descho_e/tek2/PSU_2016_zappy
** 
** Made by Eric Deschodt
** Login   <descho_e@epitech.net>
** 
** Started on  Thu Jun 22 12:46:53 2017 Eric Deschodt
** Last update Fri Jun 30 16:05:06 2017 pierre piazza
*/

#include "server.h"

void	execute_and_erase(t_serv *server,
			  t_client *client,
			  t_cmd *cmd)
{
  client->cmd = cmd->type;
  execute_client_demand(server, client, cmd->cmd);
  erase(&client->cmds, 0, NULL);
}

void		egg_hatching(t_team *team)
{
  t_vector	*tmp;

  tmp = team->eggs;
  while (tmp)
    {
      if (((t_egg *)tmp->data)->delay > 0)
	((t_egg *)tmp->data)->delay--;
      tmp = tmp->next;
    }
}

void		do_actions(t_serv *server, t_vector *tmp_team,
			   t_vector *tmp_client, int i)
{
  t_client	*client;
  t_cmd		*cmd;

  client = ((t_client *)tmp_client->data);
  if (!remove_food(server, client))
    {
      ARENA[client->pos_y][client->pos_x].player--;
      erase(&((t_team *)tmp_team->data)->clients, i, NULL);
      return ;
    }
  cmd = get_elem_index(client->cmds, 0);
  if (cmd)
    {
      (cmd->delay == 0) ? execute_and_erase(server, client, cmd) :
	cmd->delay--;
    }
}

void		update_client_delay(t_serv *server)
{
  t_vector      *tmp_team;
  t_vector	*tmp_client;
  int		i;

  tmp_team = server->teams->next;
  while (tmp_team)
    {
      i = 0;
      tmp_client = ((t_team *)tmp_team->data)->clients;
      egg_hatching(((t_team *)tmp_team->data));
      while (tmp_client)
	{
	  do_actions(server, tmp_team, tmp_client, i);
	  tmp_client = tmp_client->next;
	  i++;
	}
      tmp_team = tmp_team->next;
    }
}
