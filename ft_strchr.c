/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:46:08 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 11:54:58 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	t;
	int				i;

	i = 0;
	t = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == t)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (t == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}