/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** my_strlen.c
*/

#include "libmy.h"

size_t my_arraylen(char **array)
{
	size_t i = 0;

	if (!array)
		return (0);
	for (; array[i]; i++);
	return (i);
}

size_t my_strlen(char *str)
{
	size_t i = 0;

	if (!str)
		return (0);
	for (; str[i]; i++);
	return (i);
}

size_t my_intlen(int nbr)
{
	size_t i = 0;

	if (nbr < 0)
		nbr *= -1;
	for (; nbr > 0; nbr /= 10, i++);
	return (i);
}
