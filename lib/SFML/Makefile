##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC_DIR=	src/

SRC=		$(SRC_DIR)SFML.cpp			\
			../../$(SRC_DIR)Error.cpp

OBJ=		$(SRC:.cpp=.o)

NAME=		lib_arcade_sfml.so

CXXFLAGS=	-Wall -Wextra -Werror -std=c++17

CPPFLAGS=	-I .

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $(SRC) -lsfml-graphics -shared -fPIC -o $(NAME)
			mv $(NAME) ../

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) ../$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
