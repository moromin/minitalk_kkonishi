/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:56:52 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/19 13:06:31 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str;

	if (!s)
		return (ft_calloc(1, sizeof(char *)));
	size = ft_strlen(s);
	if (size < (start + len) && start < size)
		len = size - start;
	if (start >= size)
		len = 0;
	str = ft_calloc(sizeof(char) * (len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (start >= size)
		return (str);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
