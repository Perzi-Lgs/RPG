/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** create_monsters.c
*/

#include "parsing_rpg.h"

static char **open_file(void)
{
	FILE *fd = fopen("./conf_files/mobs.txt", "r");
	char *rd = malloc(sizeof(char) * FILE_SIZE + 1);

	if (!rd || !fd)
		return (NULL);
	fread(rd, FILE_SIZE, 1, fd);
	if (!rd)
		return (NULL);
	rd[FILE_SIZE] = '\0';
	return (my_str_word_tab(rd, ":"));
}

monsters_t *create_monsters(void)
{
	char **file = open_file();
	monsters_t *mobs = malloc_monsters();

	if (!file || !mobs)
		return (NULL);
	return (fill_mobs(mobs, file));
}
