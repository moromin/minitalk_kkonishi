/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:50:17 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/18 16:21:40 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sign_check(char s)
{
	if (s == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = sign_check(str[i++]);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if ((res * 10 + (str[i] - '0')) / 10 != res)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
