/*
** EPITECH PROJECT, 2018
** create_map
** File description:
** my_world
*/

#include <SFML/Graphics/BlendMode.h>
#include "my_rpg.h"

void append_strip(map_t *map, sfVertex vertex0, sfVertex vertex1,\
	sfVertex vertex2)
{
	sfVertexArray_append(map->vert, vertex0);
	sfVertexArray_append(map->vert, vertex1);
	sfVertexArray_append(map->vert, vertex2);
}

void create_strip(map_t *map, int i, int j)
{
	sfVector2f pos1 = map->text_coord[map->texture_place[i][j]][0];
	sfVector2f pos2 = map->text_coord[map->texture_place[i][j]][1];
	sfVector2f pos3 = map->text_coord[map->texture_place[i][j]][2];
	sfVector2f pos4 = map->text_coord[map->texture_place[i][j]][3];
	sfVector2f pos5 = map->text_coord[map->texture_place[i][j]][7];

	sfVertex vertex0 = {.position = map->map[i][j].n_map[4],\
		.color = sfWhite, .texCoords = pos5};
	sfVertex vertex1 = {.position = map->map[i][j].n_map[0],\
		.color = sfWhite, .texCoords = pos1};
	sfVertex vertex2 = {.position = map->map[i][j].n_map[1],\
		.color = sfWhite, .texCoords = pos2};
	sfVertex vertex3 = {.position = map->map[i][j].n_map[2],\
		.color = sfWhite, .texCoords = pos3};
	sfVertex vertex4 = {.position = map->map[i][j].n_map[3],\
		.color = sfWhite, .texCoords = pos4};
	append_strip(map, vertex0, vertex1, vertex2);
	append_strip(map, vertex3, vertex4, vertex1);
	sfVertexArray_setPrimitiveType(map->vert, sfTrianglesFan);
}

void draw_2d_map_loop_bck(window_t *window, map_t *map, sfBool *check, int i)
{
	float height_char = map->map[x_coord][y_coord].tile[0];

	for (int j = 0; j < 49; j++) {
		if (i == x_coord && j == y_coord)
			*check = sfTrue;
		if ((map->map[i][j].tile[0] <= height_char) ||
		(*check == sfFalse))
			draw_tile(window, map, i, j);
	}
}

void draw_2d_map_loop_front(window_t *window, map_t *map, sfBool *check, int i)
{
	float height_char = map->map[x_coord][y_coord].tile[0];

	for (int j = 0; j < 49; j++) {
		if (i == x_coord && j == y_coord)
			*check = sfTrue;
		if ((map->map[i][j].tile[0] > height_char) &&
		(*check == sfTrue))
			draw_tile(window, map, i, j);
	}
}

int draw_2d_map(window_t *window, map_t *map, fsprites_t *sprites)
{
	sfBool check = sfFalse;

	for (int i = 0; i < 49; i++)
		draw_2d_map_loop_bck(window, map, &check, i);
	check = sfFalse;
	display_floor_sprites(sprites, window);
	for (int i = 0; i < 49; i++)
		draw_2d_map_loop_front(window, map, &check, i);
	return (0);
}
