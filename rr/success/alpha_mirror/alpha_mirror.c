#include <unistd.h>

void	mirror(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i]>= 'a' && str[i]<='z')
			str[i] = 'n' - str[i] + 'm';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'N' - str[i] + 'M';
		write (1, &str[i], 1);
		i++;
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
		mirror(av[1]);
	write (1, "\n", 1);
}

