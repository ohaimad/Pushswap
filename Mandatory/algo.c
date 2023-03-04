/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:36:57 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/04 20:33:47 by ohaimad          ###   ########.fr       */
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

void    ft_size(t_data *size)
{
    int s;
    int sta;
    int end;
    int res;
    int plus;
    t_list *tmp;
    
    tmp = size->stack_a;
    s = ft_lstsize(tmp) - 1;
    res = s / 5;
    plus = 0;
    sta = 0;
    end = res - 1;
    while(tmp)
    {
        if(tmp->position >= sta && tmp->position <= end)
        {
            if(tmp->position < ((sta + end) / 2))
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
        }
        else
            ft_ra(size, 1);
    }
}
