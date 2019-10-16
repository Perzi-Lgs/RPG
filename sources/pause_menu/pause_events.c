/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** events handling for the pause menu
*/

#include "my_rpg.h"

int	cross_clicked(button_t *button, rsprite_t *obj, window_t *window,
	map_t *map)
{
	int nb = 240;

	if (button_is_clicked(button, window, map) == 1 &&
	obj->rect.left <= nb) {
		obj->rect.left = nb;
		return (1);
	} else if (obj->rect.left <= nb)
		obj->rect.left = 0;
	return (0);
}

int	menu_clicked(button_t *button, rsprite_t *obj, window_t *window,
	map_t *map)
{
	int nb = 1244;

	if (button_is_clicked(button, window, map) == 1 &&
	obj->rect.left <= nb) {
		obj->rect.left = nb;
		return (1);
	} else if (obj->rect.left <= nb)
		obj->rect.left = 0;
	return (0);
}

int	button_clicked_on(pause_t *pause, window_t *window, map_t* map,
	fsprites_t *sprites)
{
	if (menu_clicked(&pause->pbuttons.btmenu, &pause->psprites.menu,\
		window, map) == 1) {
		display_pause_sprites(window, pause, map, sprites);
		sfSleep(sfSeconds(0.5));
		return (2);
	}
	if (menu_clicked(&pause->pbuttons.btexit, &pause->psprites.exit,\
		window, map) == 1) {
		display_pause_sprites(window, pause, map, sprites);
		sfSleep(sfSeconds(0.5));
		sfRenderWindow_close(window->RenderWindow);
		return (-1);
	}
	if (cross_clicked(&pause->pbuttons.btcross, &pause->psprites.cross,\
		window, map) == 1) {
		display_pause_sprites(window, pause, map, sprites);
		sfSleep(sfSeconds(0.5));
		return (1);
	}
	return (0);
}

int	pause_events(window_t *window, pause_t *pause, map_t *map,
	fsprites_t *sprites)
{
	int rt = 0;

	while (sfRenderWindow_pollEvent(window->RenderWindow,\
		&window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->RenderWindow);
		if (window->event.type == sfEvtMouseButtonReleased) {
			rt = button_clicked_on(pause, window, map, sprites);
			if (rt == 2)
				return (2);
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		sfSleep(sfSeconds(0.2));
		return (1);
	}
	return (rt);
}
