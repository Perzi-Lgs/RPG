/*
** EPITECH PROJECT, 2017
** dante
** File description:
** character.h
*/

#ifndef _char

#include "my_rpg.h"

/*
** with the enum each nbr_id gonna get a nbr
** object_id is the id of the object and object_nbr the value's nbr
*/
int start_map(window_t *window, int **map, game_t *game);
int choose_name_screen(window_t *window, char *name);
void	move_up(fsprites_t *sprites, map_t *s_map, window_t *window,\
	game_t *);
void	move_left(fsprites_t *sprites, map_t *s_map, window_t *window,\
	game_t *);
void	move_down(fsprites_t *sprites, map_t *s_map, window_t *window,\
	game_t *);
void	move_right(fsprites_t *sprites, map_t *s_map, window_t *window,\
	game_t *);
void draw_map(window_t *window, map_t *s_map, fsprites_t *sprite);
int	new_game(window_t *window, game_t *);
int	menu(window_t *, game_t *);
int create_chara(window_t *window, int **map, game_t *game);
int	floor_events(window_t *, fsprites_t *, map_t *, game_t *);
int     inv_game(window_t *, fsprites_t *, map_t *, game_t *);
int	inv_events(window_t *, inv_t *, game_t *);
int	inventory(inv_t *, int, game_t *);

#define _char
#endif
