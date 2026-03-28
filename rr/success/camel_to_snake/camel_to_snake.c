#include <unistd.h>

void	ft_camel(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			write(1, "_", 1);
			str[i]+=32;
		}
		write (1, &str[i], 1);
		i++;
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
		ft_camel(av[1]);
	write (1, "\n", 1);
}
