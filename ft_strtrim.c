/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:20:48 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 13:55:28 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_copy_trimed(char const *s1, size_t start, size_t end)
{
	char	*s1_trimed;
	int		i;

	i = 0;
	s1_trimed = malloc(end - start + 1);
	if (!s1_trimed)
		return (NULL);
	while (start < end)
	{
		s1_trimed[i] = s1[start];
		start++;
		i++;
	}
	s1_trimed[i] = '\0';
	return (s1_trimed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && ft_isinset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isinset(s1[end - 1], set))
		end--;
	return (ft_copy_trimed(s1, start, end));
}
