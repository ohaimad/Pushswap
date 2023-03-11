/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:24:49 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/11 16:48:46 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!new)
		return ;
	head = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_list	*ft_lstnew(int content, int position)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->position = position;
	node->next = NULL;
	return (node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*new;

	if (!lst)
		return ;
	while (*lst)
	{
		new = (*lst)->next;
		free(*lst);
		*lst = new;
	}
	*lst = NULL;
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}