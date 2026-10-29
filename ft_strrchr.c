/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:06:13 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/19 15:07:48 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	t;
	int				i;
	char			*last_match;

	i = 0;
	t = (unsigned char)c;
	last_match = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == t)
		{
			last_match = (char *)(s + i);
		}
		i++;
	}
	if (t == '\0')
	{
		return ((char *)(s + i));
	}
	return (last_match);
}
