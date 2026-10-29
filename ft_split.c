/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:09:40 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/27 11:06:47 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_all(char **res, int j)
{
	while (j > 0)
	{
		j--;
		free(res[j]);
	}
	free(res);
	return (NULL);
}

static char	*ft_alloc_word(const char *str, char d)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	i = 0;
	while (str[len] != '\0' && str[len] != d)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static int	ft_wordcount(char const *str, char c)
{
	int	word_count;
	int	in_word;
	int	i;

	word_count = 0;
	in_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			word_count++;
			in_word = 1;
		}
		i++;
	}
	return (word_count);
}

static char	**ft_fill(char **res, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			res[j] = ft_alloc_word(&s[i], c);
			if (!res[j])
				return (ft_free_all(res, j));
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (ft_fill(res, s, c));
}
/*int main(void)
{
    char **str;
    int i = 0;

    str = ft_split("hello world 42", ' ');
    while (str[i] != NULL)
    {
        printf("%s\n", str[i]);
        i++;
    }
    return (0);
}*/