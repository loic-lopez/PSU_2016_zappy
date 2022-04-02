##
## Makefile for  in /home/descho_e/tek2/PSU_2016_zappy
## 
## Made by Eric Deschodt
## Login   <descho_e@epitech.net>
## 
## Started on  Thu Jun 15 17:31:51 2017 Eric Deschodt
## Last update Mon Jun 26 13:53:23 2017 Jabbari Yassir
##

MAKE		=	@make --no-print-directory

all		:
			$(MAKE) all -C server
			$(MAKE) all -C ai
			$(MAKE) all -C gui

zappy_server	:
			$(MAKE) all -C server

zappy_ai	:
			$(MAKE) all -C ai

zappy_gui	:
			$(MAKE) all -C gui

clean		:
			$(MAKE) clean -C server
			$(MAKE) clean -C ai
			$(MAKE) clean -C gui

fclean		:
			$(MAKE) fclean -C server
			$(MAKE) fclean -C ai
			$(MAKE) fclean -C gui

re		:	fclean all
