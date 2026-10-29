/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:35:56 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 11:02:42 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t count)
{
	unsigned char	*box;

	box = str;
	while (count > 0)
	{
		*box = value;
		box++;
		count--;
	}
	return (str);
}
/*int	main()
{
	char str[] = "abcdefg";
	char str2[] = "abcdefg";
	int value = 'X';
	size_t count = 1;

	ft_memset(str2, value, count);
	memset(str, value, count);
	printf("ft_memset res: %s\n", str2);
	printf("   memset res: %s\n", str);
	return 0;
}*/