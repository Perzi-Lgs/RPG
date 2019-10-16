/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** create_2D_map.c
*/

#include "my_rpg.h"

sfVector2f create_iso_point_2(int i, int j, map_t *map)
{
	sfVector2f point = {0, 0};
	float tmp_x = 0;
	float tmp_y = 0;

	tmp_x = i*cos(0)-(j+1)*sin(0);
	tmp_y = i*sin(0)+(j+1)*cos(0);
	point = project_iso_point(tmp_x*80, tmp_y*80,\
		map->map[i][j].tile[0]*80);
	return (point);
}

sfVector2f create_iso_point_3(int i, int j, map_t *map)
{
	sfVector2f point = {0, 0};
	float tmp_x = 0;
	float tmp_y = 0;

	tmp_x = (i+1)*cos(0)-(j+1)*sin(0);
	tmp_y = (i+1)*sin(0)+(j+1)*cos(0);
	point = project_iso_point(tmp_x*80, tmp_y*80,\
		map->map[i][j].tile[0]*80);
	return (point);
}

sfVector2f create_iso_point_4(int i, int j, map_t *map)
{
	sfVector2f point = {0, 0};
	float tmp_x = 0;
	float tmp_y = 0;

	tmp_x = (i+1)*cos(0)-j*sin(0);
	tmp_y = (i+1)*sin(0)+j*cos(0);
	point = project_iso_point(tmp_x*80, tmp_y*80,\
		map->map[i][j].tile[0]*80);
	return (point);
}

sfVector2f *create_2d_map(int i , int j, map_t *map)
{
	sfVector2f *projected_point = malloc(sizeof(sfVector2f) * 5);
	float *value = malloc(sizeof(float) * 5);

	if (!value || !projected_point)
		return (NULL);
	projected_point[0] = create_iso_point_1(i, j, map);
	projected_point[1] = create_iso_point_2(i, j, map);
	projected_point[2] = create_iso_point_3(i, j, map);
	projected_point[3] = create_iso_point_4(i, j, map);
	projected_point[4] = create_iso_point_5(i, j, map);

	for (int i = 0; i< 5; i++) {
		projected_point[i].x += 1000;
		projected_point[i].y += 150;
	}
	return (projected_point);
}
