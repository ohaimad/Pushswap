/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:25:41 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/02 23:06:59 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    sort_3(t_data *sort)
{
    t_list *srt;

    srt = sort->stack_a;
    if(srt->position > srt->next->position 
        && srt->position < srt->next->next->position)
        ft_swap(&sort->stack_a, 0);
    else if(srt->position > srt->next->position 
        && srt->next->position < srt->next->next->position)
        ft_ra(sort, 1);
    else if(srt->position > srt->next->position 
        && srt->position > srt->next->next->position)
    {
        ft_swap(&sort->stack_a, 0);
        ft_rra(sort, 1);
    }
    else if (srt->position < srt->next->position
        && srt->position > srt->next->next->position)
        ft_rra(sort, 1);
    else if (srt->position < srt->next->position
        && srt->next->position > srt->next->next->position)
    {
        ft_swap(&sort->stack_a, 0);
        ft_ra(sort, 1);
    }
}