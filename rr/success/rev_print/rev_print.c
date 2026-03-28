#include <unistd.h>
void	rev(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		write (1, &str[i], 1);
		i--;
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
		rev(av[1]);
	write (1, "\n", 1);
}

