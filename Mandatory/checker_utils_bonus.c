/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:56:50 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/13 17:45:07 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_a_bonus(t_data *pu)
{
	int		tmp;
	int		tmp1;
	t_list	*tmp_next;

	if (!ft_lstsize(pu->stack_b))
		return ;
	tmp = pu->stack_b->content;
	tmp1 = pu->stack_b->position;
	ft_lstadd_front(&pu->stack_a, ft_lstnew(tmp, tmp1));
	tmp_next = pu->stack_b->next;
	free(pu->stack_b);
	pu->stack_b = tmp_next;
}

void	ft_push_b_bonus(t_data *pu)
{
	int		tmp;
	int		tmp1;
	t_list	*tmp_next;

	if (!ft_lstsize(pu->stack_a))
		return ;
	tmp = pu->stack_a->content;
	tmp1 = pu->stack_a->position;
	ft_lstadd_front(&pu->stack_b, ft_lstnew(tmp, tmp1));
	tmp_next = pu->stack_a->next;
	free(pu->stack_a);
	pu->stack_a = tmp_next;
}

void	ft_rr_bonus(t_data *rev)
{
	if (!ft_lstsize(rev->stack_b) || !ft_lstsize(rev->stack_a))
		return ;
	ft_rb(rev, 0);
	ft_ra(rev, 0);
}

void	ft_rrr_bonus(t_data *rrev)
{
	if (!ft_lstsize(rrev->stack_a) || !ft_lstsize(rrev->stack_b))
		return ;
	ft_rra(rrev, 0);
	ft_rrb(rrev, 0);
}
