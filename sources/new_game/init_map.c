/*
** EPITECH PROJECT, 2017
** my_world
** File description:
** ini_map.c
*/

#include "my_rpg.h"

map_c_t **init_struct_value(void)
{
	map_c_t **map = malloc(sizeof(map_c_t *) * 50);

	if (!map)
		return (NULL);
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++)
			map[i] = malloc(sizeof(map_c_t) * 50);
	}
	return (map);
}

float *init_tiles(int hauteur)
{
	float *tile = malloc(sizeof(float) * 5);

	if (!tile)
		return (NULL);
	for (int i = 0; i < 5; i++)
		tile[i] = hauteur;
	return (tile);
}

void load_true(map_t *s_map, int **map)
{
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			s_map->map[i][j].tile =  init_tiles(map[i][j]);
			s_map->map[i][j].n_map = create_2d_map(i, j, s_map);
		}
	}
}

sfTexture *create_texture_plop(void)
{
	sfTexture *texture = malloc(sizeof(sfTexture *) * 90);

	texture = sfTexture_createFromFile("./pictures/sheet.png", NULL);
	return (texture);
}

int init_struct_map(int **map, map_t *s_map, window_t *window, sfBool cpt)
{
	s_map->texture = create_texture_plop();
	s_map->texture_place = read_text(cpt);
	s_map->vert = sfVertexArray_create();
	s_map->map = init_struct_value();
	s_map->text_coord = create_coord_texture();
	load_true(s_map, map);
	s_map->translate_x = 1000;
	s_map->translate_y = 150;
	if (s_map->map == NULL || s_map->texture_place == NULL)
		return (-1);
	if (init_view(s_map, window) == 84)
		return (-1);
	return (0);
}
