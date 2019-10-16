##
## EPITECH PROJECT, 2017
## My_PrintF
## File description:
## Printf
##

## Names

NAME	=		libprintf.a

## Utilitaries

CC		?=	gcc
MAKE		?=	/usr/bin/make
RM		?=	rm -rf

## Sources

SRC_DIR		=	.
OBJ		=	$(SRC:.c=.o)
SRC	=		$(SRC_DIR)/my_printf.c		\
			$(SRC_DIR)/my_printf_char.c	\
			$(SRC_DIR)/my_printf_nbr.c	\
			$(SRC_DIR)/my_printf_plus.c	\
			$(SRC_DIR)/my_putchar.c		\
			$(SRC_DIR)/my_put_nbr.c		\
			$(SRC_DIR)/my_putstr.c		\
			$(SRC_DIR)/my_revstr.c		\
			$(SRC_DIR)/my_strlen.c		\

## Flags

CFLAGS		+=	-Wall -Wextra -I./
CPPFLAGS	+=
LDFLAGS		+=

## Rules

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv ./$(NAME) ../../

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) ../../$(NAME)

re:		fclean all

.PHONY:		re all fclean clean
