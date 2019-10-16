##
## EPITECH PROJECT, 2017
## My_lib
## File description:
## Libmy
##

## Names

NAME		=	libmy.a

## Utilitaries

CC		?=	gcc
MAKE		?=	/usr/bin/make
RM		?=	rm -rf

## Sources

SRC_DIR		=	.
OBJ		=	$(SRC:.c=.o)
SRC		=	$(SRC_DIR)/free_tab.c			\
			$(SRC_DIR)/get_next_line.c		\
			$(SRC_DIR)/my_atof.c			\
			$(SRC_DIR)/my_atoi.c			\
			$(SRC_DIR)/my_itoa.c			\
			$(SRC_DIR)/my_len.c			\
			$(SRC_DIR)/my_memset.c			\
			$(SRC_DIR)/my_str_word_tab.c		\
			$(SRC_DIR)/my_pass_charac.c		\
			$(SRC_DIR)/my_strcat.c			\
			$(SRC_DIR)/my_strcmp.c			\
			$(SRC_DIR)/my_strcpy.c			\

## Flags

CFLAGS		+=	-Wall -Wextra -I./
CPPFLAGS	+=
LDFLAGS		+=

## Rules

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc  $(NAME) $(OBJ) $(CPPFLAGS)
	mv ./$(NAME) ../
	cp libmy.h ../../include

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) ../$(NAME)
	$(RM) ../../include/libmy.h

re:		fclean all

.PHONY:		re all fclean clean
