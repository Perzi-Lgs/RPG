/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** int_to_array.c
*/

#include <stdlib.h>

char **my_str_word_tab(char *, char *);
int my_arraylen(char **);
int my_atoi(char *);

int	fill_nb(int *array, char *str, int place, int i)
{
	int	res = 0;

	for (; str[i] >= '0' && str[i] <= '9'; i++) {
		res = res * 10 + (str[i] - '0');
	}
	array[place] = res;
	return (i);
}

int	*my_atoi_array(char *str)
{
	char **tab = my_str_word_tab(str, ";");
	int *array;

	if (!tab)
		return (NULL);
	array = malloc(sizeof(int) * (my_arraylen(tab) + 1));
	if (!array)
		return (NULL);
	for (int i = 0; tab[i]; i++)
		array[i] = my_atoi(tab[i]);
	return (array);
}
