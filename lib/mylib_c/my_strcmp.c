/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** my_strcmp.c
*/

#include "libmy.h"

int my_strscmp(char *str1, char* str2)
{
	int j = 0;

	for (int i = 0; str1[i]; i++, j++) {
		if (str1[i] != str2[j])
			return (1);
	}
	return (0);
}

int my_strcmp(char *str1, char* str2)
{
	int j = 0;

	if (my_strlen(str1) != my_strlen(str2))
		return (1);
	for (int i = 0; str1[i]; i++, j++)
		if (str1[i] != str2[j])
			return (1);
	return (0);
}
