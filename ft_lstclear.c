/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:44:16 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/24 10:19:49 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_next;

	if (!lst || !del)
		return ;
	temp_next = *lst;
	while (*lst)
	{
		temp_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp_next;
	}
}
