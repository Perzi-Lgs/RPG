/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display sprites for the pause menu
*/

#include "my_rpg.h"

void	display_pause_sprites(window_t *window, pause_t *pause, map_t *map,
	fsprites_t *sprites)
{
	sfRenderWindow_setView(window->RenderWindow, map->view);
	draw_2d_map(window, map, sprites);
	display_sprite(&pause->psprites.back, window);
	display_sprite(&pause->psprites.menu, window);
	display_sprite(&pause->psprites.exit, window);
	display_sprite(&pause->psprites.cross, window);
	sfRenderWindow_display(window->RenderWindow);
	sfRenderWindow_clear(window->RenderWindow, sfBlack);
}
