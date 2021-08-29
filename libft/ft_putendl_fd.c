/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:05:57 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/07 18:29:46 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (*s)
	{
		write(fd, s, 1);
		ft_putendl_fd(++s, fd);
	}
	else
	{
		write(fd, "\n", 1);
		return ;
	}
}
