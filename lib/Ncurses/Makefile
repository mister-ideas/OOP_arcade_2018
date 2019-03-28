##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC_DIR=	src/

SRC=		$(SRC_DIR)Ncurses.cpp

OBJ=		$(SRC:.cpp=.o)

NAME=		lib_arcade_ncurses.so

CXXFLAGS=	-Wall -Wextra -Werror -std=c++17 -lncurses

CPPFLAGS=	-I .

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CXXFLAGS) $(SRC) -shared -fPIC -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
