/*
** EPITECH PROJECT, 2017
** my_world
** File description:
** my_itoa.c
*/

#include "libmy.h"

static void do_itoa(char *res, int b, int i, int a)
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

char *my_itoa(int nbr)
{
	int tmp;
	int a;
	int cpt = 1;
	int b = 0;
	char *res = malloc(sizeof(char) * my_intlen(nbr) + 1);

	if (nbr < 0) {
		nbr *= -1;
		b = 1;
	}
	tmp = nbr;
	for (; tmp >= 10; tmp /= 10, cpt *= 10);
	for (int i = 0; cpt > 0; i++) {
		a = nbr / cpt;
		do_itoa(res, b, i, a);
		nbr = nbr % cpt;
		cpt = cpt / 10;
	}
	return (res);
}
