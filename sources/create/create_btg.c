/*
** EPITECH PROJECT, 2017
** dante
** File description:
** create_btg.c
*/

#include "struct.h"
#include "my_rpg.h"

void set_view_with_window(fsprites_t *sprite, rsprite_t *battleground)
{
	sfVector2f pos = sfSprite_getPosition(sprite->chara.sprite);

	battleground[0].pos.x = pos.x - 1920/2.34;
	battleground[0].pos.y = pos.y - 1080/3.32;
	battleground[1].pos.x = pos.x - 1920/2.34;
	battleground[1].pos.y = pos.y - 1080/3.32;
}

rsprite_t *create_btg(int index, fsprites_t *sprite)
{
	rsprite_t *battleground = malloc(sizeof(rsprite_t) * 2);
	char *asset[4] = {"./pictures/RockCave.png",
	"./pictures/RockCave2.png", "./pictures/Grassland2.png",
	"./pictures/Grassland.png"};

	if (!battleground)
		return (NULL);
	create_sprite(&battleground[0], asset[index], "0;0", "0;0;1920;1080");
	create_sprite(&battleground[1], asset[index+1],\
		"0;0", "0;0;1920;1080");
	set_view_with_window(sprite, battleground);
	return (battleground);
}
