#include <unistd.h>

void	putnbr(int nb)
{
	char c;

	if (nb>= 0 && nb <= 9)
	{
		c = nb + 48;
		write (1, &c, 1);
	}
	else
	{
		putnbr(nb/10);
		putnbr(nb%10);
	}
}

int main(int ac, char **av)
{
	int i = 0;
	if (ac > 1)
	{
		i = ac - 1;
		putnbr(i);
	}
	else
		write (1, "0", 1);
	write (1, "\n", 1);
}
