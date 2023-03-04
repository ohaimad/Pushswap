/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:36:57 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/04 23:57:19 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void    ft_size(t_data *size, int args)
{
    int s;
    int sta;
    int end;
    int res;
    int plus;

    s = ft_lstsize(size->stack_a);
    res = s / args;
    plus = 0;
    sta = 0;
    end = res - 1;
    while(size->stack_a)
    {
        if(size->stack_a->position >= sta && size->stack_a->position <= end)
        {
            if(size->stack_a->position <= ((sta + end) / 2))
                ft_push_b(size);
            else
            {
                ft_push_b(size);
                ft_rb(size, 1);
            }
            plus++;
        }
        else if(plus == res)
        {
            sta += res;
            end += res;
            plus = 0;
        }
        else
            ft_ra(size, 1);
    }
}
