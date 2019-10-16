/*
** EPITECH PROJECT, 2017
** my_world
** File description:
** my_itoa.c
*/

#include <stdlib.h>
#include <stdio.h>

static void itoa2(char *res, int b, int i, int a)
{
	if (b == 0) {
		res[i] = a + '0';
		res[i + 1] = '\0';
	} else {
		res[i] = '-';
		res[i + 1] = a + '0';
		res[i + 2] = '\0';
	}
}

char *itoa(int nbr)
{
	int tmp;
	int a;
	int cpt = 1;
	char *res = malloc(sizeof(char) * 9);
	int b = 0;

	if (nbr < 0) {
		nbr *= -1;
		b = 1;
	}
	tmp = nbr;
	for (; tmp >= 10; tmp /= 10, cpt *= 10);
	for (int i = 0; cpt > 0; i++) {
		a = nbr / cpt;
		itoa2(res, b, i, a);
		nbr = nbr % cpt;
		cpt = cpt / 10;
	}
	return (res);
}
