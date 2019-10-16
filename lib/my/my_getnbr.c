/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_getnbr.c
*/

static int signe(char const *str)
{
	int r = 1;
	int i = 0;
	int a = 0;

	while (!(str[i] >= '0' && str[i] <= '9')) {
		if (str[i] == '-')
			a += 1;
		i++;
	}
	while (a != 0 && a != 1)
		a -= 2;
	if (a == 1)
		r = -1;
	else
		r = 1;
	return (r);
}

static int nbr(char const *str)
{
	int i = 0;

	while (!(str[i] >= '0' && str[i] <= '9')) {
		if (!(str[i] == '-' || str[i] == '+')) {
				i = - 10;
				return (i);
			}
		i += 1;
	}
	return (i);
}

int my_getnbr(char const *str)
{
	int n = 0;
	int c = signe(str);
	int i = nbr(str);

	if (i < 0)
		return (0);
	while (str[i] <= '9' && str[i] >= '0') {
		if (str[i] >= '0' && str[i] <= '9') {
			n = n + (str[i] - 48);
			n = n * 10;
		}
		i += 1;
	}
	n = n * c;
	n = n / 10;
	return (n);
}
