/*
** EPITECH PROJECT, 2017
** Lib
** File description:
** free_tab.c
*/

#include "libmy.h"

void free_tab(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}
