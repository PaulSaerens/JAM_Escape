##
## EPITECH PROJECT, 2020
## JAM_escape_2019
## File description:
## Makefile
##

CC	=	gcc

SRC	=	main.c			\
		./src/open_map.c	\
		./src/fill_map.c	\
		./src/display_map.c	\
		./src/move_player.c	\
		./src/move_direction.c	\
		./src/win_or_lose.c	\
		./src/check_validity.c	\
		./src/my_strlen.c	\
		./src/my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	Escape

all:	$(NAME)

CFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm -I./include

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
