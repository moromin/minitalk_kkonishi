/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:47:13 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/07 17:16:36 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	int					i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (p1[i] == p2[i])
	{
		n--;
		if (p1[i] == '\0' || n == 0)
			return (0);
		i++;
	}
	return (p1[i] - p2[i]);
}
