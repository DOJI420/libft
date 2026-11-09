/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <yibn-yah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:46:08 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 11:54:58 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;
	int				i;

	i = 0;
	find = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == find)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (find == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
