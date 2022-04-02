/*
** main.c for main in /home/deneub_s/PSU_2016_zappy/client
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Mon Jun 19 17:19:42 2017 Stanislas Deneubourg
** Last update Sat Jul  1 14:55:56 2017 Stanislas Deneubourg
*/

#include "ai.h"

void 	error()
{
  fprintf(stderr, "%s\n", strerror(errno));
  exit(EXIT_FAILURE);
}

int		connect_with_server(t_client *client, char **argv)
{
  struct sockaddr_in    addr;
  int                   port;
  struct hostent	*server;

  if (client == NULL)
    return (0);
  port = client->port;
  if ((client->sd = socket(AF_INET, SOCK_STREAM, 6)) == -1)
    exit(EXIT_FAILURE);
  if ((server = gethostbyname(argv[6])) == NULL)
    {
      dprintf(2, "%s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  memset((char *)&addr, 0, sizeof(addr));
  memcpy((char *)&addr.sin_addr.s_addr, server->h_addr, server->h_length);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  if (connect(client->sd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
      dprintf(2, "%s\n", strerror(errno));
      close(client->sd);
      exit(EXIT_FAILURE);
    }
  return (1);
}

int		main(int argc, char **argv)
{
  t_client	client;

  check_args(argc, argv, &client);
  connect_with_server(&client, argv);
  verify_connect(&client, argv[4]);
  init_trantorian(&client);
  ai_general_pattern(&client);
  return (0);
}
