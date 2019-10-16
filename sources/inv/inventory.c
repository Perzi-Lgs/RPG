/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** move and select object in the inventory
*/

#include "my_rpg.h"
#include "character.h"

int select_item(gsprites_t *sprites, game_t *game, int pos)
{
	(void)sprites;
	if (game->items[pos].is_equipped == 0 &&
		game->player.nbr_object_equiped < 3) {
		game->items[pos].is_equipped = 1;
		game->player.nbr_object_equiped++;
		game->items[pos].isprite.rect.top += 104;
		sfSleep(sfSeconds(0.2));
	} else {
		game->items[pos].is_equipped = 0;
		game->items[pos].isprite.rect.top -= 104;
		game->player.nbr_object_equiped--;
		sfSleep(sfSeconds(0.2));
	}
	return (0);
}

int	quit_inventory(gsprites_t *sprites, textures_t *textures, int pos)
{
	sfVector2f posi = sfSprite_getPosition(sprites->back.sprite);

	if (pos == 0 || pos == 4 || pos == 8) {
		sfSprite_setTexture(sprites->cadre.sprite,\
			textures->empty, sfTrue);
		sprites->cadre.pos.x = posi.x + 800;
		sprites->cadre.pos.y = posi.y + 100;
		return (1);
	}
	return (0);
}

int	inventory(inv_t *inv, int layer, game_t *game)
{
	static int pos = 0;

	sfSprite_setTexture(inv->sprites.cadre.sprite,\
		inv->textures.cadre, sfTrue);
	sfSprite_setTexture(inv->sprites.cursor.sprite,\
		inv->textures.empty, sfTrue);
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		if (quit_inventory(&inv->sprites, &inv->textures, pos) == 1) {
			layer--;
			pos = 0;
			return (layer);
		}
		pos = move_inv_left(&inv->sprites, pos);
	}
	pos = move_inside_inv(inv, pos, game);
	return (layer);
}
