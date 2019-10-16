/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** malloc_items.c
*/

#include "parsing_rpg.h"

static monsters_t *malloc_mobs(monsters_t *mobs)
{
	for (int i = 0; i < (NBR_MOBS + 1); i++) {
		mobs[i].name = malloc(sizeof(char) * MOB_NAME + 1);
		mobs[i].stats = malloc(sizeof(int) * (NBR_STATS + 1));
		mobs[i].path_sprite = malloc(sizeof(char) * NBR_SPRITE + 1);
		mobs[i].coord = malloc(sizeof(float) * (COORD + 1));
		if (!mobs[i].name || !mobs[i].stats || !mobs[i].path_sprite ||
			!mobs[i].coord)
			return (NULL);
	}
	return (mobs);
}

monsters_t *malloc_monsters(void)
{
	monsters_t *mobs = malloc(sizeof(monsters_t) * (NBR_ITEMS + 1));

	if (!mobs)
		return (NULL);
	mobs = malloc_mobs(mobs);
	if (!mobs)
		return (NULL);
	return (mobs);
}
