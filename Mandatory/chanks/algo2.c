/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:29:11 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/10 23:50:56 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void    ft_size(t_data *s, int args)
{
	s->size = ft_lstsize(s->stack_a);
	s->rslt = s->size / args;
	s->plus = 0;
	s->end = s->rslt;
	while(s->stack_a)
	{
		if(s->stack_a->position <= s->end)
		{
			if(s->stack_a->position <= (s->end - (s->rslt / 2)))
				ft_push_b(s);
			else
			{
				ft_push_b(s);
				ft_rb(s, 1);
			}
			s->plus++;
		}
		else if(s->plus == s->rslt)
		{
			s->end += s->rslt;
			s->plus = 0;
		}
		else
			ft_ra(s, 1);
	}
}
