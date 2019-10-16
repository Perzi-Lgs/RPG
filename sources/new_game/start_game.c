/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** start_game.c
*/

#include "character.h"

void check_advance_2(char const c, map_t *map, int *soil2, float *tmp2)
{
	if ('q' == c) {
		*tmp2 = map->map[x_coord+1][y_coord-1].tile[0];
		*soil2 = map->texture_place[x_coord+1][y_coord-1];
	} else if ('s' == c) {
		*tmp2 = map->map[x_coord+1][y_coord+1].tile[0];
		*soil2 = map->texture_place[x_coord+1][y_coord+1];
	}
	if ('z' == c) {
		*tmp2 = map->map[x_coord-1][y_coord-1].tile[0];
		*soil2 = map->texture_place[x_coord-1][y_coord-1];
	}
}

int check_advance(char const c, map_t *map)
{
	float tmp = map->map[x_coord][y_coord].tile[0];
	int soil = map->texture_place[x_coord][y_coord];
	int soil2;
	float tmp2;

	check_advance_2(c, map, &soil2, &tmp2);
	if ('d' == c) {
		tmp2 = map->map[x_coord-1][y_coord+1].tile[0];
		soil2 = map->texture_place[x_coord-1][y_coord+1];
	}
	if ((tmp + 1 >= tmp2 && tmp2 >= tmp - 1 &&
		((soil >= STAIRS1 && soil <= STAIRS18)
		|| (soil2 >= STAIRS1 && soil2 <= STAIRS18))) || tmp == tmp2)
		if (soil2 != LAVA1 && soil2 != WATER)
			return (0);
	return (1);
}

int world_event(window_t *window, map_t *s_map, fsprites_t *sprites,
	game_t *game)
{
	pnj_t *pnj = malloc(sizeof(pnj_t) * 3);

	pnj_events(sprites, window, s_map, pnj);
	if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue &&
	check_advance('q', s_map) == 0)
		move_left(sprites, s_map, window, game);
	else if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue &&
	check_advance('d', s_map) == 0)
		move_right(sprites, s_map, window, game);
	if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue &&
	check_advance('z', s_map) == 0)
		move_up(sprites, s_map, window, game);
	else if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
	check_advance('s', s_map) == 0)
		move_down(sprites, s_map, window, game);
	if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
		return (3);
	return (floor_events(window, sprites, s_map, game));
}

void draw_map(window_t *window, map_t *s_map, fsprites_t *sprites)
{
	sfRenderWindow_setView(window->RenderWindow, s_map->view);
	draw_2d_map(window, s_map, sprites);
	sfRenderWindow_setView(window->RenderWindow, s_map->minimap);
	draw_2d_map(window, s_map, sprites);
	DRAW(window->RenderWindow);
	CLEAR(window->RenderWindow, sfBlack);
}

int start_map(window_t *window, int **map, game_t *game)
{
	int ret = 0;
	map_t *s_map = malloc(sizeof(map_t));
	fsprites_t sprites;

	create_floor_sprites(&sprites);
	if (init_struct_map(map, s_map, window, sfFalse) == -1)
		return (84);
	s_map->music = sfMusic_createFromFile("./pictures/game_music.ogg");
	sfMusic_setLoop(s_map->music, sfTrue);
	sfMusic_setVolume(s_map->music, 50);
	sfMusic_play(s_map->music);
	while (ret == 0) {
		ret = world_event(window, s_map, &sprites, game);
		draw_map(window, s_map, &sprites);
	}
	sfMusic_destroy(s_map->music);
	if (ret == 3)
		return (0);
	return (ret);
}
