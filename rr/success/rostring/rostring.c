#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int c = 0;
	if (ac > 1)
	{
		while(av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i++;
		while(av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			 while(av[1][i] == ' ' || av[1][i] == '\t')
			 {
				 c = 1;
				 i++;
			 }
			 if (av[1][i] && c == 1)
			 {
				 write (1, " ", 1);
				 c = 0;
			 }
			  while(av[1][i] != ' '&& av[1][i] != '\t' && av[1][i])
			  {
				  write (1, &av[1][i], 1);
				  i++;
			  }
			  if (!av[1][i])
				  write (1, " ", 1);
		}
		i = 0;
		 while(av[1][i] == ' ' || av[1][i] == '\t')
			                         i++;
		  while(av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
		  {
			  write (1, &av[1][i], 1);
			  i++;
		  }
	}
	write (1, "\n", 1);
}
				             


