/*
** EPITECH PROJECT, 2018
** my_RPG_2017
** File description:
** file for fonctions used for the inv menu
*/

#include "my_rpg.h"
#include "character.h"

int	create_inv_texts(fsprites_t *fsprite, text_t *text, game_t *game)
{
	sfVector2f pos = sfSprite_getPosition(fsprite->chara.sprite);

	text->font = sfFont_createFromFile("pictures/anir.ttf");
	if (!text->font)
		return EXIT_FAILURE;
	text->name = create_text(text->name, text->font,\
		game->player.name, 30);
	text->hp = create_text(text->hp, text->font, my_strcat("HP: ",
	my_strcat(itoa(game->player.stats.hp), my_strcat("/",
	itoa(game->player.stats.hp_max)))), 30);
	pos.x -= 300;
	sfText_setPosition(text->name, pos);
	pos.y += 50;
	sfText_setPosition(text->hp, pos);
	return (0);
}

int     inv_game(window_t *window, fsprites_t *g_sprites, map_t *map,
	game_t *game)
{
	inv_t inve;
	text_t text;
	int inv = 0;

	create_inv_texts(g_sprites, &text, game);
	inve.items = 0;
	create_inv_sprites(&inve.sprites, &inve.textures, g_sprites);
	while (sfRenderWindow_isOpen(window->RenderWindow)) {
		inv = inv_events(window, &inve, game);
		if (inv == 1)
			return (0);
		display_inv_sprites(window, g_sprites, &inve.sprites, map);
		if (inve.items == 1)
			display_inventory(window, g_sprites, game);
		sfRenderWindow_drawText(window->RenderWindow, text.name, NULL);
		sfRenderWindow_drawText(window->RenderWindow, text.hp, NULL);
		sfRenderWindow_display(window->RenderWindow);
		sfRenderWindow_clear(window->RenderWindow, sfBlack);
	}
	return (0);
}
