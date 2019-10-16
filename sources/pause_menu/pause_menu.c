/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main fonction for the pause menu
*/

#include "my_rpg.h"

void	hover_button(pause_t *pause, window_t *window, map_t *map)
{
	menu_state(&pause->pbuttons.btexit, &pause->psprites.exit, window,\
		map);
	menu_state(&pause->pbuttons.btmenu, &pause->psprites.menu, window,\
		map);
	cross_state(&pause->pbuttons.btcross, &pause->psprites.cross, window,\
		map);
}

int	pause_menu(window_t *window, fsprites_t *sprites, map_t *map)
{
	pause_t pause;
	int rt = 0;

	sfSleep(sfSeconds(0.2));
	if (init_pause(&pause, sprites) == -1)
		return (-1);
	while (rt == 0) {
		rt = pause_events(window, &pause, map, sprites);
		if (rt == 1) {
			rt = 0;
			break;
		}
		if (rt == 2)
			return (3);
	hover_button(&pause, window, map);
	display_pause_sprites(window, &pause, map, sprites);
	}
	return (rt);
}
