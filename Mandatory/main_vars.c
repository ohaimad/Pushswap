/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:23:12 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/12 18:26:55 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_vars_main(t_data data)
{
	if (ft_lstsize(data.stack_a) == 1)
		return (ft_lstclear(&data.stack_a), 0);
	gd_order(&data);
	if (ft_lstsize(data.stack_a) == 3)
		sort_3(&data);
	else if (ft_lstsize(data.stack_a) == 4)
		sort_4(&data);
	else if (ft_lstsize(data.stack_a) == 5)
		sort_5(&data);
	else if (ft_lstsize(data.stack_a) > 5 && ft_lstsize(data.stack_a) <= 100)
	{
		ft_size(&data, 5);
		ft_push_back(&data);
	}
	else if (ft_lstsize(data.stack_a) > 100)
	{
		ft_size(&data, 9);
		ft_push_back(&data);
	}
	else
		ft_swap(&data.stack_a, 0);
	return (ft_lstclear(&data.stack_a), 1);
}

void	print_stack(t_data data)
{
	while (data.stack_a)
	{
		printf("a == %d / ", data.stack_a->content);
		printf("ia == %d\n", data.stack_a->position);
		data.stack_a = data.stack_a->next;
	}
	while (data.stack_b)
	{
		printf("b == %d / ", data.stack_b->content);
		printf("ib == %d\n", data.stack_b->position);
		data.stack_b = data.stack_b->next;
	}
}

void	add_to_a(t_data *data)
{
	while (data->list[data->k])
	{
		ft_lstadd_back(&data->stack_a, ft_lstnew(ft_atoi(data->list[data->k],
					data), -1));
		free(data->list[data->k++]);
	}
	free(data->list);
}
