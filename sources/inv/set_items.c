/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** set the variable items at 1 or 0
*/

#include "my_rpg.h"

void	set_items(int state, inv_t *inv)
{
	if (state == 0)
		inv->items = 1;
	else
		inv->items = 0;
}
