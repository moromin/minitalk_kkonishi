/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:24:03 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/07 16:26:44 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p1;
	const char	*p2;

	if (!dst && !src)
		return (NULL);
	p1 = (char *)dst;
	p2 = (const char *)src;
	while (n-- != 0)
		*p1++ = *p2++;
	return (dst);
}
