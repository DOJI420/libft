/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:32:31 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 12:00:33 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				len;
	int				negative;

	negative = (n < 0);
	if (negative)
		nb = (unsigned int)(-(n + 1)) + 1;
	if (!negative)
		nb = (unsigned int)n;
	len = ft_numlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > negative)
	{
		str[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
/*int	main()
{
	int	i = 42;
	
	printf("result: %s\n",ft_itoa(i));
}*/