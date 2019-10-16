/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** create_2D_map.c
*/

#include "my_rpg.h"

sfVector2f project_iso_point(float x, float y, float z)
{
	sfVector2f point = { 0, 0 };

	point.x = cos(158* M_PI / 180) * x - cos(158* M_PI / 180) * y;
	point.y = sin(154* M_PI / 180) * y + sin(154* M_PI / 180) * x - z;
	return (point);
}

sfVector2f create_iso_point_1(int i, int j, map_t *map)
{
	sfVector2f point = {0, 0};
	float tmp_x = 0;
	float tmp_y = 0;

	tmp_x = i*cos(0)-j*sin(0);
	tmp_y = i*sin(0)+j*cos(0);
	point = project_iso_point(tmp_x*80, tmp_y*80,\
		map->map[i][j].tile[0]*80);
	return (point);
}

sfVector2f create_iso_point_5(int i, int j, map_t *map)
{
	sfVector2f point = {0, 0};
	float tmp_x = 0;
	float tmp_y = 0;

	tmp_x = (i+0.5)*cos(0)-(j+0.5)*sin(0);
	tmp_y = (i+0.5)*sin(0)+(j+0.5)*cos(0);
	point = project_iso_point(tmp_x*80, tmp_y*80,\
		map->map[i][j].tile[0]*80);
	return (point);
}
