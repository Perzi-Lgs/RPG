/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** matchstick.h
*/

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	char *res = malloc(sizeof(char) * 500);
	char c;
	int nbr = 1;

	if (fd < 0 || res == NULL)
		return (NULL);
	nbr = read(fd, &c, 1);
	for (int i = 0; nbr != 0; i++) {
		if (c == '\n' || c == '\0')
			return (res);
		else {
			res[i] = c;
			res[i + 1] = '\0';
		}
		nbr = read(fd, &c, 1);
	}
	return (NULL);
}
