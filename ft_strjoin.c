/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:45:15 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 09:58:50 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s_joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s_joined)
		return (NULL);
	while (s1[i] != '\0')
	{
		s_joined[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s_joined[i + j] = s2[j];
		j++;
	}
	s_joined[i + j] = '\0';
	return (s_joined);
}