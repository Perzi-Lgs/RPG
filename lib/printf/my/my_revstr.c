/*
** EPITECH PROJECT, 2017
** Rev str
** File description:
** reverse a string
*/

int	my_strlen(char *str);

char	*my_revstr(char *str)
{
	int	len = my_strlen(str) - 1;
	char	tmp;

	for (int i = 0; i < len - i; i++) {
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
	}
	return (str);
}
