##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC_DIR=	src/

SRC=		$(SRC_DIR)Core.cpp		\
			$(SRC_DIR)Error.cpp		\
			$(SRC_DIR)main.cpp

OBJ=		$(SRC:.cpp=.o)

NAME=		arcade

CXXFLAGS=	-Wall -Wextra -Werror -std=c++17

CPPFLAGS=	-ldl -I include/

all: 		core games graphicals

core: 		$(OBJ)
			$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)

games:

graphicals:
			make -C lib/Ncurses/

clean:
			$(RM) $(OBJ)
			make clean -C lib/Ncurses/

fclean: 	clean
			$(RM) $(NAME)
			make fclean -C lib/Ncurses/

re: 		fclean all

.PHONY: 	all fclean clean re