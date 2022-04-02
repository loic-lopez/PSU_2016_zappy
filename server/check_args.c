/*
** check_args.c for check_args in /home/piazza_p/rendu/PSU_2016_zappy
** 
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
** 
** Started on  Fri Jun 16 17:47:59 2017 pierre piazza
** Last update Sun Jul  2 22:10:05 2017 pierre piazza
*/

#include "server.h"

int		print_usage(char *bin)
{
  dprintf(1, "USAGE: %s -p port -x width -y height ", bin);
  dprintf(1, "-n name1 name2 ... -c clientsNb -f freq\n");
  return (1);
}

void		print_help(char *bin)
{
  print_usage(bin);
  dprintf(1, "\tport\t\tis the port number\n");
  dprintf(1, "\twidth\t\tis the width of the world\n");
  dprintf(1, "\theight\t\tis the height of the world\n");
  dprintf(1, "\tnameX\t\tis the name of the team X\n");
  dprintf(1, "\tclientsNb\tis the number of authorized clients per team\n");
  dprintf(1, "\tfreq\t\tis the reciprocal of time unit for execution of \
actions\n");
  exit(0);
}

void		add_graphical_team(t_serv *server)
{
  t_team	*tmp;

  if ((tmp = malloc(sizeof(t_team))) == NULL)
    exit(1);
  memset(tmp->name, 0, 255);
  tmp->nbr_clients_remaining = 0;
  tmp->clients = NULL;
  tmp->eggs = NULL;
  tmp->clients_waiting = NULL;
  push_back(&server->teams, tmp);
}

void		store_data(int ac, char **av, t_serv *serv)
{
  int		i;
  t_team	*tmp;

  i = 7;
  if (((serv->port = atoi(av[2])) <= 0)
      || ((serv->map.width = atoi(av[4])) <= 0)
      || ((serv->map.height = atoi(av[6])) <= 0)
      || ((serv->max_clients_per_team = atoi(av[ac - 3])) <= 0)
      || ((serv->freq = atof(av[ac - 1])) <= 0))
    exit(print_usage(av[0]));
  serv->teams = NULL;
  add_graphical_team(serv);
  while (++i < ac - 4)
    {
      if ((tmp = malloc(sizeof(t_team))) == NULL)
	exit(1);
      memset(tmp->name, 0, 255);
      strcpy(tmp->name, av[i]);
      tmp->nbr_clients_remaining = serv->max_clients_per_team;
      tmp->clients = NULL;
      tmp->eggs = NULL;
      tmp->clients_waiting = NULL;
      push_back(&serv->teams, tmp);
    }
}

void		check_args(int ac, char **av, t_serv *serv)
{
  if (ac == 2 && strcmp(av[1], "-help") == 0)
    print_help(av[0]);
  else if (ac < 13)
    {
      print_usage(av[0]);
      exit(1);
    }
  else
    {
      if (strcmp(av[1], "-p") != 0 || strcmp(av[3], "-x") != 0 ||
	  strcmp(av[5], "-y") != 0 || strcmp(av[7], "-n") != 0 ||
	  strcmp(av[ac - 4], "-c") != 0 || strcmp(av[ac - 2], "-f") != 0)
	{
	  print_usage(av[0]);
	  exit(1);
	}
      else
	store_data(ac, av, serv);
    }
}
