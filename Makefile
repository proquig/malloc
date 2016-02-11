##
## Makefile for Makefile in /home/jacque_x/rendu/PSU_2015_malloc
## 
## Made by JACQUET Vincent
## Login   <jacque_x@epitech.net>
## 
## Started on  Mon Feb  1 10:05:19 2016 JACQUET Vincent
## Last update Thu Feb 11 09:56:58 2016 Guillaume PROQUIN
##

SRC	=	src/malloc.c	\
		src/mem.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -fPIC \
		-I include/

NAME	=	libmy_malloc.so

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -shared

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
