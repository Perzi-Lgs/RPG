##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	my_rpg

CC	=	gcc

MAKE	=	/usr/bin/make

SRC_DIR	=	./sources

LIB_DIR	=	./lib/my

SRC	=	$(SRC_DIR)/main.c				\
		$(SRC_DIR)/scenes.c				\
		$(SRC_DIR)/events.c				\
		$(SRC_DIR)/event_quest.c			\
		$(SRC_DIR)/window.c				\
		$(SRC_DIR)/click_button.c			\
		$(SRC_DIR)/button_fct.c				\
		$(SRC_DIR)/move_character.c			\
		$(SRC_DIR)/utils.c				\
		$(SRC_DIR)/view.c				\
		$(SRC_DIR)/button_fonctions.c			\
		$(SRC_DIR)/inv/inv_menu.c			\
		$(SRC_DIR)/inv/inv_events.c			\
		$(SRC_DIR)/inv/inventory.c			\
		$(SRC_DIR)/inv/set_items.c			\
		$(SRC_DIR)/inv/move_inventory.c			\
		$(SRC_DIR)/pause_menu/pause_menu.c		\
		$(SRC_DIR)/pause_menu/pause_events.c		\
		$(SRC_DIR)/pause_menu/create_pause.c		\
		$(SRC_DIR)/pause_menu/display_pause.c		\
		$(SRC_DIR)/display/display_sprite.c		\
		$(SRC_DIR)/display/draw_settings.c		\
		$(SRC_DIR)/display/display_floor_sprites.c	\
		$(SRC_DIR)/display/display_inv_sprites.c	\
		$(SRC_DIR)/create/create_floor_sprites.c	\
		$(SRC_DIR)/create/init_values_menu.c		\
		$(SRC_DIR)/create/create_inv_sprites.c		\
		$(SRC_DIR)/create/create_sprites.c		\
		$(SRC_DIR)/create/create_iso_point.c		\
		$(SRC_DIR)/create/create_2D_map.c		\
		$(SRC_DIR)/create/create_main_menu.c		\
		$(SRC_DIR)/create/init_main_menu_vertex.c	\
		$(SRC_DIR)/create/create_chara.c		\
		$(SRC_DIR)/create/create_text.c			\
		$(SRC_DIR)/create/create_btg.c			\
		$(SRC_DIR)/new_game/draw_2D_map_print.c		\
		$(SRC_DIR)/new_game/new_level.c			\
		$(SRC_DIR)/new_game/choose_player_name.c	\
		$(SRC_DIR)/new_game/draw_2D_map.c		\
		$(SRC_DIR)/new_game/init_map.c			\
		$(SRC_DIR)/new_game/init_world.c		\
		$(SRC_DIR)/new_game/start_game.c		\
		$(SRC_DIR)/new_game/parser_coord.c		\
		$(SRC_DIR)/settings/settings.c			\
		$(SRC_DIR)/settings/sound_settings.c		\
		$(SRC_DIR)/parsing/items/create_armors.c	\
		$(SRC_DIR)/parsing/items/fill_sword.c		\
		$(SRC_DIR)/parsing/items/malloc_items.c		\
		$(SRC_DIR)/parsing/monsters/create_monsters.c	\
		$(SRC_DIR)/parsing/monsters/fill_mobs.c		\
		$(SRC_DIR)/parsing/monsters/malloc_mobs.c	\
		$(SRC_DIR)/fight_scene/fight_init.c		\
		$(SRC_DIR)/fight_scene/fight_loop.c		\
		$(SRC_DIR)/fight_scene/find_mob.c		\
		$(SRC_DIR)/mob_encounter/find_mob.c		\
		$(SRC_DIR)/particules/atk_mob.c			\
		$(SRC_DIR)/particules/atk_player.c		\
		$(SRC_DIR)/particules/particule.c		\
		$(SRC_DIR)/particules/setting_particules.c

SRCLIB	=	$(LIB_DIR)/my_putstr_error.c	\
		$(LIB_DIR)/my_strlen.c		\
		$(LIB_DIR)/get_next_line.c	\
		$(LIB_DIR)/my_itoa.c		\
		$(LIB_DIR)/my_atoi.c		\
		$(LIB_DIR)/my_revstr.c		\
		$(LIB_DIR)/int_to_array.c	\
		$(LIB_DIR)/my_getnbr.c

OBJ2	=	$(SRCLIB:.c=.o)

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CPPFLAGS += 	-I ./include/

CFLAGS	+=	-Wall -Wextra

INCLUDE	=	-L./lib -lmy -lmy2 -lm -lsfml-graphics -lsfml-window -lsfml-system -lcsfml-audio

all:		$(NAME)

$(NAME):	lib $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(INCLUDE)

lib:		$(OBJ2)
		ar rc libmy2.a $(OBJ2)
		mv ./libmy2.a ./lib/
		$(MAKE) -C lib/mylib_c
		$(MAKE) -C lib/printf/my

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJ2)

fclean:		clean
		$(RM) $(NAME)
		$(MAKE) fclean -C ./lib/printf/my
		$(MAKE) fclean -C ./lib/mylib_c
		rm -rf ./lib/libmy2.a

re:		fclean all

.PHONY:		re all fclean clean lib
