/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:57:06 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/20 09:41:33 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (size1 + size2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size1 + size2)
	{
		if (i < size1)
			str[i] = s1[i];
		else if (i < size1 + size2)
			str[i] = s2[j++];
		i++;
	}
	str[i] = '\0';
	return (str);
}
