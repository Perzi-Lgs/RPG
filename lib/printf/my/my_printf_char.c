/*
** EPITECH PROJECT, 2017
** PRINTF
** File description:
** printchara
*/

#include "my_printf.h"
#include <unistd.h>

void	my_print_u(void *unbr)
{
	my_put_unbr(unbr);
}

void	my_print_c(void *chara)
{
	write(1, &chara, 1);
}

void	my_print_s(void *str)
{
	my_putstr(str);
}
