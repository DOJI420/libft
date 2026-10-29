/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:09:43 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 10:55:11 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < count)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*int main(void)
{
    char src[] = "maaanmaaan";
    char dst[10];
	char dst2[10];
	size_t count = 5;

	memcpy(NULL, NULL, count);
    ft_memcpy(NULL, NULL, count);
	dst[count] = '\0';
	dst2[count] = '\0';
	printf("memcpy res: %s\n", dst);
    printf("ft_memcpy res: %s", dst2);
    return (0);
}*/