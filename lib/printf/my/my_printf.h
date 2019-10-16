/*
** EPITECH PROJECT, 2017
** lib my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINT_F_
#define MY_PRINT_F_

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(char *nb);
void	my_put_unbr(char *nb);
void	my_put_long(char *nb);
void	my_print_u(void *unb);
void	my_print_up_x(void *hexa_maj);
void	my_print_x(void *hexa);
void	my_print_o(void *octa);
void	my_print_d(void *nb);
void	my_print_s(void *str);
void	my_print_p(void *str);
void	my_print_c(void *c);
void	my_print_b(void *binary);
void	my_c_star(void *str);
void	my_put_error(void *str);
void	my_print_up_s(void *no_p);
void	zero_octa(int nb);
char	*my_revstr(char *str);
void	my_put_base(long nb, int base, char *chara);
int	my_strlen(char *str);
int	no_printable(char c, int i);
void	my_printf(char *, ...);

#endif
