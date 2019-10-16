/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** file for moving inside of the inventory
*/

#include "my_rpg.h"

int	move_inv_right(gsprites_t *sprites, int pos)
{
	if (pos == 3 || pos == 7 || pos == 11)
		return (pos);
	else {
		pos++;
		sprites->cadre.pos.x += 145;
	}
	return (pos);
}

int	move_inv_left(gsprites_t *sprites, int pos)
{
	if (pos == 0 || pos == 4 || pos == 8)
		return (pos);
	else {
		pos--;
		sprites->cadre.pos.x -= 145;
	}
	return (pos);
}

int	move_inv_up(gsprites_t *sprites, int pos)
{
	if (pos >= 0 && pos <= 3)
		return (pos);
	else {
		pos -= 4;
		sprites->cadre.pos.y -= 95;
	}
	return (pos);
}

int	move_inv_down(gsprites_t *sprites, int pos)
{
	if (pos >= 8 && pos <= 11)
		return (pos);
	else {
		pos += 4;
		sprites->cadre.pos.y += 95;
	}
	return (pos);
}

int	move_inside_inv(inv_t *inv, int pos, game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		pos = move_inv_right(&inv->sprites, pos);
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		pos = move_inv_up(&inv->sprites, pos);
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		pos = move_inv_down(&inv->sprites, pos);
	if (sfKeyboard_isKeyPressed(sfKeyReturn))
		select_item(&inv->sprites, game, pos);
	return (pos);
}
