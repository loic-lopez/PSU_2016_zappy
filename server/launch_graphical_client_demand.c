/*
** launch_graphical_client_demand.c for  in /home/descho_e/tek2/PSU_2016_zappy/server
** 
** Made by Eric Deschodt
** Login   <descho_e@epitech.net>
** 
** Started on  Fri Jun 30 14:58:00 2017 Eric Deschodt
** Last update Fri Jun 30 16:30:06 2017 pierre piazza
*/

#include "server.h"

void	execute_graphical_client_demand(t_serv *server,
					    t_client *current_client,
					    char *cmd,
					    server_command type)
{
  void	(*graphical_server_functions[])(t_serv *, t_client *, char *) =
   {
    execute_msz, execute_bct, execute_mct, execute_tna,
    execute_ppo, execute_plv, execute_pin,
    execute_sgt, execute_sst
   };

  graphical_server_functions[type](server, current_client, cmd);
}

void	launch_graphical_client_demand(t_serv *server,
					   t_client *current_client,
					   char *cmd)
{
  size_t	i;
  const char	*available_commands[] =
   {
    "msz", "bct", "mct", "tna", "ppo", "plv", "pin", "sgt", "sst"
   };
  bool			is_valid_command;
  server_command	type;

  if (cmd[strlen(cmd) - 1] == '\n')
    cmd[strlen(cmd) - 1] = 0;
  else
    return ((!cmd[0]) ? remove_client(server, current_client, true) :
	    (void)dprintf(current_client->sd, "suc\n"));
  i = 0;
  is_valid_command = false;
  while (i < sizeof(available_commands) / sizeof(available_commands[0]))
    {
      if (strncmp(available_commands[i],
		  cmd, strlen(available_commands[i])) == 0)
	find_typ(&type, &is_valid_command, i);
      i++;
    }
  !is_valid_command ? dprintf(current_client->sd, "suc\n") :
  execute_graphical_client_demand(server, current_client, cmd, type);
}
