/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:19:39 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/01 21:40:18 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		ft_len (int s, char **str, int space)
{
	int i;
	int len;

	i = -1;
	len = space * -1;
	while (++i < s)
		len += space + ft_strlen(str[i]);
	return (len);
}

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_list	*ft_index(t_data *in)
{
	int i;
	t_list *min;
	t_list *cut;
	t_list *tmp;

	cut = in->stack_a;
	tmp = in->stack_a;
	min = in->stack_a;
	i = 0;
	while(cut)
	{
		in->stack_a = tmp;
		while(in->stack_a)
		{
			if(in->stack_a->position == -1 && min->position == -1
				&& in->stack_a->content < min->content)
					min = in->stack_a;
			in->stack_a = in->stack_a->next;
		}
		in->stack_a = tmp;
		min->position = i++;
		while(in->stack_a)
		{
			if(in->stack_a->position == -1)
			{
				min = in->stack_a;
				break;
			}
			in->stack_a = in->stack_a->next;
		}
		cut = cut->next;
	}
	in->stack_a = tmp;
	return(tmp);
}