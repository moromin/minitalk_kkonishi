/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:06:06 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/07 21:21:24 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[30];
	int		count;

	count = 0;
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	while (n)
	{
		if (n >= 0)
			num[count] = '0' + (n % 10);
		else
			num[count] = '0' - (n % 10);
		n /= 10;
		count++;
	}
	while (count > 0)
		write(fd, &num[count-- - 1], 1);
}
