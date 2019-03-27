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

CXXFLAGS=	-Wall -Wextra -Werror

CPPFLAGS=	-ldl -I include/

all: 		core games graphicals

core: 		$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(CFLAGS) $(CPPFLAGS)

games:

graphicals:

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all fclean clean re
