/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** my_strcat.c
*/

#include "libmy.h"

char *my_strcat(char *str, char *send)
{
	int i = 0;
	char *new_str;

	if (!str || !send)
		return (NULL);
	new_str = malloc(sizeof(char) * (my_strlen(str) + my_strlen(send)) + 1);
	if (!new_str)
		return (NULL);
	for (int k = 0; str[k]; k++, i++)
		new_str[i] = str[k];
	for (int k = 0; send[k]; k++, i++)
		new_str[i] = send[k];
	new_str[i] = '\0';
	return (new_str);
}
