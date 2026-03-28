int	ft_atoi(const char *str)
{
	int i;
	int res;
	int sing;

	i = 0;
	sing = 1;
	res = 0;
	while (str[i] == ' ' ||(str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <='9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sing);
}
