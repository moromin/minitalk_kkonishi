/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:57:25 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/10 17:06:18 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match_check(char str, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == str)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (len > 0 && match_check(s1[len - 1], set))
		len--;
	i = 0;
	while (len > 0 && match_check(s1[i++], set))
		len--;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (match_check(s1[i], set))
		i++;
	while (j < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
