/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** init_main_menu_vertex.c
*/

#include "my_rpg.h"

void init_color_menu_button(sfVertex **vertices, int i)
{
	sfColor black = sfColor_fromRGBA(40, 99, 88, 60);
	vertices[i][0].color = black;
	vertices[i][1].color = sfTransparent;
	vertices[i][2].color = sfTransparent;
	vertices[i][3].color = black;
}

int init_fondu_button(sfVertex **vertices)
{
	sfVector2f pos = {1355, 465};
	sfVector2f pos2 = {1755, 465};
	sfVector2f pos3 = {1755, 515};
	sfVector2f pos4 = {1355, 515};

	for (int i = 0; i < 4; i++) {
		vertices[i] = malloc(sizeof(sfVertex) * 4);
		if (!vertices[i])
			return (-1);
		vertices[i][0].position = pos;
		vertices[i][1].position = pos2;
		vertices[i][2].position = pos3;
		vertices[i][3].position = pos4;
		init_color_menu_button(vertices, i);
		pos.y += 100;
		pos2.y += 100;
		pos3.y += 100;
		pos4.y += 100;
	}
	return (0);
}

void init_vertex_array(main_menu_t *menu)
{
	for (int i = 0; i < 4; i++) {
		menu->overlay.vert[i] = sfVertexArray_create();
		sfVertexArray_append(menu->overlay.vert[i],\
			menu->overlay.vertices[i][0]);
		sfVertexArray_append(menu->overlay.vert[i],\
			menu->overlay.vertices[i][1]);
		sfVertexArray_append(menu->overlay.vert[i],\
			menu->overlay.vertices[i][2]);
		sfVertexArray_append(menu->overlay.vert[i],\
			menu->overlay.vertices[i][3]);
		sfVertexArray_append(menu->overlay.vert[i],\
			menu->overlay.vertices[i][0]);
		sfVertexArray_setPrimitiveType(menu->overlay.vert[i], sfQuads);
	}
}

void init_overlay_bck_2(main_menu_t *menu)
{
	sfVertexArray_append(menu->overlay.bck, menu->overlay.bck_pts[0]);
	sfVertexArray_append(menu->overlay.bck, menu->overlay.bck_pts[1]);
	sfVertexArray_append(menu->overlay.bck, menu->overlay.bck_pts[2]);
	sfVertexArray_append(menu->overlay.bck, menu->overlay.bck_pts[3]);
}

void init_overlay_bck(main_menu_t *menu)
{
	sfColor up_arr = sfColor_fromRGBA(28, 59, 53, 52);
	sfColor dwn_arr = sfColor_fromRGBA(33, 51, 68, 52);

	sfVector2f pos1 = {1315, 420};
	sfVector2f pos2 = {1815, 420};
	sfVector2f pos3 = {1815, 850};
	sfVector2f pos4 = {1315, 850};
	menu->overlay.bck_pts = malloc(sizeof(sfVertex) * 4);
	menu->overlay.bck_pts[0].position = pos1;
	menu->overlay.bck_pts[0].color = up_arr;
	menu->overlay.bck_pts[1].position = pos2;
	menu->overlay.bck_pts[1].color = sfTransparent;
	menu->overlay.bck_pts[2].position = pos3;
	menu->overlay.bck_pts[2].color = sfTransparent;
	menu->overlay.bck_pts[3].position = pos4;
	menu->overlay.bck_pts[3].color = dwn_arr;
	menu->overlay.bck = sfVertexArray_create();
	init_overlay_bck_2(menu);
	sfVertexArray_setPrimitiveType(menu->overlay.bck, sfQuads);
}
