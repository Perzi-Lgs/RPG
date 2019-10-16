/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** find_mob.c
*/

#include "my_rpg.h"

void display_cbt_text(window_t *window, sfText **hp, monsters_t *monster,
	game_t *game)
{
	sfText_setString(hp[1], itoa(monster->stats[HP]));
	sfText_setString(hp[3], itoa(game->player.stat[HP]));
	for (int i = 0; i < 4; i++)
		DRAW_TXT(window->RenderWindow, hp[i], NULL);
	DRAW(window->RenderWindow);
	CLEAR(window->RenderWindow, sfBlack);
}
