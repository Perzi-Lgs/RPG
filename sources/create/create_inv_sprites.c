/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** file for creating sprites and buttons for pause_menu
*/

#include "my_rpg.h"

void	set_sprites_pos(gsprites_t *sprites, fsprites_t *fsprite)
{
	sfVector2f pos = sfSprite_getPosition(fsprite->chara.sprite);

	sprites->back.pos.x = pos.x - 650;
	sprites->back.pos.y = pos.y - 100;
	sprites->cursor.pos.x = pos.x - 650;
	sprites->cursor.pos.y = pos.y + 20;
	sprites->cadre.pos.x = pos.x + 150;
	sprites->cadre.pos.y = pos.y;
	sprites->profil.pos.x = pos.x - 560;
	sprites->profil.pos.y = pos.y;
}

int	create_inv_sprites(gsprites_t *sprites, textures_t *textures,
	fsprites_t *fsprite)
{
	create_sprite(&sprites->back, "./pictures/pause.png", "0;0",
	"0;0;1500;842");
	textures->empty = sfTexture_createFromFile("./pictures/void.png"
	, NULL);
	create_sprite(&sprites->cursor, "./pictures/void.png", "450;200",
	"0;0;57;50");
	textures->cursor = sfTexture_createFromFile("./pictures/cursor.png"
	, NULL);
	create_sprite(&sprites->cadre, "./pictures/void.png", "450;200",
	"0;0;137;85");
	textures->cadre = sfTexture_createFromFile("./pictures/cadre.png"
	, NULL);
	create_sprite(&sprites->profil, "./pictures/profil.png", "450;200",
	"0;0;90;90");
	set_sprites_pos(sprites, fsprite);
	return (0);
}
