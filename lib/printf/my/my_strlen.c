/*
** EPITECH PROJECT, 2017
** Fonction Principale
** File description:
** My_Strlen
*/

#include <unistd.h>

int	my_strlen(char const *str)
{
	int	count  = 0;

	while (str[count] != '\0')
		count++;
	return (count);
}
