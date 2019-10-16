/*
** EPITECH PROJECT, 2017
** PRINTF
** File description:
** PRINTF core
*/

#include <stdarg.h>
#include "my_printf.h"

void	my_put_base(long nb, int base, char *chara)
{
	if (nb < 0) {
		nb *= -1;
		my_putchar('-');
	}
	if (nb >= base)
		my_put_base(nb / base, base, chara);
	my_putchar(chara[nb % base]);
}

int	compar_modul(char *str, int i, void *arg)
{
	void	(*print[13])(void*) = {my_print_d, my_print_d, my_print_o,
					my_print_x, my_print_up_x, my_print_u,
					my_print_c, my_print_s, my_print_p,
					my_print_b, my_print_up_s, my_c_star,
					my_put_error};
	char	*letters = "dioxXucspbSae";

	for (int j = 0; letters[j] != '\0'; j++)
		if (letters[j] == str[i + 1])
			print[j](arg);
	return (i++);
}

int	compar_chara(char *str, int i)
{
	if (str[i] == '%' && str[i + 1] == '%') {
		my_putchar('%');
		i = i + 1;
	} else
		my_putchar(str[i]);
	return (i);
}

void	my_printf(char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] == '%') && (str[i + 1] != '%'))
			i = compar_modul(str, i, va_arg(ap, void*)) + 1;
		else
			i = compar_chara(str, i);
	}
	va_end(ap);
}
