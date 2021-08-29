/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:54:18 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/09 17:33:50 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*block;
	size_t	i;

	block = malloc(size * count);
	if (block == NULL)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		block[i] = 0;
		i++;
	}
	return ((void *)block);
}
