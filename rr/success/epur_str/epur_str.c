#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			while (av[1][i]&&av[1][i]!=' ' && av[1][i]!='\t')
			{
				write (1, &av[1][i], 1);
				i++;
			}
			while(av[1][i] == ' ' || av[1][i] == '\t')
			{
				c = 1;
				i++;
			}
			if (c == 1 && av[1][i])
			{
				write (1, " ", 1);
				c = 0;
			}
		}
	}
	write (1, "\n", 1);
}
