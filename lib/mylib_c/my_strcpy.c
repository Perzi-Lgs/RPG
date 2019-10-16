/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** my_strcpy.c
*/

#include "libmy.h"

char *my_strmcpy(char *str)
{
	char *res;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * my_strlen(str) + 1);
	if (!res)
		return (NULL);
	for (int i = 0; str[i]; i++) {
		res[i] = str[i];
		res[i + 1] = '\0';
	}
	return (res);
}

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	if (!src)
		return (NULL);
	while (src[i] != '\0') {
		dest[i] = src[i];
		dest[i + 1] = '\0';
		i += 1;
	}
	return (dest);
}
