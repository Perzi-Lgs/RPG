/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** buttons fonctions
*/

#include "my_rpg.h"

int	button_is_clicked(button_t *button, window_t *window, map_t *map)
{
	int lenght = button->pos.x + button->size.x;
	int height = button->pos.y + button->size.y;
	sfVector2f pos;

	window->posmouse =\
	sfMouse_getPositionRenderWindow(window->RenderWindow);
	pos = sfRenderWindow_mapPixelToCoords(window->RenderWindow,
		window->posmouse, map->view);
	if (pos.x >= button->pos.x && pos.x <= lenght
	&& pos.y >= button->pos.y && pos.y <= height) {
		return (1);
	}
	return (0);
}

int	button_initialise(button_t *button, char *posi, char *sizei)
{
	int *pos = my_atoi_array(posi);
	int *size = my_atoi_array(sizei);

	button->pos.x = pos[0];
	button->pos.y = pos[1];
	button->size.x = size[0];
	button->size.y = size[1];
	button->rect = sfRectangleShape_create();
	if (!button->rect)
		return (-1);
	sfRectangleShape_setPosition(button->rect, button->pos);
	sfRectangleShape_setSize(button->rect, button->size);
	return (0);
}

void	menu_state(button_t *button, rsprite_t *obj, window_t *window,
	map_t *map)
{
	int nb = 622;

	if (button_is_clicked(button, window, map) == 1 && obj->rect.left <= nb)
		obj->rect.left = nb;
	else if (obj->rect.left <= nb)
		obj->rect.left = 0;
}

void	cross_state(button_t *button, rsprite_t *obj, window_t *window,
	map_t *map)
{
	int nb = 120;

	if (button_is_clicked(button, window, map) == 1 && obj->rect.left <= nb)
		obj->rect.left = nb;
	else if (obj->rect.left <= nb)
		obj->rect.left = 0;
}
