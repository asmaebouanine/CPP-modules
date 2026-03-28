#include <unistd.h>

void ft_putnbr(int n)
{
	char c;
	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_atoi(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}
int main(int ac, char **av)
{
	int i = 1;
	int num;
	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write (1, " x ", 3);
			ft_putnbr(num);
			write (1, " = ", 3);
			ft_putnbr(i * num);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}
