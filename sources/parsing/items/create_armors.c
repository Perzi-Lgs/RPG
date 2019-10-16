/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** create_armors.c
*/

#include "parsing_rpg.h"

static char **open_file(void)
{
	FILE *fd = fopen("./conf_files/armors.txt", "r");
	char *rd = malloc(sizeof(char) * FILE_SIZE + 1);

	if (!rd || !fd)
		return (NULL);
	my_memset(rd, FILE_SIZE + 1);
	fread(rd, FILE_SIZE, 1, fd);
	if (!rd)
		return (NULL);
	return (my_str_word_tab(rd, ":"));
}

all_armors_t *create_armors(void)
{
	int items = 0;
	char **file = open_file();
	all_armors_t *armors = malloc_armors();

	if (!file || !armors)
		return (NULL);
	items = fill_sword(armors, file, items);
	items = fill_shield(armors, file, items);
	items = fill_body_armor(armors, file, items);
	return (armors);
}
