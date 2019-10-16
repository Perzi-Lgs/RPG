/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** fill_sword.c
*/

#include "my_rpg.h"

int fill_sword(all_armors_t *armors, char **file, int item)
{
	int i = 0;
	int items;

	(void)item;
	for (items = 1; my_strcmp("BOUCLIER", file[items]) == 1 && file[items]
	&& i < NBR_ITEMS; items++, i++) {
		armors[i].sword.name = my_strmcpy(file[items++]);
		armors[i].sword.stats[LEVEL] = my_atoi(file[items++]);
		armors[i].sword.stats[ATTACK] = my_atoi(file[items++]);
		armors[i].sword.stats[DEFENSE] = my_atoi(file[items++]);
		armors[i].sword.path_sprite = my_strmcpy(file[items++]);
		if (create_sprite(&armors[i].sword.isprite,
			armors[i].sword.path_sprite, "0;0", file[items]) == -1)
			return (84);
		armors[i].sword.is_equipped = 0;
	}
	return (items + 1);
}

int fill_shield(all_armors_t *armors, char **file, int item)
{
	int i = 0;

	for (; my_strcmp("ARMURE", file[item]) == 1 && file[item]
	&& i < NBR_ITEMS; item++, i++) {
		armors[i].shield->name = my_strmcpy(file[item++]);
		armors[i].shield->stats[LEVEL] = my_atoi(file[item++]);
		armors[i].shield->stats[ATTACK] = my_atoi(file[item++]);
		armors[i].shield->stats[DEFENSE] = my_atoi(file[item++]);
		armors[i].shield->path_sprite = my_strmcpy(file[item++]);
		create_sprite(&armors[i].shield->isprite,
		armors[i].shield->path_sprite, "0;0", "0;0;100;102");
		armors[i].shield->is_equipped = 0;
	}
	return (item + 1);
}

int fill_body_armor(all_armors_t *armors, char **file, int item)
{
	int i = 0;

	for (; file[item] && i < NBR_ITEMS; item++, i++) {
		armors[i].body_armors->name = my_strmcpy(file[item++]);
		armors[i].body_armors->stats[LEVEL] = my_atoi(file[item++]);
		armors[i].body_armors->stats[ATTACK] = my_atoi(file[item++]);
		armors[i].body_armors->stats[DEFENSE] = my_atoi(file[item++]);
		armors[i].body_armors->path_sprite = my_strmcpy(file[item++]);
		create_sprite(&armors[i].body_armors->isprite,
		armors[i].body_armors->path_sprite, "0;0", file[item]);
		armors[i].body_armors->is_equipped = 0;
	}
	return (item);
}
