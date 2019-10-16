/*
** EPITECH PROJECT, 2017
** my_world.h
** File description:
** window.c
*/

#include <unistd.h>

void my_putstr2(char *str)
{
	for (int i = 0; str[i]; i++)
		write(2, &str[i], 1);
}
