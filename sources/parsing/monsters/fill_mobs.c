/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** fill_mobs.c
*/

#include "parsing_rpg.h"

monsters_t *fill_mobs(monsters_t *mobs, char **file)
{
	int i = 0;

	for (int pos = 0; i < NBR_MOBS; i++, pos++) {
		mobs[i].zone = my_atoi(file[pos++]);
		mobs[i].name = my_strmcpy(file[pos++]);
		mobs[i].stats[LEVEL] = my_atoi(file[pos++]);
		mobs[i].stats[ATTACK] = my_atoi(file[pos++]);
		mobs[i].stats[DEFENSE] = my_atoi(file[pos++]);
		mobs[i].path_sprite = my_strmcpy(file[pos++]);
		mobs[i].coord[0] = my_atoi(file[pos++]);
		mobs[i].coord[1] = my_atoi(file[pos++]);
		mobs[i].coord[2] = my_atoi(file[pos++]);
		mobs[i].coord[3] = my_atoi(file[pos]);
	}
	return (mobs);
}
