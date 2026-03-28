#include <unistd.h>

int	check(char c, char *str, int j)
{
	int 	i;

	i = 0;
	while (i < j)
	{
		if (str[i] == c)
			return 0;
		i++;
	}
	return 1;
}

int main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j] &&check(av[1][i],av[1],i))
				{
					write (1, &av[1][i], 1);
					break;
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
}
