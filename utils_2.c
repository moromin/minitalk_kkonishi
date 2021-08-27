#include "minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

char	*ft_strjoin(char **s1, char *s2, size_t size1, size_t size2)
{
	size_t	i;
	int		j;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	tmp = *s1;
	*s1 = malloc(sizeof(char) * (size1 + size2 + 2));
	if (*s1 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size1 + size2)
	{
		if (i < size1)
			(*s1)[i] = tmp[i];
		else if (i < size1 + size2)
			(*s1)[i] = s2[j++];
		i++;
	}
	(*s1)[i] = 0x04;
	(*s1)[i + 1] = '\0';
	free(tmp);
	return (*s1);
}
