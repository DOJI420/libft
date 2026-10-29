/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:35:12 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 10:56:03 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (d < s)
	{
		while (i < num)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
	while (num > 0)
	{
		num--;
		d[num] = s[num];
	}
	return (dest);
}
/*int	main()
{
	char src[] = "abcdefg";
	char dest[10] = "123456g";
	char dest2[10] = "123456g";
	size_t	num = 3;

	ft_memmove(dest2, src, num);
	memmove(dest, src, num);
	printf("   memmove res: %s\n", dest);
	printf("ft_memmove res: %s", dest2);
	return 0;
}*/