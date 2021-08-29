/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:47:03 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/07 17:16:44 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen2(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)hay);
	while (hay[i] && len != 0 && len >= ft_strlen2(needle))
	{
		j = 0;
		while (hay[i + j] == needle[j] && hay[i + j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&hay[i]);
		i++;
		len--;
	}
	return (NULL);
}
