/*
** launch_client_demand.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/launch_client_demand.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 17:52:44 2017 Loic Lopez
** Last update Fri Jun 30 16:30:17 2017 pierre piazza
*/

#include "server.h"

void		add_cmd_client(t_serv *server,
			       t_client *current_client,
			       char *cmd,
			       server_command type)
{
  t_cmd		*new_cmd;

  if (checking_client_possibility(server, current_client, cmd, type) == true)
    {
      if ((new_cmd = malloc(sizeof(t_cmd))) != NULL)
	{
	  strncpy(new_cmd->cmd, cmd, 255);
	  new_cmd->type = type;
	  new_cmd->delay =
	    (type == FORWARD || type == RIGHT ||
	     type == LEFT || type == LOOK ||
	     type == BROADCAST_TEXT || type == EJECT ||
	     type == TAKE_OBJECT || type == SET_OBJECT) ? 7 :
	    (type == FORK) ? 42 : (type == INCANTATION) ? 300 : 0;
	  push_back(&current_client->cmds, new_cmd);
	}
    }
}

void	find_typ(server_command *type,
		 bool *is_valid_command,
		 int i)
{
  *type = (server_command)i;
  *is_valid_command = true;

}

void	remove_client(t_serv *server, t_client *client, bool graph)
{
  t_vector      *tmp_team;
  t_vector      *tmp_client;
  int           i;

  tmp_team = server->teams;
  while (tmp_team)
    {
      i = 0;
      tmp_client = ((t_team *)tmp_team->data)->clients;
      while (tmp_client)
	{
	  if (((t_client *)tmp_client->data)->sd == client->sd)
	    {
	      close(client->sd);
	      if (!graph)
		ARENA[client->pos_y][client->pos_x].player--;
	      erase(&((t_team *)tmp_team->data)->clients, i, NULL);
	      break;
	    }
	  i++;
	  tmp_client = tmp_client->next;
	}
      tmp_team = tmp_team->next;
    }
}

void	launch_client_demand(t_serv *server,
			     t_client *current_client, char *cmd)
{
  size_t	i;
  const char	*available_commands[] =
   {
    "Forward", "Right", "Left", "Look", "Inventory",
    "Broadcast", "Connect_nbr", "Fork", "Eject", "Take",
    "Set", "Incantation"
   };
  bool			is_valid_command;
  server_command	type;

  if (cmd[strlen(cmd) - 1] == '\n')
    cmd[strlen(cmd) - 1] = 0;
  else
    return ((!cmd[0]) ? remove_client(server, current_client, false) :
	    (void)dprintf(current_client->sd, "ko\n"));
  i = -1;
  is_valid_command = false;
  while (++i < sizeof(available_commands) / sizeof(available_commands[0]))
    {
      if (strncmp(available_commands[i],
		  cmd, strlen(available_commands[i])) == 0)
	find_typ(&type, & is_valid_command, i);
    }
  !is_valid_command ? dprintf(current_client->sd, "ko\n") :
    add_cmd_client(server, current_client, cmd, type);
}
