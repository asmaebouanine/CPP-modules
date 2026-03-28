#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int i;
	char *cp;

	i = 0;
	while (src[i])
		i++;
	cp = malloc(sizeof(char)* (i + 1));
	if (!cp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
