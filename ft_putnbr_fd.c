/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:02:58 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/21 11:52:22 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_unsigned(unsigned int nb, int fd)
{
	char	c;

	if (nb >= 10)
		ft_put_unsigned(nb / 10, fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = (unsigned int)(-(n + 1)) + 1;
	}
	if (n >= 0)
		nb = (unsigned int)n;
	ft_put_unsigned(nb, fd);
}
/*int	main()
{
	int	i = -2147483648;
	int	fd = 0;

	ft_putnbr_fd(i, fd);
	return 0;
}*/