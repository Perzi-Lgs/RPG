/*
** EPITECH PROJECT, 2017
** try
** File description:
** nbr
*/

void	my_putchar(char c);

int	size(int n, int i)
{
	while (n >= 1) {
		n = n / 10;
		i++;
	}
	return (i);
}

int power(int p)
{
	int	c;

	c = 1;
	while (p > 1) {
		c *= 10;
		p--;
	}
	return (c);
}

void	my_put_nbr(int n)
{
	int	i = 0;
	int	initial_n = n;
	int	p = 1;

	if (n < 0) {
		n *= -1;
		initial_n *= -1;
		my_putchar('-');
	} else if (n == 0)
		my_putchar('0');
	i = size(n, i);
	while (i > 0) {
		n = initial_n;
		p = power(i);
		n = n / p % 10;
		my_putchar((n + '0'));
		i--;
	}
}

void	my_put_unbr(unsigned int n)
{
	int i = 0;
	unsigned int	initial_n = n;
	int p = 1;

	if (n == 0)
		my_putchar('0');
	i = size(n, i);
	while (i > 0){
		n = initial_n;
		p = power(i);
		n = n / p % 10;
		my_putchar(n + '0');
		i--;
	}
}

void	my_put_long(long n)
{
	int	i = 0;
	long	initial_n = n;
	int	p = 1;

	if (n == 0)
		my_putchar('0');
	i = size(n, i);
	while (i > 0){
		n = initial_n;
		p = power(i);
		n = n / p % 10;
		my_putchar(n + '0');
		i--;
	}
}
