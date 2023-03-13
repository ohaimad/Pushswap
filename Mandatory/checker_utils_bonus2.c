/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:13:16 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/13 17:42:26 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	ft_rra_bonus(t_data *rrev, int id)
{
	t_list	*re;

	if (!ft_lstsize(rrev->stack_a))
		return ;
	re = rrev->stack_a;
	while (re)
	{
		if (re->next->next == NULL)
		{
			ft_lstadd_front(&rrev->stack_a,
				ft_lstnew(re->next->content, re->next->position));
			free(re->next);
			re->next = NULL;
			break ;
		}
		re = re->next;
	}
	if (id == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb_bonus(t_data *rrev, int id)
{
	t_list	*re;

	if (!ft_lstsize(rrev->stack_b))
		return ;
	re = rrev->stack_b;
	while (re)
	{
		if (re->next->next == NULL)
		{
			ft_lstadd_front(&rrev->stack_b,
				ft_lstnew(re->next->content, re->next->position));
			free(re->next);
			re->next = NULL;
			break ;
		}
		re = re->next;
	}
	if (id == 1)
		write(1, "rrb\n", 4);
}

void	ft_swap_bonus(t_list **swp, int st)
{
	int	swap;
	int	swap_in;

	if (!ft_lstsize(*swp))
		return ;
	if ((*swp)->next == NULL)
		return ;
	swap = (*swp)->content;
	(*swp)->content = (*swp)->next->content;
	(*swp)->next->content = swap;
	swap_in = (*swp)->position;
	(*swp)->position = (*swp)->next->position;
	(*swp)->next->position = swap_in;
	if (st == 0)
		write(1, "sa\n", 3);
	else if (st == 1)
		write(1, "sb\n", 3);
}

void	ft_ss_bonus(t_data *swp)
{
    if (!ft_lstsize(swp->stack_b) || !ft_lstsize(swp->stack_a))
		return ;
	ft_swap(&swp->stack_a, 2);
	ft_swap(&swp->stack_b, 2);
	write(1, "ss\n", 3);
}
