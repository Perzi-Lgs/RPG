/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** my_atoi.c
*/

#include "libmy.h"

int my_atoi(char *str)
{
	int result = 0;
	int tmp = 1;
	int nb = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		for (; (str[i] == '-') && nb == 0; i++)
			tmp *= -1;
		result = result * 10 + str[i] - '0';
		nb = 1;
	}
	result = result * tmp;
	return (result);
}
