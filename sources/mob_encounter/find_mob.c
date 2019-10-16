/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** find_mob.c
*/

#include "struct.h"
#include "parsing_rpg.h"
#include "my_rpg.h"

monsters_t generate_mob(monsters_t *mob, chara_t chara, int zone)
{
	monsters_t new_mob = { 0 };

	(void)chara;
	new_mob.zone = mob[zone].zone;
	new_mob.name = my_strmcpy(mob[zone].name);
	new_mob.stats[LEVEL] = mob[zone].stats[LEVEL];
	new_mob.stats[ATTACK] = mob[zone].stats[ATTACK];
	new_mob.stats[DEFENSE] = mob[zone].stats[DEFENSE];
	new_mob.path_sprite = my_strmcpy(mob[zone].path_sprite);
	new_mob.coord[0] = mob[zone].coord[0];
	new_mob.coord[1] = mob[zone].coord[1];
	new_mob.coord[2] = mob[zone].coord[2];
	new_mob.coord[3] = mob[zone].coord[3];
	return (new_mob);
}

monsters_t generation(chara_t chara, monsters_t *mob, int zone)
{
	int array[2] = { 0, 0 };
	int gen_mob;

	(void)chara;
	for (array[0] = 0; zone != mob[array[0]].zone; array[0]++);
	for (array[1] = array[0]; mob[array[1]].zone == zone; array[1]++);
	gen_mob = NBR_MOBS % (array[0] + 1) + array[0];
	return (generate_mob(mob, chara, gen_mob));
}
