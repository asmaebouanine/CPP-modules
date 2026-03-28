#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] >= 'A' && av[i][j] <= 'Z')
					av[i][j]+=32;
				j++;
			}
			j--;
			while (av[i][j])
			{
				if((av[i][j+1]==' '||av[i][j+1]=='\t'||!av[i][j+1])&&av[i][j]>= 'a' && av[i][j] <= 'z')
				av[i][j]-=32;
				j--;
			}
			j = 0;
			while (av[i][j])
			{
				write (1, &av[i][j], 1);
				j++;
			}
			write (1, "\n", 1);
			i++;
		}
	}
	else 
		write (1, "\n", 1);
}
