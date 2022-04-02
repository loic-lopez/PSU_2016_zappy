/*
** ai_base.c for ai_base in /home/deneub_s/PSU_2016_zappy/ai
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Wed Jun 21 15:47:28 2017 Stanislas Deneubourg
** Last update Sat Jul  1 17:22:47 2017 Stanislas Deneubourg
*/

#include "ai.h"

char	*clear_string(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  while (str[i] != '\0')
	    {
	      str[i] = '\0';
	      i++;
	    }
	}
      i++;
    }
  return (str);
}

void	get_receive(t_client *client, char first_recv[40960])
{
  char	second_recv[40960];
  int	first_recv_value;
  int	second_recv_value;

  if ((first_recv_value = recv(client->sd, first_recv, 40960, 0)) < 0)
    dprintf(1, "recv failed\n");
  else
    {
      first_recv[first_recv_value] = '\0';
      clear_string(first_recv);
      if ((second_recv_value = recv(client->sd, second_recv, 40960, 0)) < 0)
	dprintf(1, "recv failed\n");
      else
	{
	  second_recv[second_recv_value] = '\0';
	  clear_string(second_recv);
	  strcat(first_recv, second_recv);
	}
    }
}

int	ai_determine_pattern_to_follow(t_client *client)
{
  int	ret;

  client->inventory.food <= 500 ? ret = ai_search_for(client, "food") :
  client->search_player == true ? ret = ai_search_for(client, "player") :
  client->inventory.linemate < 2 ? ret = ai_search_for(client, "linemate") :
  client->inventory.deraumere < 2 ? ret = ai_search_for(client, "deraumere") :
  client->inventory.sibur < 3 ? ret = ai_search_for(client, "sibur") :
  client->inventory.mendiane < 3 ? ret = ai_search_for(client, "mendiane") :
  client->inventory.phiras < 2 ? ret = ai_search_for(client, "phiras") :
  client->inventory.thystame < 1 ? ret = ai_search_for(client, "thystame") :
    0;
  return (ret);
}

void	ai_general_pattern(t_client *client)
{
  recv(client->sd, NULL, 4, 0);
  while (client->inventory.food > 0)
    {
      if (client->search_player == false)
      	ai_send_broadcast_text(client, "Broadcast No");
      ai_hear_broadcast_text(client);
      ai_inventory(client);
      ai_check_elevation(client);
      ai_look(client);
      if ((ai_determine_pattern_to_follow(client)) == -1)
	move_farther_than_view_range_to_search_further(client);
    }
}
