/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** my_str_word_tab.c
*/

#include "libmy.h"

static char *fill_str(char *new_str, char *str, int *i, int t)
{
	if (str[*i] == '"') {
		*i += 1;
		for (; str[*i] && str[*i] != '"'; *i += 1, t++) {
			new_str[t] = str[*i];
			new_str[t + 1] = '\0';
		}
		return (new_str);
	} else {
		new_str[t] = str[*i];
		new_str[t + 1] = '\0';
	}
	return (new_str);
}

static char **simple_str_word_tab(char *str)
{
	int k = 0;
	char **tab = malloc(sizeof(char *) * my_strlen(str));

	if (!tab)
		return (NULL);
	for (int i = 0; str[i]; i++, k++) {
		tab[k] = malloc(sizeof(char) * my_strlen(str));
		if (!tab[k])
			return (NULL);
		tab[k + 1] = NULL;
		for (int t = 0; str[i] != '\n' && str[i]; t++, i++) {
			tab[k] = fill_str(tab[k], str, &i, t);
		}
		if (str[i] == '\0')
			return (tab);
	}
	return (tab);
}

static int is_sep(char *separator, char character)
{
	for (int i = 0; separator[i]; i++)
		if (separator[i] == character)
			return (1);
	return (0);
}

static char **str_to_word_tab(char *str, char *sep)
{
	int k = 0;
	char **tab = malloc(sizeof(char *) * (my_strlen(str) + 1));

	if (!tab)
		return (NULL);
	for (int i = 0; str[i]; k++) {
		tab[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
		if (!tab[k])
			return (NULL);
		tab[k + 1] = NULL;
		for (; str[i] && is_sep(sep, str[i]) == 1; i++);
		for (int t = 0; str[i] && is_sep(sep, str[i]) == 0; i++, t++)
			tab[k] = fill_str(tab[k], str, &i, t);
		for (; str[i] && is_sep(sep, str[i]) == 1; i++);
		if (str[i] == '\0')
			return (tab);
	}
	return (tab);
}

char **my_str_word_tab(char *str, char *separator)
{
	if (!str)
		return (NULL);
	if (!separator)
		return (simple_str_word_tab(str));
	return (str_to_word_tab(str, my_strcat(separator, "\n")));
}
