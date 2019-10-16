/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_menset.c
*/

#include "libmy.h"

void my_memset(char *str, int size)
{
	for (int i = 0; i < size; i++)
		str[i] = '\0';
}

void my_memset_array(char **array)
{
	int count = 0;

	for (int i = 0; array[i]; i++, count++);
	for (int i = 0; i < count; i++)
		array[i] = NULL;
}
