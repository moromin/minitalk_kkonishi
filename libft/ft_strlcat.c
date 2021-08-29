/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:46:11 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/07 17:16:06 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (dstsize >= i + 1)
	{
		while (src[j] && i + 1 < dstsize)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	else
		i = dstsize;
	while (src[j++])
		i++;
	return (i);
}
