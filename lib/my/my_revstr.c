/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** my_revstr.c
*/

#include <string.h>

size_t my_strlen(char *);

char	*my_revstr(char *str)
{
	size_t	len = my_strlen(str) - 1;
	char	tmp;

	for (size_t i = 0; i < len - i; i++) {
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
	}
	return (str);
}
