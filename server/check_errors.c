/*
** check_errors.c for check_errors in /home/piazza_p/rendu/PSU_2016_zappy
** 
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
** 
** Started on  Fri Jun 23 10:21:32 2017 pierre piazza
** Last update Sun Jul  2 22:14:25 2017 pierre piazza
*/

#include "server.h"

bool	sig_ret = true;

void	sig_handler(int sig __attribute__((unused)))
{
  sig_ret = false;
}

void	killall(t_serv *server)
{
  t_vector              *tmp_client;
  t_vector              *tmp_team;
  t_client              *client;

  tmp_team = server->teams;
  while (tmp_team != NULL)
    {
      tmp_client = ((t_team *)tmp_team->data)->clients;
      while (tmp_client != NULL)
	{
	  client = ((t_client *)tmp_client->data);
	  if (client->sd)
	    close(client->sd);
	  tmp_client = tmp_client->next;
	}
      tmp_team = tmp_team->next;
    }
  close(server->master_socket);
  dprintf(1, "Exiting server\n");
}
