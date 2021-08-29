/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:27:11 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/09 20:13:04 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int			i;
	char		*p1;
	const char	*p2;

	p1 = (char *)dst;
	p2 = (const char *)src;
	if (p1 < p2)
	{
		i = 0;
		while (i < (int)n)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	else if (p1 > p2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			p1[i] = p2[i];
			i--;
		}
	}
	return (dst);
}
