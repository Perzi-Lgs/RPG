/*
** EPITECH PROJECT, 2017
** PRINTF
** File description:
** printnbr
*/

#include <stdlib.h>
#include "my_printf.h"

void	my_print_d(void *nb)
{
	my_put_nbr(nb);
}

void	my_print_o(void *octa)
{
	my_put_base((long)(octa), 8, "01234567");
}

void	my_print_x(void *hexa)
{
	my_put_base((long)(hexa), 16, "0123456789abcdef");
}

void	my_print_up_x(void *hexa)
{
	my_put_base((long)(hexa), 16, "0123456789ABCDEF");
}

void	my_print_p(void *ptr)
{
	my_putstr("0x");
	my_print_x(ptr);
}
