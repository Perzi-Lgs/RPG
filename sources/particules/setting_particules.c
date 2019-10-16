/*
** EPITECH PROJECT, 2018
** .
** File description:
** setting_particules.c
*/

#include "my_rpg.h"
#include "character.h"

int my_rand(int a, int b)
{
	return (rand() % (b - a) + a);
}

buffer_part *new_part_buffer(int size)
{
	buffer_part *this;
	const size_t size_m = (sizeof(buffer_part) + sizeof(sfVertex) *\
	size * 4 + sizeof(t_info) * size);
	void *ptn = malloc(size_m);

	if (ptn == NULL)
		return (NULL);
	memset(ptn, 0, size_m);
	this = (buffer_part*)(ptn);
	this->size = size;
	this->vertex = (sfVertex*)(ptn + sizeof(buffer_part));
	this->info = (t_info*)(this->vertex + (size * 4));
	return (this);
}

void set_vertex(buffer_part *this, uint id, sfVector2f pos, int nb)
{
	int x = 10;
	int y = 192;

	this->vertex[(id * 4) + 0].texCoords = (sfVector2f){0, 0};
	this->vertex[(id * 4) + 1].texCoords = (sfVector2f){y, 0};
	this->vertex[(id * 4) + 2].texCoords = (sfVector2f){y, y};
	this->vertex[(id * 4) + 3].texCoords = (sfVector2f){0, y};
	this->vertex[(id * 4) + 0].position =
	(sfVector2f){pos.x + 0 + nb, pos.y + 0 + nb};
	this->vertex[(id * 4) + 1].position =
	(sfVector2f){pos.x + x, pos.y + 0 + nb};
	this->vertex[(id * 4) + 2].position =
	(sfVector2f){pos.x + x, pos.y + x};
	this->vertex[(id * 4) + 3].position =
	(sfVector2f){pos.x + 0 + nb, pos.y + x};
}

void set_part(buffer_part *this, uint id, sfVector2f pos, int nb)
{
	if (id >= this->size)
		return;
	set_vertex(this, id, pos, nb);
	this->vertex[(id * 4) + 0].color = sfWhite;
	this->vertex[(id * 4) + 1].color = sfWhite;
	this->vertex[(id * 4) + 2].color = sfWhite;
	this->vertex[(id * 4) + 3].color = sfWhite;
	this->info[id].speed = (sfVector2f){my_rand(-3, 3), my_rand(-3, 3)};
	this->info[id].life = 1.0;
}

uint new_part(buffer_part *this)
{
	for (uint id = this->size - 1; id != 0; id -= 1)
		if (this->info[id].life <= 0)
			return (id);
	return ((uint)(-1));
}
