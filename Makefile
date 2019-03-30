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

CPPFLAGS=	-ldl

all: 		core games graphicals

core: 		$(OBJ)
			$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)

games:
			make -C games/Test/

graphicals:
			make -C lib/Ncurses/
			make -C lib/SFML/

clean:
			$(RM) $(OBJ)
			make clean -C lib/Ncurses/
			make clean -C lib/SFML/
			make clean -C games/Test/

fclean: 	clean
			$(RM) $(NAME)
			make fclean -C lib/Ncurses/
			make fclean -C lib/SFML/
			make fclean -C games/Test/

re: 		fclean all

.PHONY: 	all core games graphicals fclean clean re