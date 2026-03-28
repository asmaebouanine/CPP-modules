#include <stdlib.h>
int	count_len(int nb)
{
	int c;

	c = 0;
	if (nb == 0)
		return 1;
	if (nb < 0)
		c++;
	while (nb)
	{
		c++;
		nb /= 10;
	}
	return c;
}

char	*ft_itoa(int nbr)
{
	int len;
	char *res;

	len = count_len(nbr);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (nbr == 0)
		res[0] = '0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	res[len] = '\0';
	while (nbr)
	{
		len--;
		res[len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (res);
}

