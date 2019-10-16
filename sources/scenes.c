/*
** EPITECH PROJECT, 2018
** my_RPG_2017
** File description:
** file for scene handling
*/

#include "my_rpg.h"
#include "character.h"

int	init_game(game_t *game)
{
	game->inv_slot = 2;
	game->list = create_armors();
	game->items = malloc(sizeof(armors_t) * 12);
	game->items[0] = game->list[0].sword;
	game->items[1] = game->list[2].sword;
	game->player.nbr_object_equiped = 0;
	game->player.stats.hp_max = 120;
	game->player.stats.hp = 120;
	return (0);
}

int	logo(window_t window)
{
	rsprite_t logo;

	if (create_sprite(&logo, "./pictures/slimy.png", "0;0",
	"0;0;1920;1080") == -1)
		return (-1);
	display_sprite(&logo, &window);
	return (0);
}

int	scenes(void)
{
	window_t window;
	game_t game;
	int (*ptr[3])(window_t *, game_t *) = {menu, new_game, new_level};
	int rt = 0;

	init_game(&game);
	if (windows_create(&window) == -1)
		return (84);
	if (logo(window) == -1)
		return (84);
	sfRenderWindow_display(window.RenderWindow);
	sfSleep(sfSeconds(3));
	sfRenderWindow_clear(window.RenderWindow, sfBlack);
	while (sfRenderWindow_isOpen(window.RenderWindow))
		rt = ptr[rt](&window, &game);
	return (0);
}
