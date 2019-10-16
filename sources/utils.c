/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** utils.c
*/

#include "my_rpg.h"

sfRectangleShape *create_rect_entity(sfVector2f size)
{
	sfRectangleShape *rec = sfRectangleShape_create();

	sfRectangleShape_setSize(rec, size);
	sfRectangleShape_setFillColor(rec, sfTransparent);
	return (rec);
}

int **read_text(sfBool cpt)
{
	char **map = malloc(sizeof(char *) * 50);
	int fd;
	int **text;

	if (cpt == sfTrue)
		fd = open(MAP2_T, O_RDWR);
	if (cpt == sfFalse)
		fd = open(MAP_T, O_RDWR);
	if (!map)
		return (NULL);
	for (int i = 0; i < 50; i++) {
		map[i] = malloc(sizeof(char) * 50);
		if (!map[i])
			return (NULL);
	}
	for (int i = 0; i < 50; i++)
		map[i] = get_next_line(fd);
	text = transform_save(map, 50);
	return (text);
}

void	move_rect(rsprite_t *sprite, int max, int nb)
{
	sprite->rect.left += nb;
	if (sprite->rect.left > max)
		sprite->rect.left = 0;
}

void	move_rect_neg(rsprite_t *sprite, int min, int nb, int max)
{
	sprite->rect.left -= nb;
	if (sprite->rect.left < min)
		sprite->rect.left = max;
}
