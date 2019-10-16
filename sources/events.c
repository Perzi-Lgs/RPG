/*
** EPITECH PROJECT, 2018
** my_RPG_2017
** File description:
** file for handling events
*/

#include "my_rpg.h"
#include "character.h"

static int quest = 0;

int	floor_events(window_t *window, fsprites_t *sprites, map_t *map,
	game_t *game)
{
	int rt = 0;

	if (x_coord == 10 && y_coord == 42) {
		x_coord = 46;
		y_coord = 46;
		return (2);
	}
	if (sfKeyboard_isKeyPressed(sfKeyI)) {
		inv_game(window, sprites, map, game);
		sfSleep(sfSeconds(0.1));
	}
	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		rt = pause_menu(window, sprites, map);
	}
	return (rt);
}

void quest_loop(fsprites_t *sprites, window_t *window, map_t *map, pnj_t *pnj)
{
	if (((pnj->pos.y - pnj->pos_pnj_b.y) < 10) &&
	((pnj->pos.x - pnj->pos_pnj_b.x) < 10) && (pnj->pos.x != 0)
	&& quest == 0) {
		begin_quest(window, pnj, map, sprites);
		while (!sfKeyboard_isKeyPressed(sfKeyReturn));
		sfSleep(sfSeconds(0.3));
	}
	if (((pnj->pos.y - pnj->pos_pnj_g.y) < 150) &&
	((pnj->pos.x - pnj->pos_pnj_g.x) < 200) &&
	(pnj->pos.x != 0) && quest == 0) {
		end_quest(window, pnj, map, sprites);
		while (!sfKeyboard_isKeyPressed(sfKeyReturn));
		sfSleep(sfSeconds(0.3));
		quest = 1;
	}
}

void start_quest(fsprites_t *sprites, window_t *window, map_t *map, pnj_t *pnj)
{
	ini_pnj(sprites, pnj);
	if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
		sfSleep(sfSeconds(0.3));
		quest_loop(sprites, window, map, pnj);
		sfRenderWindow_clear(window->RenderWindow, sfBlack);
	}
	sfText_destroy(pnj->text);
}

int pnj_events(fsprites_t *sprites, window_t *window, map_t *map, pnj_t *pnj)
{
	start_quest(sprites, window, map, pnj);
	return (0);
}
