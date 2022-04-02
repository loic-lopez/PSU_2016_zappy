/*
** server.c for PSU_2016_zappy in /home/lopez_i/PSU_2016_zappy/server.c
**
** Made by Loic Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  lun. juin 19 15:45:05 2017 Loic Lopez
** Last update Fri Jun 30 15:30:39 2017 Eric Deschodt
*/

#include "server.h"

int	rng_ressources()
{
  int	choice;

  choice = rand() % 100;
  return ((choice <= 30) ? LINEMATE :
	  (choice <= 50) ? DERAUMERE :
	  (choice <= 70) ? SIBUR :
	  (choice <= 80) ? MENDIANE :
	  (choice <= 90) ? PHIRAS : THYSTAME);
}

void		update_graphical_ressources(t_serv *server)
{
  t_vector      *graph_clients;
  t_client      *graph_client;

  graph_clients = ((t_team *)server->teams->data)->clients;
  while (graph_clients != NULL)
    {
      graph_client = graph_clients->data;
      if (graph_client)
	execute_mct(server, graph_client, NULL);
      graph_clients = graph_clients->next;
    }
}

void		spawn_ressources(t_serv *server)
{
  int		i;
  int		j;
  int		nb;
  int		rng;

  i = -1;
  while (++i < (int)HEIGHT)
    {
      j = -1;
      while (++j < (int)WIDTH)
	{
	  nb = rand() % 4;
	  while (--nb >= 0)
	    {
	      rng = rng_ressources();
	      if (ARENA[i][j].ressources[rng] < 21)
		ARENA[i][j].ressources[rng] += 1;
	    }
	  ARENA[i][j].ressources[FOOD] += (rand() % 3 == 0) ? 1 : 0;
	}
    }
  update_graphical_ressources(server);
}
