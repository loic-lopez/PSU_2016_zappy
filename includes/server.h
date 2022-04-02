/*
** server.h for server in /home/piazza_p/rendu/PSU_2016_zappy
** 
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
** 
** Started on  Mon May 29 15:29:25 2017 pierre piazza
** Last update Fri Jun 30 16:30:37 2017 pierre piazza
*/

#ifndef SERVER_H__
# define SERVER_H__

# include <arpa/inet.h>
# include <errno.h>
# include <netinet/in.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>
# include "map.h"
# include "linkList.h"

# define WIDTH server->map.width
# define HEIGHT server->map.height
# define ABSWIDTH(a) ((a + WIDTH) % WIDTH)
# define ABSHEIGHT(a) ((a + HEIGHT) % HEIGHT)
# define ARENA server->map.field

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef t_tile		t_inventory;

typedef enum		server_command
{
  FORWARD	=	0,
  RIGHT		=	1,
  LEFT		=	2,
  LOOK		=	3,
  INVENTORY	=	4,
  BROADCAST_TEXT = 	5,
  CONNECT_NBR	=	6,
  FORK		=	7,
  EJECT		=	8,
  TAKE_OBJECT	=	9,
  SET_OBJECT	=	10,
  INCANTATION	=	11
}			server_command;

typedef enum		graphical_server_command
{
  MSZ		=	0,
  BCT		=	1,
  MCT		=	2,
  TNA		=	3,
  PPO		=	4,
  PLV		= 	5,
  PIN		=	6,
  SGT		=	7,
  SST		=	8,
}			graphical_server_command;

typedef enum 		client_orientation
{
  NORTH		=	0,
  EAST		=	1,
  SOUTH		=	2,
  WEST		=	3
}			client_orientation;

typedef struct		s_cmd
{
  char			cmd[255];
  int			delay;
  server_command	type;
}			t_cmd;

typedef struct		s_client
{
  int			sd;
  t_inventory		inv;
  server_command	cmd;
  client_orientation	orientation;
  size_t		pos_x;
  size_t		pos_y;
  short 		lvl;
  t_vector		*cmds;
  bool			is_graphical_client;
  size_t		id;
}			t_client;

typedef struct		s_egg
{
  size_t		pos_x;
  size_t		pos_y;
  int			delay;
}			t_egg;

typedef struct		s_team
{
  char			name[255];
  int 			nbr_clients_remaining;
  t_vector		*clients;
  t_vector		*eggs;
  t_vector		*clients_waiting;
}			t_team;

typedef struct		s_serv
{
  int			port;
  int			master_socket;
  fd_set		rs;
  fd_set		ws;
  fd_set		es;
  int			max_sd;
  struct sockaddr_in	addr;
  int			addrlen;
  t_map			map;
  int			max_clients_per_team;
  float			freq;
  t_vector		*teams;
  size_t		max_id;
}			t_serv;

bool			sig_ret;

void			spawn_ressources(t_serv *server);
void			check_args(int, char **, t_serv *);
void			launch_server(t_serv *server);
void			launch_client_demand(t_serv *server,
				 t_client *current_client, char *cmd);
void			add_user(t_serv *server,
				 bool *team_found,
				 char *team_name,
				 int new_client_socket);
void			execute_client_demand(t_serv *server,
					      t_client *current_client,
					      char *cmd);
void			execute_forward(t_serv *server,
					t_client *current_client,
					char *cmd);
void			execute_right(t_serv *server,
				      t_client *current_client,
				      char *cmd);
void			execute_left(t_serv *server,
				     t_client *current_client,
				     char *cmd);
void			execute_look(t_serv *server,
				     t_client *current_client,
				     char *cmd);
void			execute_inventory(t_serv *server,
					  t_client *current_client,
					  char *cmd);
void			execute_broadcast_text(t_serv *server,
					       t_client *current_client,
					       char *cmd);
void			execute_connect_nbr(t_serv *server,
					    t_client *current_client,
					    char *cmd);
void			execute_fork(t_serv *server,
				     t_client *current_client,
				     char *cmd);
void			execute_forward_north(t_serv *server,
					      t_client *current_client);
void			execute_forward_south(t_serv *server,
					      t_client *current_client);
void			execute_forward_east(t_serv *server,
					     t_client *current_client);
void			execute_forward_west(t_serv *server,
					     t_client *current_client);
