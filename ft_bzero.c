/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:00:10 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/28 13:25:32 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t num)
{
	char	*box;

	box = s;
	while (num > 0)
	{
		*box = 0;
		box++;
		num--;
	}
}
/*int	main(void)
{
	char	s[] = "123456789";
	size_t	num = 2;
	size_t	i;

	printf("before: %s\n", s);
	ft_bzero(s, num);
	printf("after: ");
	i = 0;
	while (i < sizeof(s) - 1)
	{
		if (s[i] == '\0')
			printf("0");
		if (s[i] != '\0')
			printf("%c", s[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
