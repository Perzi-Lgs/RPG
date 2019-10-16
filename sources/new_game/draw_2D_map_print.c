/*
** EPITECH PROJECT, 2017
** dante
** File description:
** draw_2D_map_print.c
*/

#include "my_rpg.h"

typedef struct coord_vertex
{
	int i;
	int j;
} c_vertex_t;

void height(map_t *map, c_vertex_t c, window_t *window,\
	sfRenderStates render)
{
	sfVector2f green = map->text_coord[map->texture_place[c.i][c.j]][5];
	sfVector2f blue = map->text_coord[map->texture_place[c.i][c.j]][2];
	sfVector2f yellow = map->text_coord[map->texture_place[c.i][c.j]][3];
	sfVector2f red = map->text_coord[map->texture_place[c.i][c.j]][6];

	sfVertex vertex0 = {.position = map->map[c.i+1][c.j].n_map[0],\
		.color = sfWhite, .texCoords = red};
	sfVertex vertex1 = {.position = map->map[c.i][c.j].n_map[3],\
		.color = sfWhite, .texCoords = yellow};
	sfVertex vertex2 = {.position = map->map[c.i][c.j].n_map[2],\
		.color = sfWhite, .texCoords = blue};
	sfVertex vertex3 = {.position = map->map[c.i+1][c.j].n_map[1],\
		.color = sfWhite, .texCoords = green};
	if (map->map[c.i][c.j].tile[4] > map->map[c.i+1][c.j].tile[4]) {
		append_strip(map, vertex0, vertex1, vertex2);
		sfVertexArray_append(map->vert, vertex3);
		sfVertexArray_append(map->vert, vertex0);
		sfVertexArray_setPrimitiveType(map->vert, sfQuads);
		DRAW_VERTEX(window->RenderWindow, map->vert, &render);
	}
}

void height2(map_t *map, c_vertex_t c, window_t *window,\
	sfRenderStates render)
{
	sfVector2f red = map->text_coord[map->texture_place[c.i][c.j]][5];
	sfVector2f green = map->text_coord[map->texture_place[c.i][c.j]][1];
	sfVector2f blue = map->text_coord[map->texture_place[c.i][c.j]][2];
	sfVector2f yellow = map->text_coord[map->texture_place[c.i][c.j]][4];

	sfVertex vertex0 = {.position = map->map[c.i][c.j+1].n_map[3],\
		.color = sfWhite, .texCoords = red};
	sfVertex vertex1 = {.position = map->map[c.i][c.j].n_map[2],\
		.color = sfWhite, .texCoords = blue};
	sfVertex vertex2 = {.position = map->map[c.i][c.j].n_map[1],\
		.color = sfWhite, .texCoords = green};
	sfVertex vertex3 = {.position = map->map[c.i][c.j+1].n_map[0],\
		.color = sfWhite, .texCoords = yellow};
	if (map->map[c.i][c.j].tile[4] > map->map[c.i][c.j+1].tile[4]) {
		append_strip(map, vertex0, vertex1, vertex2);
		sfVertexArray_append(map->vert, vertex3);
		sfVertexArray_setPrimitiveType(map->vert, sfQuads);
		DRAW_VERTEX(window->RenderWindow, map->vert, &render);
	}
}

void draw_tile(window_t *window, map_t *map, int i, int j)
{
	sfRenderStates render = {sfBlendNone, sfTransform_Identity,\
		map->texture, NULL};
	c_vertex_t co_d = { i, j };

	create_strip(map, i, j);
	DRAW_VERTEX(window->RenderWindow, map->vert, &render);
	sfVertexArray_clear(map->vert);
	height(map, co_d, window, render);
	DRAW_VERTEX(window->RenderWindow, map->vert, &render);
	sfVertexArray_clear(map->vert);
	height2(map, co_d, window, render);
	DRAW_VERTEX(window->RenderWindow, map->vert, &render);
	sfVertexArray_clear(map->vert);
}
