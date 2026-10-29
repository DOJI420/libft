/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:27:07 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/19 15:18:13 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	flag;
	int	res;

	i = 0;
	flag = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * flag);
}
/*int main(void)
{
    printf("%d\n", ft_atoi("67"));
    printf("%d\n", ft_atoi("-67"));
    printf("%d\n", ft_atoi("--67"));
    printf("%d\n", ft_atoi(" \t  -42069"));
    printf("%d\n", ft_atoi("69 00"));
    return (0);
}*/