/*
** EPITECH PROJECT, 2017
** PRINTF
** File description:
** S & b
*/

#include "my_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	my_print_b(void *binary)
{
	my_put_base((long)(binary), 2, "01");
}

int	octa_str(char chara, int i)
{
	my_putchar('\\');
	if (chara < 8)
		my_putstr("00");
	if (chara <= 64 && chara > 8)
		my_putstr("0");
	my_put_base((long)(chara), 8, "01234567");
	i++;
	return (i);
}

void	my_print_up_s(void *str)
{
	char	*string = str;

	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] < 32 || string[i] >= 127)
			i = octa_str(string[i], i);
		my_putchar(string[i]);
	}
}

void	my_put_error(void *str)
{
	char	*string = str;

	write(2, string, my_strlen(string));
}

void	my_c_star(void *str)
{
	char	**array = str;

	for (int i = 0; array[i]; i++) {
		my_printf("Array[%d] : %s\n", i, array[i]);
	}
}
