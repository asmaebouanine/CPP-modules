#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 55
#endif

char	*ft_strdup(char *str)
{
	int i;
	char *cp;

	i = 0;
	while (str[i])
		i++;
	cp = malloc(i + 1);
	if (!cp)
		return NULL;
	i = 0;
	while (str[i])
	{
		cp[i] = str[i];
		i++;
	}
	cp[i] = '\0';
	return cp;
}

char *get_next_line(int fd)
{
	int i;
	static int read_buff;
	static int pos;
	static char buffer[BUFFER_SIZE];
	char	line[39999];

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while(1)
	{
		if (pos >= read_buff)
		{
			read_buff = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (read_buff <= 0)
				break;
		}
		line[i++] = buffer[pos++];
		if(line[i -1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return NULL;
	return (ft_strdup(line));
}
