##
## Makefile for Makefile in /home/piazza_p/rendu/PSU_2016_zappy
## 
## Made by pierre piazza
## Login   <piazza_p@epitech.net>
## 
## Started on  Mon May 29 15:25:17 2017 pierre piazza
## Last update Fri Jun 30 15:38:44 2017 Eric Deschodt
##

SERVER		=	../zappy_server

SSRCS		=	main.c					\
			linkList.c				\
			check_args.c				\
			server.c				\
			server_utils.c				\
			add_user.c				\
			launch_client_demand.c			\
			execute_client_demand.c			\
			execute_client_move.c			\
			execute_client_utils.c			\
			execute_client_fork.c			\
			init_map_sound.c			\
			sound_straight.c			\
			execute_client_broadcast.c		\
			execute_client_broad_up_left.c		\
			execute_client_broad_down_left.c	\
			execute_client_broad_up_right.c		\
			execute_client_broad_down_right.c	\
			execute_client_forwards.c		\
			execute_client_eject.c			\
			execute_client_objects.c		\
			execute_client_how_many.c		\
			execute_client_incantation.c		\
			execute_client_looking.c		\
			execute_client_delay.c			\
			check_client_possibility.c		\
			check_errors.c				\
			put_client_in_team_if_not_egg_delay.c 	\
			map.c					\
			launch_graphical_client_demand.c 	\
			execute_graphical_client_time.c 	\
			execute_graphical_client_position.c 	\
			execute_graphical_client_utils.c	\
			remove_food.c				\
			print_info_graphic_clients.c		\
			print_graphical_modify_ressources.c	\
			spawn_ressources.c			\
			execute_ppo.c				\
			wait_clients.c

SOBJS		=	$(SSRCS:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -Werror
CFLAGS		+=	-I../includes -g


all		:	$(SERVER)

$(SERVER)	:	$(SOBJS)
			gcc -o $(SERVER) $(SOBJS) $(CFLAGS)

clean		:
			rm -f $(SOBJS)

fclean		:	clean
			rm -f $(SERVER)

re		:	fclean all

.PHONY		:	all clean fclean re
