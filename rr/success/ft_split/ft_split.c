#include <stdlib.h>

char	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **ptr;

	i = 0;
	k = 0;
	if (!(ptr = (char **)malloc(sizeof(char *) * (1000))))
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		j = 0;
		if (!(ptr[k] =(char *)malloc(sizeof(char) * (1000))))
			return (0);
		while (str[i] && str[i] != ' '&&str[i] != '\t' && str[i] != '\n')
			ptr[k][j++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] =='\n')
			i++;
		ptr[k][j] = '\0';
		k++;
	}
	ptr[k] = NULL;
	return (ptr);
}
