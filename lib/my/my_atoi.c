/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** my_atoi.c
*/

int	my_atoi(char *str)
{
	int     result = 0;
	int     tmp = 1;
	int	nb = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		while ((str[i] == '-') && nb == 0) {
			tmp *= -1;
			i++;
		}
		result = result * 10 + str[i] - '0';
		nb = 1;
	}
	result = result * tmp;
	return (result);
}
