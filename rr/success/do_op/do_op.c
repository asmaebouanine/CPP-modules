#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	int i;
	int num;
	int num1;
	i = 0;
	if (ac == 4)
	{
		num = atoi(av[1]);
		num1 = atoi(av[3]);
		if (av[2][i] == '-')
			printf("%d", num - num1);
		if (av[2][i] == '+')
			printf("%d", num +num1);
		if (av[2][i] == '*')
			                        printf("%d", num * num1);
		if (av[2][i] == '/')
			                        printf("%d", num / num1);
		if (av[2][i] == '%')
			                        printf("%d", num % num1);
	}
	printf ( "\n");
}

