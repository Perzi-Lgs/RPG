/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** file for drawing and moving the character on the map
*/

#include "character.h"

void	move_up(fsprites_t *sprites, map_t *s_map, window_t *window,
	game_t *game)
{
	sfVector2f var = {0, -2.6};
	int ret = 0;

	game->player.mob_encounter += 1;
	sprites->chara.rect.top = 0;
	for (int i = 0; i < 9; i++) {
		move_rect(&sprites->chara, 1584, 199);
		for (int j = 0; j < 3; j++) {
			sfView_move(s_map->view, var);
			sprites->chara.pos.y += -2.6;
			draw_map(window, s_map, sprites);
		}
	}
	x_coord -= 1;
	y_coord -= 1;
	if ((game->player.mob_encounter * 100 / 30) > (ret = (rand()%100))) {
		init_fight(game, s_map, window, sprites);
		game->player.mob_encounter = 0;
	}
}

void	move_down(fsprites_t *sprites, map_t *s_map, window_t *window,
	game_t *game)
{
	sfVector2f var = {0, 2.6};
	int ret = 0;

	game->player.mob_encounter += 1;
	sprites->chara.rect.top = 408;
	for (int i = 0; i < 9; i++) {
		move_rect(&sprites->chara, 1584, 199);
		for (int j = 0; j < 3; j++) {
			sfView_move(s_map->view, var);
			sprites->chara.pos.y += 2.6;
			draw_map(window, s_map, sprites);
		}
	}
	x_coord += 1;
	y_coord += 1;
	if ((game->player.mob_encounter * 100 / 30) > (ret = (rand()%100))) {
		init_fight(game, s_map, window, sprites);
		game->player.mob_encounter = 0;
	}
}

void	move_left(fsprites_t *sprites, map_t *s_map, window_t *window,
	game_t *game)
{
	sfVector2f var = {-5.5, 0};
	int ret = 0;

	game->player.mob_encounter += 1;
	sprites->chara.rect.top = 204;
	for (int i = 0; i < 9; i++) {
		move_rect(&sprites->chara, 1584, 199);
		for (int j = 0; j < 3; j++) {
			sfView_move(s_map->view, var);
			sprites->chara.pos.x -= 5.5;
			draw_map(window, s_map, sprites);
		}
	}
	y_coord -= 1;
	x_coord += 1;
	if ((game->player.mob_encounter * 100 / 30) > (ret = (rand()%100))) {
		init_fight(game, s_map, window, sprites);
		game->player.mob_encounter = 0;
	}
}

void	move_right(fsprites_t *sprites, map_t *s_map, window_t *window,
	game_t *game)
{
	sfVector2f var = {5.5, 0};
	int ret = 0;

	game->player.mob_encounter += 1;
	sprites->chara.rect.top = 612;
	for (int i = 0; i < 9; i++) {
		move_rect(&sprites->chara, 1584, 199);
		for (int j = 0; j < 3; j++) {
			sfView_move(s_map->view, var);
			sprites->chara.pos.x += 5.5;
			draw_map(window, s_map, sprites);
		}
	}
	x_coord -= 1;
	y_coord += 1;
	if ((game->player.mob_encounter * 100 / 30) > (ret = (rand()%100))) {
		init_fight(game, s_map, window, sprites);
		game->player.mob_encounter = 0;
	}
}
