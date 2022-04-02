/*
** check_args.c for check_args in /home/piazza_p/rendu/PSU_2016_zappy
** 
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
** 
** Started on  Fri Jun 16 17:47:59 2017 pierre piazza
** Last update Mon Jun 26 11:57:12 2017 Stanislas Deneubourg
*/

#include "ai.h"

int		print_usage(char *bin)
{
  dprintf(1, "USAGE: %s -p port -n name -h machine\n", bin);
  return (1);
}

void		print_help(char *bin)
{
  print_usage(bin);
  dprintf(1, "\tport\t\tis the port number\n");
  dprintf(1, "\tname\t\tis the name of the team\n");
  dprintf(1, "\tmachine\t\tis the name of the machine; ");
  dprintf(1, "localhost by default\n");
  exit(0);
}

void		store_data(char **av, t_client *client)
{
  client->port = atoi(av[2]);
  strcpy(client->team_name, av[4]);
}

void		check_args(int ac, char **av, t_client *client)
{
  if (ac == 2 && strcmp(av[1], "-help") == 0)
    print_help(av[0]);
  else if (ac != 7)
    {
      print_usage(av[0]);
      exit(1);
    }
  else
    {
      if (strcmp(av[1], "-p") != 0 || strcmp(av[3], "-n") != 0
	  || strcmp(av[1], "-p") != 0 || strcmp(av[3], "-n") != 0
	  || strcmp(av[5], "-h") != 0)
	{
	  print_usage(av[0]);
	  exit(1);
	}
      else
	store_data(av, client);
    }
}
