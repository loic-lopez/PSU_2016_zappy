/*
** remove_food.c for remove_food  in /home/piazza_p/rendu/PSU_2016_zappy
** 
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
** 
** Started on  Wed Jun 28 11:05:22 2017 pierre piazza
** Last update Thu Jun 29 13:28:15 2017 pierre piazza
*/

#include "server.h"

bool		remove_food(t_serv *server, t_client *client)
{
  t_vector	*graph_clients;
  t_client	*graph_client;

  if (client->inv.ressources[FOOD] > 0)
    {
      client->inv.ressources[FOOD]--;
      return (true);
    }
  else
    {
      dprintf(client->sd, "dead\n");
      close(client->sd);
      client->sd = 0;
      graph_clients = ((t_team *)server->teams->data)->clients;
      while (graph_clients != NULL)
	{
	  graph_client = graph_clients->data;
	  if (graph_client)
	    dprintf(graph_client->sd, "pdi %zu\n", client->id);
	  graph_clients = graph_clients->next;
	}
      return (false);
    }
}
