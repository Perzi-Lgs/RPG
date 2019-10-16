/*
** EPITECH PROJECT, 2018
** my_RPG_2017
** File description:
** fonction for displaying sprites
*/

#include "my_rpg.h"

void    display_sprite(rsprite_t *obj, window_t *window)
{
	sfSprite_setPosition(obj->sprite, obj->pos);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfRenderWindow_drawSprite(window->RenderWindow, obj->sprite, NULL);
}
