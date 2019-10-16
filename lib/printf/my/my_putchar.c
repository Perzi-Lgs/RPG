/*
** EPITECH PROJECT, 2017
** My_Putchar
** File description:
** Generic of Printf
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}
