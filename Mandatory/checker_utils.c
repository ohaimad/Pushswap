/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:56:50 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/12 22:58:33 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_a_(t_data *pu)
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

void	ft_push_b_(t_data *pu)
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