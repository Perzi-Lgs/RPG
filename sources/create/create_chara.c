/*
** EPITECH PROJECT, 2017
** dante
** File description:
** create_chara.c
*/

#include "character.h"

void init_anim_atk(rsprite_t *anim)
{
	create_sprite(anim, "./pictures/ATK_DANG.png", "0;0", "0;0;192;192");
}

void init_stat(game_t *game)
{
	game->player.stat = malloc(sizeof(int) * 3);

	game->player.stat[HP] = 25;
	game->player.stat[ATK] = 8;
	game->player.stat[DEF] = 5;
}

/*
** init the value of the inventory
** at 0
** return value void
*/

static void alloc_inventory(inventory_t *equiped, inventory_t *inventory)
{
	for (int i = 0; i < 3; i++) {
		equiped->object_id = 0;
		equiped->object_nbr = 0;
	}
	for (int i = 0; i < 3; i++) {
		inventory->object_id = 0;
		inventory->object_nbr = 0;
	}
}

/*
** set the player default name
** by writing in the struct the default name
** return value void
*/

static void set_name_default(char *name)
{
	char *default_name = "Gucci Dang";

	name[11] = '\0';
	for (int i = 0; default_name[i]; i++) {
		name[i] = default_name[i];
		name[i+1] = '\0';
	}
}

/*
** This is the function who init the playable character
** This fct init all the value and start a screen who allow the player
** to choose a name
** after this screen the fct launch the new_game
** return value = 0 or 84
*/

int create_chara(window_t *window, int **map, game_t *game)
{
	game->player.name = malloc(sizeof(char) * 12);
	game->player.sprite = malloc(sizeof(fsprites_t));
	game->player.equiped = malloc(sizeof(inventory_t) * 3);
	game->player.inventory = malloc(sizeof(inventory_t) * 10);
	init_anim_atk(&game->player.anim_atk);
	init_stat(game);
	if (!game->player.name || !game->player.sprite ||
		!game->player.equiped || (!game->player.inventory &&
			game->player.mob_encounter != 0))
		return (84);
	if (create_sprite(game->player.sprite, "./pictures/dang.png",\
	"900;3250", "0;208;199;204") == -1)
		return (84);
	alloc_inventory(game->player.equiped, game->player.inventory);
	game->player.nbr_object = 0;
	game->player.mob_encounter = 0;
	set_name_default(game->player.name);
	choose_name_screen(window, game->player.name);
	return (start_map(window, map, game));
}
