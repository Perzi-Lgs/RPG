/*
** EPITECH PROJECT, 2017
** dante
** File description:
** fight_loop.c
*/

#include "my_rpg.h"
#include "character.h"

void	set_hp_pos(sfText **text, monsters_t *monster)
{
	sfVector2f pos;

	pos.x = monster->isprite.pos.x;
	pos.y = monster->isprite.pos.y + 200;
	sfText_setPosition(text[0], pos);
	pos.x += 200;
	sfText_setPosition(text[1], pos);
	pos.x = monster->isprite.pos.x + 500;
	sfText_setPosition(text[2], pos);
	pos.x += 200;
	sfText_setPosition(text[3], pos);
}

sfText **init_hp(game_t *game, monsters_t *monster)
{
	sfText **text = malloc(sizeof(sfText *) * 4);
	sfFont *font = sfFont_createFromFile("./pictures/anir.ttf");
	char *str[4] = {"HP :", itoa(game->player.stat[HP]), "HP:",
	itoa(game->player.stat[HP])};
	int x = sfSprite_getPosition(monster->isprite.sprite).x;

	for (int i = 0; i < 4; i++) {
		text[i] = sfText_create();
		sfText_setFont(text[i], font);
		sfText_setString(text[i], str[i]);
		sfText_setCharacterSize(text[i], 50);
		sfText_setPosition(text[i], (sfVector2f){x,\
			sfSprite_getPosition(monster->isprite.sprite).y+100});
		if (i == 2)
			x = sfSprite_getPosition(game->player.\
				sprite->sprite).x;
		x += 20;
	}
	set_hp_pos(text, monster);
	return (text);
}

void atk_persos(game_t *game, monsters_t *monster, window_t *window,
	rsprite_t *battleground)
{
	player_atk(game, monster, window, battleground);
	monster->stats[HP] -= game->player.stat[ATK] - monster->stats[DEF];
}

void atk_mob(game_t *game, monsters_t *monster, window_t *window,
	rsprite_t *battleground)
{
	monster_atk(game, monster, window, battleground);
	game->player.stat[HP] -= monster->stats[ATK]-game->player.stat[DEF];
}

void	display_cbt(window_t *window, rsprite_t *btg, monsters_t *monster,
	game_t *game)
{
	display_sprite(&btg[0], window);
	display_sprite(&btg[1], window);
	display_sprite(&monster->isprite, window);
	display_sprite(game->player.sprite, window);
}
