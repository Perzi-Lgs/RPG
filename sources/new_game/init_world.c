/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** init_world.c
*/

#include "my_rpg.h"
#include "character.h"

char **malloc_tab(int size_one, int size_two)
{
	char **tab = malloc(sizeof(char *) * (size_one+1));

	if (tab == NULL)
		return (NULL);
	tab[size_one] = NULL;
	for (int i = 0; i < size_one; i++) {
		tab[i] = malloc(sizeof(char) * size_two+1);
		if (tab[i] == NULL)
			return (NULL);
		tab[i][size_two] = '\0';
	}
	return (tab);
}

int **transform_save(char **save, int size)
{
	int **map = malloc(sizeof(int *) * (size));

	if (map == NULL)
		return (NULL);
	for (int i = 0; i < size; i++) {
		map[i] = malloc(sizeof(int) * (size));
		if (map[i] == NULL)
			return (NULL);
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][j] = my_getnbr(save[i]);
			save[i] += my_strlen(itoa(my_getnbr(save[i])));
			save[i] += 1;
		}
	}
	return (map);
}

int fill_map(char **save, int fd, int size)
{
	for (int i = 1; i < size; i++)
		save[i] = get_next_line(fd);
	return (0);
}

int new_game(window_t *window, game_t *game)
{
	char **save = malloc_tab(50, 50);
	int fd = open(MAP_H, O_RDWR);
	int **map;

	if (fd < 0 || save == NULL)
		return (1);
	save[0] = get_next_line(fd);
	if (save[0] != NULL) {
		if (fill_map(save, fd, 50) == 1)
			return (1);
		map = transform_save(save, 50);
		close(fd);
		return (create_chara(window, map, game));
	}
	return (0);
}
