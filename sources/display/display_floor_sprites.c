/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** file to display floors sprites
*/

#include "my_rpg.h"

void	display_floor_sprites(fsprites_t *sprites, window_t *window)
{
	display_sprite(&sprites->chara, window);
	display_sprite(&sprites->pnj_b, window);
	display_sprite(&sprites->pnj_g, window);
}
