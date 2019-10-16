/*
** EPITECH PROJECT, 2018
** .
** File description:
** particule.c
*/

#include "my_rpg.h"
#include "character.h"

static sfVector2f g_startRect [20] = {
	{192 * 0, 192 * 3},
	{192 * 1, 192 * 3},
	{192 * 2, 192 * 3},
	{192 * 3, 192 * 3},
	{192 * 4, 192 * 3},
	{192 * 0, 192 * 2},
	{192 * 1, 192 * 2},
	{192 * 2, 192 * 2},
	{192 * 3, 192 * 2},
	{192 * 4, 192 * 2},
	{192 * 0, 192 * 1},
	{192 * 1, 192 * 1},
	{192 * 2, 192 * 1},
	{192 * 3, 192 * 1},
	{192 * 4, 192 * 1},
	{192 * 0, 192 * 0},
	{192 * 1, 192 * 0},
	{192 * 2, 192 * 0},
	{192 * 3, 192 * 0},
	{192 * 4, 192 * 0},
};

void update_vertex(buffer_part *this, uint id, sfVector2f start)
{
	this->vertex[(id * 4) + 0].position.x += this->info[id].speed.x;
	this->vertex[(id * 4) + 1].position.x += this->info[id].speed.x;
	this->vertex[(id * 4) + 2].position.x += this->info[id].speed.x;
	this->vertex[(id * 4) + 3].position.x += this->info[id].speed.x;
	this->vertex[(id * 4) + 0].position.y += this->info[id].speed.y;
	this->vertex[(id * 4) + 1].position.y += this->info[id].speed.y;
	this->vertex[(id * 4) + 2].position.y += this->info[id].speed.y;
	this->vertex[(id * 4) + 3].position.y += this->info[id].speed.y;
	this->vertex [(id * 4) + 0].texCoords =
	(sfVector2f){start.x + 0 , start.y};
	this->vertex [(id * 4) + 1].texCoords =
	(sfVector2f){start.x + 192, start.y};
	this->vertex [(id * 4) + 2].texCoords =
	(sfVector2f){start.x + 192, start.y + 192};
	this->vertex [(id * 4) + 3].texCoords =
	(sfVector2f){start.x + 0 , start.y + 192};
}

void update_vertex_color(buffer_part *this, uint id, sfVector2f start)
{
	(void)start;
	this->vertex[(id * 4) + 0].color.a =\
	(sfUint8)(this->info[id].life * 255.);
	this->vertex[(id * 4) + 1].color.a =\
	(sfUint8)(this->info[id].life * 255.);
	this->vertex[(id * 4) + 2].color.a =\
	(sfUint8)(this->info[id].life * 255.);
	this->vertex[(id * 4) + 3].color.a =\
	(sfUint8)(this->info[id].life * 255.);
}

void update_buffer_m(buffer_part *this, sfVector2f pos)
{
	int  idRect;
	sfVector2f start;

	for (uint id = 0; id < this->size; id += 1) {
		idRect = (int)((1. - this ->info[id].life) * 16.);
		start = g_startRect[idRect];
		if (this->info[id].life > 0)
			this->info[id].life -= 0.01;
		if (this->info[id].life <= 0) {
			set_part(this, id, pos, id);
			break;
		}
		update_vertex(this, id, start);
		update_vertex_color(this, id, start);
	}
}

void update_buffer_p(buffer_part *this, sfVector2f pos)
{
	int  idRect;
	sfVector2f start;

	for (uint id = 0; id < this->size; id += 1) {
		idRect = (int)((1. - this ->info[id].life) * 16.);
		start = g_startRect[idRect];
		if (this->info[id].life > 0)
			this->info[id].life -= 0.01;
		if (this->info[id].life <= 0) {
			set_part(this, id, pos, id);
			break;
		}
		update_vertex(this, id, start);
		update_vertex_color(this, id, start);
	}
}
