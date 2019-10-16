/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parser_coord.c
*/

#include "my_rpg.h"

const int SIZE_FILE_COORD = 105;
const int NBR_COORD = 9;
const int SIZE_FILE = 6030;

static sfVector2f **init_coord_texture(void)
{
	sfVector2f **texture_coord =
	malloc(sizeof(sfVector2f *) * SIZE_FILE_COORD);

	if (!texture_coord)
		return (NULL);
	for (int i = 0; i < SIZE_FILE_COORD; i++) {
		texture_coord[i] = malloc(sizeof(sfVector2f) * NBR_COORD);
		if (!texture_coord[i])
			return (NULL);
		texture_coord[i]->x = 0;
		texture_coord[i]->y = 0;
	}
	return (texture_coord);
}

static void fill_coord(sfVector2f **coord_texture, int i,
	char **opened_file, float vector_pos[])
{
	for (int k = 0; k < 8 && **opened_file; k++) {
		vector_pos[0] = my_getnbr(*opened_file);
		*opened_file += (my_strlen(itoa(vector_pos[0])) + 1);
		vector_pos[1] = my_getnbr(*opened_file);
		*opened_file += (my_strlen(itoa(vector_pos[1])) + 1);
		coord_texture[i][k].x = vector_pos[0];
		coord_texture[i][k].y = vector_pos[1];
	}
}

sfVector2f **create_coord_texture(void)
{
	sfVector2f **coord_texture = init_coord_texture();
	char *opened_file = malloc(sizeof(char) * SIZE_FILE + 1);
	int fd = open("./conf_files/text_coord", O_RDONLY);
	float vector_pos[2] = { 0.0, 0.0 };

	if (!coord_texture || !opened_file || fd == -1)
		return (NULL);
	read(fd, opened_file, SIZE_FILE);
	opened_file[SIZE_FILE] = '\0';
	for (int i = 0; *opened_file && i < 90; i++)
		fill_coord(coord_texture, i, &opened_file, vector_pos);
	return (coord_texture);
}
