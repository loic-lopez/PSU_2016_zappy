##
## Makefile for Makefile in /home/jabbar_y/rendu/PSU_2016_zappy
## 
## Made by Jabbari Yassir
## Login   <jabbar_y@epitech.net>
## 
## Started on  Mon Jun 19 17:38:34 2017 Jabbari Yassir
## Last update Fri Jun 30 15:19:29 2017 Stanislas Deneubourg
##

CLIENT          =       ../zappy_ai

CSRCS           =       main.c					\
			get_next_line.c				\
			my_str_to_wordtab.c			\
			ai_verify_connect.c			\
			ai_free_tab.c				\
			ai_check_args.c				\
			ai_trantorian.c				\
			ai_base.c				\
			ai_check_elevation.c			\
			ai_elevation_to_level_2.c		\
			ai_elevation_to_level_3.c		\
			ai_elevation_to_level_4.c		\
			ai_elevation_to_level_5.c		\
			ai_elevation_to_level_6.c		\
			ai_elevation_to_level_7.c		\
			ai_elevation_to_level_8.c		\
			ai_look.c				\
			ai_inventory.c				\
			ai_search_for.c				\
			ai_search_for_utilities.c		\
			ai_set_object.c				\
			ai_move_to_search_further.c		\
			ai_broadcast_text.c			\
			ai_treatement_text.c			\
			ai_list_look.c

COBJS           =       $(CSRCS:.c=.o)

CFLAGS          +=      -W -Wall -Wextra -Werror
CFLAGS          +=      -g -I../includes -lpthread


all             :       $(CLIENT)

$(CLIENT)       :       $(COBJS)
			gcc -o $(CLIENT) $(COBJS) $(CFLAGS)

clean           :
			rm -f $(COBJS)

fclean          :       clean
			rm -f $(CLIENT)

re              :       fclean all

.PHONY          :       all clean fclean re
