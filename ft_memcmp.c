/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:00:26 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 11:55:47 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return ((unsigned char)p1[i] - (unsigned char)p2[i]);
		}
		i++;
	}
	return (0);
}
/*int	main()
{
	char	s1[] = "abcdbf";
	char	s2[] = "abcdaf";
	size_t	n = 5;
	int	res = ft_memcmp(s1, s2, n);

	printf("%d\n", res );
	return 0;
}*/