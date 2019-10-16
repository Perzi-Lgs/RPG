/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** get_next_line.h
*/

#include "libmy.h"

char *get_next_line(int fd)
{
	char *res = malloc(sizeof(char) * 4096);
	char c;
	int nbr = 1;

	if (fd < 0 || !res)
		return (NULL);
	nbr = read(fd, &c, 1);
	for (int i  = 0; nbr != 0; i++) {
		if (c == '\n' || c == '\0') {
			res[i] = c;
			res[i + 1] = '\0';
			return (res);
		} else {
			res[i] = c;
			res[i + 1] = '\0';
		}
		nbr = read(fd, &c, 1);
	}
	free(res);
	return (NULL);
}
