/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:45:17 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 10:13:28 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*int main(void)
{
    t_list a;
    t_list b;
    t_list c;

    a.content = "wahaaaaad";
    a.next = &b;

    b.content = "joooooooj";
    b.next = &c;

    c.content = "tlataaaaa";
    c.next = NULL;

    printf("%s\n", (char *)ft_lstlast(&a)->content);
    return (0);
}*/
