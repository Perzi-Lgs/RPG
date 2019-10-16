/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** fct for creating a sfText
*/

#include "my_rpg.h"

sfText	*create_text(sfText *text, sfFont *font, char *str, int size)
{
	text = sfText_create();
	sfText_setString(text, str);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, size);
	return (text);
}
