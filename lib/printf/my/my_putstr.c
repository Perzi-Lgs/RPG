/*
** EPITECH PROJECT, 2017
** Fonction Principale
** File description:
** My_putstr
*/

void	my_putchar(char c);

void	my_putstr(char const *str)
{
	int	j = 0;
	char	c = ' ';

	while (str[j] != '\0') {
		c = str[j];
		my_putchar(c);
		j++;
	}
}
