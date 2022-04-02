/*
** ai.h for ai in /home/deneub_s/PSU_2016_zappy
** 
** Made by Stanislas Deneubourg
** Login   <deneub_s@epitech.net>
** 
** Started on  Wed Jun 21 10:39:44 2017 Stanislas Deneubourg
** Last update Sat Jul  1 11:41:27 2017 Stanislas Deneubourg
*/

#ifndef		AI_H
# define	AI_H

# include	<pthread.h>
# include	<arpa/inet.h>
# include	<errno.h>
# include	<netdb.h>
# include	<netinet/in.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<time.h>
# include	<fcntl.h>
# include	<sys/socket.h>
# include	<sys/time.h>
# include	<sys/types.h>
# include	<unistd.h>
# include	<stdbool.h>
# include       "get_next_line.h"

typedef	struct	s_inventory
{
  size_t        food;
  size_t        linemate;
  size_t        deraumere;
  size_t        sibur;
  size_t        mendiane;
  size_t        phiras;
  size_t        thystame;
}		t_inventory;

typedef struct	s_look
{
  t_inventory	ahead;
  int		player;
  int		coor;
  struct s_look	*prev;
  struct s_look	*next;
}		t_look;

typedef	struct	s_client
{
  int		port;
  char		ip_address[255];
  int		sd;
  size_t	level;
  size_t	turns_left;
  int		nb_cases;

  char		team_name[255];
  t_inventory	inventory;
  t_look	*look;
  bool		search_player;
  int		broad_dir;
}		t_client;

int             connect_with_server(t_client *, char **av);
void		error();
void            check_args(int, char **, t_client *);
void            store_data(char **, t_client *);
void            print_help(char *);
int             print_usage(char *);
void            free_tab(char **);
void		init_trantorian(t_client *);
void		init_inventory(t_inventory *);
void		verify_connect(t_client *, char *);
void		ai_general_pattern(t_client *);
int		ai_determine_pattern_to_follow(t_client *);
void		ai_check_elevation(t_client *);
void		ai_try_elevation_to_level_2(t_client *);
void		ai_execute_elevation_to_level_2(t_client *);
void		ai_put_ressources_to_level_2(t_client *);
void		ai_try_elevation_to_level_3(t_client *);
void		ai_execute_elevation_to_level_3(t_client *);
void		ai_put_ressources_to_level_3(t_client *);
void		ai_try_elevation_to_level_4(t_client *);
void		ai_execute_elevation_to_level_4(t_client *);
void		ai_put_ressources_to_level_4(t_client *);
void		ai_try_elevation_to_level_5(t_client *);
void		ai_execute_elevation_to_level_5(t_client *);
void		ai_put_ressources_to_level_5(t_client *);
void		ai_try_elevation_to_level_6(t_client *);
void		ai_execute_elevation_to_level_6(t_client *);
void		ai_put_ressources_to_level_6(t_client *);
void		ai_try_elevation_to_level_7(t_client *);
void		ai_execute_elevation_to_level_7(t_client *);
void		ai_put_ressources_to_level_7(t_client *);
void		ai_try_elevation_to_level_8(t_client *);
void		ai_execute_elevation_to_level_8(t_client *);
void		ai_put_ressources_to_level_8(t_client *);
char		**my_str_to_wordtab(char *, char);
void		ai_treat_look(t_client *, char *);
void		ai_look(t_client *);
void            ai_treat_inventory(t_client *, char *);
void		ai_inventory(t_client *);
int		ai_search_for(t_client *, char *);
void		link_list(t_look **, char *, int);
void		fill_look(t_look *, char *, int);
void		init_look(t_look *);
void		ai_locate_seen_object(t_client *, char *, int, int);
int		ai_get_line_center(int);
char		ai_get_object_direction(int, int);
void            ai_take_object(t_client *, char *);
void            print_list(t_look *);
void            print_inventory(t_client *);
void		get_receive(t_client *, char[40960]);
void		to_find_line(t_client *, char *, int);
int		is_object_found(t_client *, char *, int, int);
void		reset_list(t_client *);
void		move_to_object(t_client *, char, int);
void		move_farther_than_view_range_to_search_further(t_client *);
void		turn_left_front_to_object(t_client *, int);
void		turn_right_front_to_object(t_client *, int);
void		ai_set_object(t_client *, char *);
void		ai_send_broadcast_text(t_client *, char *);
void		ai_hear_broadcast_text(t_client *);
void		moveto(t_client *, char *);
void		pre_move_player(t_client *);
int		follow_broadcast(t_client *);
void		assemble_buffer(char [40960], char [40960]);
int		is_buffer_full(int, char [40960], char [40960]);
int             receive_failed(char [40960]);

#endif
