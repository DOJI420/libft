/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:59:02 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/19 15:02:39 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include<bsd/string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (dest_len < size && dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	j = dest_len;
	while (src[i] != '\0' && j < (size -1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}
/*int	main(void)
{
	char	a[10] = "hello";
	char	b[10] = "hello";
	size_t	r1;
	size_t	r2;

	r1 = ft_strlcat(a, "world", 10);
	r2 = strlcat(b, "world", 10);
	printf("%zu\n", r1); 
	printf("%zu\n", r2);    
	return (0);
}*/