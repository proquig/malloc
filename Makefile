##
## Makefile for Makefile in /home/jacque_x/rendu/PSU_2015_malloc
## 
## Made by JACQUET Vincent
## Login   <jacque_x@epitech.net>
## 
## Started on  Mon Feb  1 10:05:19 2016 JACQUET Vincent
## Last update Mon Feb  1 10:40:01 2016 JACQUET Vincent
##

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

NAME	=	malloc

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all


