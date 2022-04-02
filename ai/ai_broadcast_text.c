/*
** ai_broadcast_text.c for broadcast text in /home/deneub_s/PSU_2016_zappy
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Wed Jun 28 09:24:02 2017 Stanislas Deneubourg
** Last update Sat Jul  1 11:42:43 2017 Stanislas Deneubourg
*/

#include "ai.h"

void	ai_send_broadcast_text(t_client *client, char *cmd)
{
  char *server_answer;

  dprintf(client->sd, "%s\n", cmd);
  if ((server_answer = get_next_line(client->sd)) != NULL)
    if (strcmp(server_answer, "ok") == 0)
      free(server_answer);
}

void	moveto(t_client *client, char *cmd)
{
  char	*server_answer;

  dprintf(client->sd, "%s\n", cmd);
  if ((server_answer = get_next_line(client->sd)) != NULL)
    if (strcmp(server_answer, "ok") == 0)
      free(server_answer);
}

void	pre_move_player(t_client *client)
{
   client->broad_dir == 1 ? moveto(client, "Forward") :
    client->broad_dir == 2 ? moveto(client, "Forward"),
    moveto(client, "Left"), moveto(client, "Forward") :
    client->broad_dir == 3 ? moveto(client, "Left"),
    moveto(client, "Forward") :
    client->broad_dir == 4 ? moveto(client, "Left"),
    moveto(client, "Forward"), moveto(client, "Left"),
    moveto(client, "Forward") :
    client->broad_dir == 5 ? moveto(client, "Right"),
    moveto(client, "Right"), moveto(client, "Forward") :
    client->broad_dir == 6 ? moveto(client, "Right"),
    moveto(client, "Forward"), moveto(client, "Right"),
    moveto(client, "Forward") :
    client->broad_dir == 7 ? moveto(client, "Right"),
    moveto(client, "Forward") :
    client->broad_dir == 8 ? moveto(client, "Forward"),
    moveto(client, "Right"), moveto(client, "Forward") : 0;
}

int	follow_broadcast(t_client *client)
{
  pre_move_player(client);
  ai_look(client);
  reset_list(client);
  if (client->look->coor == 0 && client->look->player > 0)
    return (0);
  else
    return (-1);
}

void	ai_hear_broadcast_text(t_client *client)
{
  char result[40960];
  char builder[40960];
  char buffer[40960];
  int	reception;

  memset(buffer, 0, 40960);
  reception = recv(client->sd, buffer, sizeof(buffer), MSG_DONTWAIT);
  while (reception != 0)
    {
      if (reception < 0 && errno == EAGAIN)
	assemble_buffer(builder, buffer);
      else if (reception < 0)
	{
	  if (receive_failed(builder) == -1)
	    return;
	}
      else
	if (is_buffer_full(reception, buffer, builder) == 0)
	  break;
      memset(buffer, 0, 40960);
      reception = recv(client->sd,  buffer, sizeof(buffer), MSG_DONTWAIT);
    }
  memcpy(result, builder, 40960);
  memset(builder, 0, 40960);
}
