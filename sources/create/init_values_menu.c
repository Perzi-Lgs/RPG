/*
** EPITECH PROJECT, 2017
** dante
** File description:
** init_values_menu.c
*/

#include "my_rpg.h"

int init_rectangle_menu(sfRectangleShape **rec)
{
	sfVector2f size = {400, 50};
	sfVector2f pos = {1360, 465};

	for (int i = 0; i < 4; i++) {
		rec[i] = create_rect_entity(size);
		sfRectangleShape_setPosition(rec[i], pos);
		pos.y += 100;
	}
	return (0);
}

sfVector2f *init_pos_menu(void)
{
	sfVector2f *pos = malloc(sizeof(sfVector2f) * 2);

	if (pos == NULL)
		return (NULL);
	pos[0].x = 0;
	pos[0].y = 0;
	pos[1].x = 1300;
	pos[1].y = 400;
	return (pos);
}
