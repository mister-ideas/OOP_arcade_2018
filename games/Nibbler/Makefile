##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC_DIR=	src/

SRC=		$(SRC_DIR)Snake.cpp			\
			$(SRC_DIR)SnakeGame.cpp		\
			$(SRC_DIR)Goal.cpp			\
			$(SRC_DIR)Location.cpp		\
			$(SRC_DIR)Board.cpp			\
			../$(SRC_DIR)Map.cpp

OBJ=		$(SRC:.cpp=.o)

NAME=		lib_arcade_nibbler.so

CXXFLAGS=	-Wall -Wextra -Werror -std=c++17

CPPFLAGS=	-I .

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $(SRC) -shared -fPIC -o $(NAME)
			mv $(NAME) ../

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) ../$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
