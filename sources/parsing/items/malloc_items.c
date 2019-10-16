/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** malloc_items.c
*/

#include "parsing_rpg.h"

static all_armors_t *malloc_sword_name(all_armors_t *armors)
{
	for (int i = 0; i < (NBR_ITEMS + 1); i++) {
		armors[i].sword.name = malloc(sizeof(char) * ITEM_NAME + 1);
		armors[i].sword.stats = malloc(sizeof(int) * (NBR_STATS + 1));
		armors[i].sword.path_sprite = malloc(sizeof(char) *
		NBR_SPRITE + 1);
		if (!armors[i].sword.name || !armors[i].sword.stats
			|| !armors[i].sword.path_sprite)
			return (NULL);
		my_memset(armors[i].sword.name, ITEM_NAME);
		my_memset(armors[i].sword.path_sprite, NBR_SPRITE);
	}
	return (armors);
}

static all_armors_t *malloc_shield_name(all_armors_t *armors)
{
	for (int i = 0; i < (NBR_ITEMS + 1); i++) {
		armors[i].shield->name = malloc(sizeof(char) * ITEM_NAME + 1);
		armors[i].shield->stats = malloc(sizeof(int) *\
		(NBR_STATS + 1));
		armors[i].shield->path_sprite = malloc(sizeof(char) *
		NBR_SPRITE + 1);
		if (!armors[i].shield->name ||
			!armors[i].shield->stats ||
			!armors[i].shield->path_sprite)
			return (NULL);
		my_memset(armors[i].shield->name, ITEM_NAME);
		my_memset(armors[i].shield->path_sprite, NBR_SPRITE);
	}
	return (armors);
}

static all_armors_t *malloc_body_name(all_armors_t *armors)
{
	for (int i = 0; i < (NBR_ITEMS + 1); i++) {
		armors[i].body_armors->name = malloc(sizeof(char) *
		ITEM_NAME + 1);
		armors[i].body_armors->stats = malloc(sizeof(int) *
		(NBR_STATS + 1));
		armors[i].body_armors->path_sprite = malloc(sizeof(char) *
		NBR_SPRITE + 1);
		if (!armors[i].body_armors->name ||
			!armors[i].body_armors->stats ||
			!armors[i].body_armors->path_sprite)
			return (NULL);
		my_memset(armors[i].body_armors->name, ITEM_NAME);
		my_memset(armors[i].body_armors->path_sprite, NBR_SPRITE);
	}
	return (armors);
}

static all_armors_t *malloc_items(all_armors_t *armors)
{
	for (int i = 0; i < (NBR_ITEMS + 1); i++) {
		armors[i].shield = malloc(sizeof(armors_t));
		armors[i].body_armors = malloc(sizeof(armors_t));
		if (!armors[i].shield ||
			!armors[i].body_armors)
			return (NULL);
	}
	return (armors);
}

all_armors_t *malloc_armors(void)
{
	all_armors_t *armors = malloc(sizeof(all_armors_t) * (NBR_ITEMS + 1));

	if (!armors)
		return (NULL);
	armors = malloc_items(armors);
	if (!armors)
		return (NULL);
	armors = malloc_sword_name(armors);
	armors = malloc_shield_name(armors);
	armors = malloc_body_name(armors);
	if (!armors)
		return (NULL);
	return (armors);
}
