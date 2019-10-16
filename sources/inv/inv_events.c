/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** file for inv_menu events
*/

#include "my_rpg.h"
#include "character.h"

int quit_inv(gsprites_t *sprites, int layer, textures_t *textures, int pos)
{
	sfVector2f posi = sfSprite_getPosition(sprites->back.sprite);

	if (pos < 0) {
		layer = 0;
		pos = 0;
		sfSprite_setTexture(sprites->cursor.sprite,
			textures->empty, sfTrue);
		sprites->cursor.pos.x = posi.x;
		sprites->cursor.pos.y = posi.y + 120;
		return (layer);
	}
	return (layer);
}

int	move_in_inventory(inv_t *inv, int layer, game_t *game)
{
	static int pos = 0;

	(void)game;
	sfSprite_setTexture(inv->sprites.cursor.sprite, inv->textures.cursor,\
		sfTrue);
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		if (pos < 3) {
			pos++;
			inv->sprites.cursor.pos.y += 120;
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		pos--;
		inv->sprites.cursor.pos.y -= 120;
		if (quit_inv(&inv->sprites, layer, &inv->textures, pos) == 0)
			return (pos = 0);
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		layer = 2;
	return (layer);
}

int	move_in_mainmenu(inv_t *inv, int layer, game_t *game)
{
	static int state = 0;

	(void)game;
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		move_rect(&inv->sprites.back, 4497, 1499);
		state++;
		if (state > 3)
			state = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		move_rect_neg(&inv->sprites.back, 0, 1499, 4497);
		state--;
		if (state < 0)
			state = 3;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) && state == 0)
		layer = 1;
	set_items(state, inv);
	return (layer);
}

int	inv_menu(int layer, inv_t *inv, game_t *game)
{
	int (*ptr[3])(inv_t *, int, game_t *) = {move_in_mainmenu,\
		move_in_inventory, inventory};

	layer = ptr[layer](inv, layer, game);
	return (layer);
}

int	inv_events(window_t *window, inv_t *inv, game_t *game)
{
	static int layer = 0;

	while (sfRenderWindow_pollEvent(window->RenderWindow, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->RenderWindow);
		if (sfKeyboard_isKeyPressed(sfKeyI)) {
			layer = 0;
			return (1);
		}
		layer = inv_menu(layer, inv, game);
	}
	return (0);
}
