/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:07:49 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 11:08:58 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		find;
	size_t				i;

	str = (const unsigned char *)s;
	find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == find)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
/*int	main()
{
	char	s[] = "abcdefg";
	int		i = 'g';
	size_t	n = 10;
	char	*res;

	res = ft_memchr(s, i, n);
	if (res)
		printf("%s\n", res);
	if (!res)
		printf("not found.\n");
	return 0;
}*/