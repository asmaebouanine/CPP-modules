#include <unistd.h>

void	wstr(char *str)
{
	int i = 0;
	int c = 0;
	while (str[i])
		i++;
	i--;
	while (str[i])
	{
		while (str[i] && str[i] != ' ')
			i--;
		c = i+1;
		while (str[c] && str[c] != ' ')
		{
			write(1, &str[c], 1);
			c++;
		}
		if (str[i] == ' ')
		{
			write (1, " ", 1);
			i--;
		}
	}
}
int main(int ac,char **av)
{
	if (ac == 2)
		wstr(av[1]);
	write (1, "\n", 1);
}

