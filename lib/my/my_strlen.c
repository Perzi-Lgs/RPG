/*
** EPITECH PROJECT, 2017
** minishell.c
** File description:
** main.c
*/

#include <string.h>

size_t my_strlen(char *str)
{
	size_t i = 0;

	for (; str[i] != '\0'; i++);
	return (i);
}
