/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:36:57 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/10 20:33:19 by ohaimad          ###   ########.fr       */
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

int    ft_max_be_max(t_data *size, int in)
{
	t_list *tmp;
	int max;
	int be_max;

	tmp = size->stack_b;
	max = ft_lstsize(size->stack_b);
	be_max = max - 1;
	while(tmp)
	{
		if(tmp->position == max && in == 0)
			return (max = tmp->position);
		else if(tmp->position == be_max && in == 1)
			return(be_max = tmp->position);
		tmp = tmp->next;
	}
	return(1);
}

int	pos_max_be(t_data *size, int in)
{
	int i;
	t_list	*tmp;

	tmp = size->stack_b;
	i = 1;
	while(tmp)
	{
		if(tmp->position == in)
			return(i);
		i++;
		tmp = tmp->next;
	}
	return(0);
}

int	ft_nb_instra(t_data *data, int in)
{
	int max;
	int size;

	max = pos_max_be(data, in);
	size = ft_lstsize(data->stack_b);
	if (max <= size / 2)
		return(max - 1);
	return((size - max) + 1);
}

void	cheking(t_data *data, int max)
{
	int i;
	if (pos_max_be(data, max) <= ((ft_lstsize(data->stack_b)) / 2))
		i = 0;
	else
		i = 1;
	while (1)
	{

		if(max == data->stack_b->position)
		{
			ft_push_a(data);
			return ;
		}
		if (i == 0)
			ft_rb(data, 1);
		else
			ft_rrb(data, 1);
	}
}

void	ft_push_back(t_data *data)
{
	int m;
	int b;
	int max;
	int bef;

	// if (ft_lstsize(data->stack_b) == 2)
	// {
	// 	if (data->stack_a->position > data->stack_a->next->position)
	// 	{
	// 		ft_push_a(data);
	// 		ft_push_a(data);
	// 	}
	// 	else
	// 	{
	// 		ft_swap(&data->stack_b, 1);
	// 		ft_push_a(data);
	// 		ft_push_a(data);
	// 	}
	// 	return;
	// }
	while (ft_lstsize(data->stack_b))
	{
		m = ft_max_be_max(data, 0);
		b = ft_max_be_max(data, 1);
		max = ft_nb_instra(data, m);
		bef = ft_nb_instra(data, b);
		if(bef < max)
		{
			cheking(data, b);
			cheking(data, m);
			ft_swap(&data->stack_a, 0);
		}
		else
			cheking(data, m);
	}
	// if (data->stack_b)
	// 	ft_push_back(data);
	// else
		// return ;
}
