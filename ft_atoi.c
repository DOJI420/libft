/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:27:07 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/11/05 08:39:23 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(size_t res, int digit, int flag)
{
	size_t	limit;

	limit = (size_t)-1 / 2;
	if (flag == -1)
		limit++;
	return (res > limit / 10
		|| (res == limit / 10 && (size_t)digit > limit % 10));
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	res;
	int		flag;

	i = 0;
	res = 0;
	flag = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flag = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (ft_overflow(res, nptr[i] - '0', flag))
			return (-(flag + 1) / 2);
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return ((int)(res * flag));
}
