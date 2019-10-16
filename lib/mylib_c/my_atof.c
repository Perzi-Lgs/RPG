/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_atof.c
*/

#include "libmy.h"

float my_atof(char *str)
{
	float nb = 0.0;
	int k = 0;
	int i;

	for (k = 0; str[k] != 0 && str[k] >= '0' && str[k] <= '9'; k++)
		nb = nb * 10.0 + (str[k] - '0');
	k++;
	if (str[k] == '.')
		for (i = 0; str[k] != 0; i--)
			nb = nb * 10.0 + (str[k] - '0');
	for (; i < 0; i++, nb *= 0.1);
	return (nb);
}

static char *put_decimal(char *str, float myfloat, int i)
{
	signed long int decipart;

	str[i++] = '.';
	myfloat *= 100;
	decipart = (signed long int)(myfloat + 0.5);
	str[i++] = ((decipart / 10) % 10) + '0';
	str[i++] = (decipart % 10) + '0';
	str[i] = '\0';
	return (str);
}

char *my_ctof(float nbr)
{
	float myfloat = nbr;
	signed long int intpart;
	char *str = malloc(sizeof(char) * (int)nbr + 1);
	int i = 0;

	if (myfloat < 0) {
		str[i++] = '-';
		str[i] = '\0';
		myfloat *= -1;
	}
	intpart = (signed long int)myfloat;
	myfloat -= intpart;
	for (; intpart > 0; intpart /= 10, i++)
		str[i] = (intpart % 10) + '0';
	if (str[i] == '\0')
		str[i++] = '0';
	my_revstr(str);
	put_decimal(str, myfloat, i);
	return (str);
}
