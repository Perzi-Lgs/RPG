/*
** EPITECH PROJECT, 2018
** my_RPG_2017
** File description:
** file for creating sprites for floors
*/

#include "my_rpg.h"

int	create_floor_sprites(fsprites_t *sprites)
{
	if (create_sprite(&sprites->chara, "./pictures/dang.png", "900;3250",
	"0;208;199;204") == -1)
		return (-1);
	if (create_sprite(&sprites->pnj_b, "./pictures/Terry.png", "1200;3250",
	"0;0;150;150") == -1)
		return (-1);
	if (create_sprite(&sprites->pnj_g, "./pictures/Tevy.png", "1500;2000",
	"0;0;150;150") == -1)
		return (-1);
	return (0);
}
