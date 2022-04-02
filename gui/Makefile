##
## Makefile for Makefile in /home/jabbar_y/rendu/PSU_2016_zappy/gui
## 
## Made by Jabbari Yassir
## Login   <jabbar_y@epitech.net>
## 
## Started on  Mon Jun 26 10:40:11 2017 Jabbari Yassir
## Last update Wed Jun 28 14:46:35 2017 Eric Deschodt
##

NAME            =       ../zappy_gui

SRC             =       main.cpp		\
			Parser.cpp		\
			Player.cpp		\
			Graphics.cpp		\
			SocketConnection.cpp	\
			SocketReader.cpp

OBJ             =       $(SRC:.cpp=.o)

CXXFLAGS        +=      -I../includes
CXXFLAGS        +=      -W -Wall -Wextra -Werror

LDFLAGS         +=      -lpthread

LIB		+=	-lsfml-graphics -lsfml-window -lsfml-system

CXX             =       g++
RM              =       rm -f

all             :       $(NAME)

$(NAME)         :       $(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB)

clean           :
			$(RM) $(OBJ)

fclean          :       clean
			$(RM) $(NAME)
re		:	fclean all
