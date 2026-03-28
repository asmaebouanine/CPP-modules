int	max(int *tab, unsigned int len)
{
	unsigned int i;
	int max;

	i = 0;
	if (len == 0)
		return 0;
	max = tab[i];
	while (len > i)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
