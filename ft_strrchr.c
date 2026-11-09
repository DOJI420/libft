/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <yibn-yah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:06:13 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/19 15:07:48 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	find;
	int				i;
	char			*last_match;

	i = 0;
	find = (unsigned char)c;
	last_match = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == find)
		{
			last_match = (char *)(s + i);
		}
		i++;
	}
	if (find == '\0')
	{
		return ((char *)(s + i));
	}
	return (last_match);
}
