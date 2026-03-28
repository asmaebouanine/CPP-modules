char	*ft_strrev(char *str)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (j > i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}
