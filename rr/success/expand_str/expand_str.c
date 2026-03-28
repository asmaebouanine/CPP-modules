#include <unistd.h>

void	expand(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
		{
			c = 1;
			i++;
		}
		if(str[i] && c == 1)
		{
			write (1, "   ", 3);
			c = 0;
		}
		while (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			write (1, &str[i], 1);
			i++;
		}
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
		expand(av[1]);
	write (1, "\n", 1);
}
