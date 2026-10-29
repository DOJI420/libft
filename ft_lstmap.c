/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:59:39 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/10/28 13:41:15 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	if (!f || !del || !lst)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*void	*double_it(void *c)
{
	int	*n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = *(int *)c * 2;
	return (n);
}
int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*tmp;
	int		a[3] = {1, 2, 3};
	int		i;

	lst = NULL;
	i = 0;
	while (i < 3)
		ft_lstadd_back(&lst, ft_lstnew(&a[i++]));
	new = ft_lstmap(lst, double_it, free);
	tmp = new;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->content);   // 2 4 6
		tmp = tmp->next;
	}
	ft_lstclear(&new, free);
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}*/