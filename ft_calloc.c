/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:16:49 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/20 09:59:28 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	size_t	i;
	char	*mptr;

	i = 0;
	total_size = nmemb * size;
	if (nmemb != 0 && (total_size / nmemb != size))
		return (NULL);
	mptr = malloc(total_size);
	if (!mptr)
		return (NULL);
	while (i < total_size)
	{
		mptr[i] = 0;
		i++;
	}
	return ((void *)mptr);
}
/*int main()
{
	char *str;
	size_t len = 0;

	str = ft_calloc(5, sizeof(char));
	while (len < 5 && str[len] == '\0')
	{
		printf("found one here: %zu\n", len);
		len++;
	}
	free(str);
	return 0;
}*/