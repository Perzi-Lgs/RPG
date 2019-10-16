/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** file for initialasing and using view
*/

#include "my_rpg.h"

int	init_view(map_t *s_map, window_t *window)
{
	sfFloatRect rect = {0, 0, 1920, 1080};
	sfFloatRect rect2 = {0.74, -0.03, 0.25, 0.25};
	sfVector2f size = {1920*4, 1080*4};
	sfVector2f move = {740, 1400};
	sfVector2f center = {1000, 3500};

	s_map->minimap = sfView_createFromRect(rect2);
	s_map->view = sfView_createFromRect(rect);
	sfView_move(s_map->minimap, move);
	if (!s_map->view || !s_map->minimap)
		return (84);
	sfView_setSize(s_map->minimap, size);
	s_map->v_coord = sfView_getCenter(s_map->view);
	sfView_setCenter(s_map->view, center);
	sfView_zoom(s_map->view, 1.6);
	sfRenderWindow_setView(window->RenderWindow, s_map->view);
	sfView_setViewport(s_map->minimap, rect2);
	return (0);
}
