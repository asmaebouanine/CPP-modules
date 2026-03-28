#include <unistd.h>
int	ft_compere(char *str, char c)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return 1;
}

void	ft_union(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	char printed[128] = {0};
	int k = 0;
	while (s1[i])
	{
		if (ft_compere(printed, s1[i]))
		{
			write (1, &s1[i], 1);
			printed[k++] = s1[i];
		}
		i++;
	}
	while (s2[j])
	{
		if (ft_compere(printed, s2[j]))
		{
			write (1, &s2[j], 1);
			printed[k++] = s2[j];
		}
		j++;
	}
}
int main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write (1, "\n", 1);
}

