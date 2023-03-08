/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:36:57 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/09 00:24:55 by ohaimad          ###   ########.fr       */
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

int    ft_max_be_max(t_data *size)
{
	t_list *tmp;
	int max;
	int be_max;

	tmp = size->stack_b;
	max = ft_lstsize(size->stack_b);
	be_max = max - 1;
	while(size->stack_b)
	{
		if(size->stack_b->position == max)
			return (max = size->stack_b->position);
		else if(size->stack_b->position == be_max)
			return(be_max = size->stack_b->position);
		size->stack_b = size->stack_b->next;
	}
	size->stack_b = tmp;
	return(0);
}

int	pos_max_be(t_data *size, int in)
{
	int i;

	i = 0;
	while(size->stack_a)
	{
		if(size->stack_a->position == in)
			return(i);
		i++;
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
	else
		return((size - max) + 1);	
}

void	ft_push_back(t_data *data)
{
	t_list *tmp;
	int m;
	int b;
	int max;
	int bef;

	m = ft_max_be_max(data);
	b = ft_max_be_max(data);
	max = pos_max_be(data, m);
	bef = pos_max_be(data, b);
	tmp = data->stack_b;
	while(tmp)
	{
		if (ft_nb_instra(data, m) <= ft_nb_instra(data, b))
			cheking(data, max);
		else
		{
			cheking(data, bef);
			cheking(data, max);
			ft_swap(&data->stack_a, 1);
		}
		tmp = tmp->next;
	}
}

void	cheking(t_data *data, int max)
{
	if (max <= ((ft_lstsize(data->stack_b)) / 2))
	{
		while(ft_nb_instra(data, max))
			ft_rb(data, 1);
		ft_push_a(data);
	}
	else
	{
		while(ft_nb_instra(data, max))
			ft_rrb(data, 1);
		ft_push_a(data);
	}
}