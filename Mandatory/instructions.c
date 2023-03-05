/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:53:58 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/05 22:08:54 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_b(t_data *pu)
{
	int tmp;
	int tmp1;

	if (!pu->stack_a)
		return ;
	tmp = pu->stack_a->content;
	tmp1 = pu->stack_a->position;
	ft_lstadd_front(&pu->stack_b, ft_lstnew(tmp, tmp1));
	pu->stack_a = pu->stack_a->next;
	write(1, "pb\n", 3);
}

void	ft_push_a(t_data *pu)
{
	int tmp;
	int tmp1;

	if (!pu->stack_b)
		return ;
	tmp = pu->stack_b->content;
	tmp1 = pu->stack_b->position;
	ft_lstadd_front(&pu->stack_a, ft_lstnew(tmp, tmp1));
	pu->stack_b = pu->stack_b->next;
	write(1, "pa\n", 3);
}

void	ft_ra(t_data *rev, int id)
{
	t_list *re;
	t_list *tmp;
	
	if(!rev->stack_a->next)
		return;
	re = rev->stack_a;
	tmp = rev->stack_a->next;
	while(re)
	{
		if(re->next == NULL)
		{
			re->next = rev->stack_a;
			rev->stack_a->next = NULL;
			break;
		}
		re = re->next;
	}
	rev->stack_a = tmp;
	if (id == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_data *rev, int id)
{
	t_list *re;
	t_list *tmp;
	
	if(!rev->stack_b->next)
		return;
	re = rev->stack_b;
	tmp = rev->stack_b->next;
	while(re)
	{
		if(re->next == NULL)
		{
			re->next = rev->stack_b;
			rev->stack_b->next = NULL;
			break;
		}
		re = re->next;
	}
	rev->stack_b = tmp;
	if (id == 1)
		write(1, "rb\n", 3);
}

void ft_rr(t_data *rev)
{
	ft_rb(rev, 0);
	ft_ra(rev, 0);
	write(1, "rr\n", 3);	
}
