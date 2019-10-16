/*
** EPITECH PROJECT, 2017
** dante
** File description:
** fight_init.c
*/

#include "my_rpg.h"
#include "character.h"


int fight_loop(rsprite_t *btg, game_t *game, monsters_t *monster,
	window_t *window)
{
	sfText **hp = init_hp(game, monster);

	if (sfKeyboard_isKeyPressed(sfKeyF) == sfTrue)
		return (1);
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
		atk_persos(game, monster, window, btg);
		if (monster->stats[HP] <= 0)
			return (1);
		atk_mob(game, monster, window, btg);
		sfSleep(sfSeconds(1));
	}
	display_cbt(window, btg, monster, game);
	display_cbt_text(window, hp, monster, game);
	return (0);
}

void load_bck(rsprite_t *btg, game_t *game, monsters_t *monster,
	window_t *window)
{

	while (game->player.stat[HP] > 0 && monster->stats[HP] > 0) {
		if (fight_loop(btg, game, monster, window) == 1)
			break;
	}
}

void	set_battle_pos(monsters_t *monstre, fsprites_t *sprites, game_t *game)
{
	sfVector2f pos = sfSprite_getPosition(sprites->chara.sprite);

	monstre->isprite.pos.y = pos.y + 200;
	monstre->isprite.pos.x = pos.x - 250;
	game->player.sprite->pos.y = pos.y + 150;
	game->player.sprite->pos.x = pos.x + 250;
}

monsters_t create_slime(game_t *game, fsprites_t *sprites)
{
	monsters_t monstre = { 0 };

	monstre.name = "Slime";
	monstre.stats = malloc(sizeof(int) * 3);
	monstre.stats[0] = 20;
	monstre.stats[1] = 5;
	monstre.stats[2] = 3;
	create_sprite(&monstre.isprite, "./pictures/Slime1_1.png", "0;0",
	"0;0;128;128");
	set_battle_pos(&monstre, sprites, game);
	return (monstre);
}

int init_fight(game_t *game, map_t *map, window_t *window,
	fsprites_t *sprites)
{
	rsprite_t *battleground;
	monsters_t monstre = create_slime(game, sprites);

	sfView_zoom(map->view, 0.6);
	sfRenderWindow_setView(window->RenderWindow, map->view);
	if (map->texture_place[x_coord][y_coord] == 82) {
		if ((battleground = create_btg(0, sprites)) == NULL)
			return (84);
		load_bck(battleground, game, &monstre, window);
	} else if (map->texture_place[x_coord][y_coord] == 20) {
		if ((battleground = create_btg(2, sprites)) == NULL)
			return (84);
		load_bck(battleground, game, &monstre, window);
	} else {
		if ((battleground = create_btg(2, sprites)) == NULL)
			return (84);
		load_bck(battleground, game, &monstre, window);
	}
	sfView_zoom(map->view, 1.6);
	return (0);
}
