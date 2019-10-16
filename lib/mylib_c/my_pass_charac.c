/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** pass_charac.c
*/

#include "libmy.h"

char *my_pass_charac(char *str, char charac)
{
	for (; *str && *str != charac; str++);
	str++;
	return (str);
}