void			execute_eject(t_serv *server,
				      t_client *current_client,
				      char *cmd);
int			find_which_ressource(char *cmd);
void			execute_take_object(t_serv *server,
						t_client *current_client,
						char *cmd);
void			execute_set_object(t_serv *server,
					   t_client *current_client,
					       char *cmd);
int			how_many_players(t_serv *server,
					 t_client *current_client);
bool			lvl1_2(t_serv *server, t_client *current_client,
				   bool erase);
bool			lvl2_3(t_serv *server, t_client *current_client,
				   bool erase);
bool			lvl3_4(t_serv *server, t_client *current_client,
				   bool erase);
bool			lvl4_5(t_serv *server, t_client *current_client,
				   bool erase);
bool			lvl5_6(t_serv *server, t_client *current_client,
				   bool erase);
bool			lvl6_7(t_serv *server, t_client *current_client,
				   bool erase);
bool			lvl7_8(t_serv *server, t_client *current_client,
				   bool erase);
void			put_client_in_team_if_not_egg_delay(t_serv *server);
void			update_client_delay(t_serv *server);
bool			checking_client_possibility(t_serv *server,
						    t_client *current_client,
						    char *cmd,
						    server_command type);
void			check_tile(t_tile, t_client *);
void			list_elem(size_t, char *, t_client *);
void			killall(t_serv *);
void			sig_handler(int);
void			init_map_sound(t_serv *server,
				       t_client *client);
bool			find_stop(char *sound,
				  int *where,
				  int ite,
				  bool *stop);
void			diagonal_left_up_earch(t_pos destination,
					       t_serv *server,
					       int *distance);

void			diagonal_right_up_earch(t_pos destination,
						t_serv *server,
						int *distance);
void			diagonal_right_down_earch(t_pos destination,
						  t_serv *server,
						  int *distance);
void                    diagonal_left_down_earch(t_pos destination,
						 t_serv *server,
						 int *distance);

void			printsoundtable(t_serv *server);
void			horizontal_search(t_pos destination,
					  t_serv *server,
					  int *distance);
void			vertical_search(t_pos destination,
					t_serv *server,
					int *distance);
void			execute_broadcast_text(t_serv *server,
				       t_client *current_client, char *cmd);
void			execute_fork(t_serv *server,
					 t_client *current_client, char *cmd);
bool			remove_food(t_serv *server, t_client *client);
void			add_graphical_user(t_serv *server,
					       int new_client_socket);
void			launch_graphical_client_demand(t_serv *server,
							   t_client
							   *current_client,
							   char *cmd);
void			find_typ(server_command *type,
				     bool *is_valid_command, int i);
void			execute_bct(t_serv *server,
					t_client *current_client, char *cmd);
void			execute_tna(t_serv *server,
					t_client *current_client, char *cmd);
void			execute_sgt(t_serv *server,
					t_client *current_client, char *cmd);
void			execute_msz(t_serv *server,
					t_client *current_client, char *cmd);
void			execute_mct(t_serv *server,
					t_client *current_client, char *cmd);
void			execute_sst(t_serv *server,
					t_client *current_client, char *cmd);
void			execute_pin(t_serv *server,
					t_client *current_client, char *cmd);
void			execute_plv(t_serv *server,
					t_client *current_client, char *cmd);
void			execute_ppo(t_serv *server,
					t_client *current_client, char *cmd);
void			print_infos_on_graphic_clients(t_client *new_client,
							   t_serv *server,
							   t_team *team);
void			print_graphic_connected_clients(t_serv *server,
							    t_client
							    *new_client);
void			print_graphical_modify_ressources(t_serv *server,
					      t_client *current_client,
					      t_client *graph_client);
void			print_all_graphical_modify_ressources(t_serv *server,
						  t_client *current_client);
void			execute_pic(t_serv *server, t_client *current_client);
void			execute_pie(t_serv *server,
					t_client *current_client, int status);
bool			check_timer(struct timespec end,
				    struct timespec start,
				    t_serv *server);
void			init_gettime(struct timespec *start,
				     struct timeval *delay,
				     t_serv *server);
void			update_cooldown(int *cooldown, t_serv *server);
void			set_fds(t_serv *server);
void			loop_on_team(t_serv *server);
void			remove_client(t_serv *server, t_client *client,
				      bool graph);
void			wait_clients(t_serv *server);
void			incomming_connection(t_serv *server);

#endif
