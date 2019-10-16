/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** file for displaying g_sprite for the inv menu
*/

#include "parsing_rpg.h"
#include "my_rpg.h"

void	display_inventory(window_t *window, fsprites_t *fsprite, game_t *game)
{
	sfVector2f pos = sfSprite_getPosition(fsprite->chara.sprite);
	int j = 0;

	for (int i = 0; i < game->inv_slot; i++) {
		game->items[i].isprite.pos.x = pos.x + 150 + j;
		game->items[i].isprite.pos.y = pos.y;
		display_sprite(&game->items[i].isprite, window);
		j += 150;
	}
}

void	display_inv_sprites(window_t *window, fsprites_t *fsprite,
	gsprites_t *g_sprite, map_t *map)
{
	sfRenderWindow_setView(window->RenderWindow, map->view);
	draw_2d_map(window, map, fsprite);
	display_sprite(&fsprite->chara, window);
	display_sprite(&g_sprite->back, window);
	display_sprite(&g_sprite->cursor, window);
	display_sprite(&g_sprite->cadre, window);
	display_sprite(&g_sprite->profil, window);
}
