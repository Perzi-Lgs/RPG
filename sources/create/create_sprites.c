/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** file for creating sprites
*/

#include "my_rpg.h"

int     create_sprite(rsprite_t *obj, char *path, char *posi, char *recti)
{
	int *pos = my_atoi_array(posi);
	int *rect = my_atoi_array(recti);

	obj->texture = sfTexture_createFromFile(path, NULL);
	if (!obj->texture)
		return (-1);
	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
	obj->pos.x = pos[0];
	obj->pos.y = pos[1];
	obj->rect.left = rect[0];
	obj->rect.top = rect[1];
	obj->rect.width = rect[2];
	obj->rect.height = rect[3];
	return (0);
}

int	create_menu_sprites(gsprites_t *sprites)
{
	if (create_sprite(&sprites->back, "./pictures/back.png", "0;0",\
	"0;0;1920;1080") == -1)
		return (84);
	return (0);
}
