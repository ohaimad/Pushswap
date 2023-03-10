/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:25:41 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/10 22:29:18 by ohaimad          ###   ########.fr       */
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

void    ft_indice(t_data *sort, int j)
{
    t_list *tmp;
    int i;
    
    i = 0;
    tmp = sort->stack_a;
    while(tmp)
    {
        if(tmp->position == j)
            break;
        i++;
        tmp = tmp->next;
    }
    while(i >= 1)
    {
        ft_ra(sort, 1);
        i--;
    }
    ft_push_b(sort);
}

void    sort_5(t_data *sort)
{
    ft_indice(sort, 1);
    ft_indice(sort, 2);
    sort_3(sort);
    ft_push_a(sort);
    ft_push_a(sort);
}


void sort_4(t_data *sort)
{
    ft_indice(sort, 1);
    sort_3(sort);
    ft_push_a(sort);
}