/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:42:20 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/12 18:28:45 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_len(int s, char **str, int space)
{
	int	i;
	int	len;

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

void	ft_vars(t_data *in)
{
	in->cut = in->stack_a;
	in->tmp = in->stack_a;
	in->min = in->stack_a;
	in->i = 1;
}

int	check_index(t_data *in)
{
	return (in->stack_a->position == -1 && in->min->position == -1
		&& in->stack_a->content < in->min->content);
}

t_list	*ft_index(t_data *in)
{
	ft_vars(in);
	while (in->cut)
	{
		in->stack_a = in->tmp;
		while (in->stack_a)
		{
			if (check_index(in))
				in->min = in->stack_a;
			in->stack_a = in->stack_a->next;
		}
		in->stack_a = in->tmp;
		in->min->position = in->i++;
		while (in->stack_a)
		{
			if (in->stack_a->position == -1)
			{
				in->min = in->stack_a;
				break ;
			}
			in->stack_a = in->stack_a->next;
		}
		in->cut = in->cut->next;
	}
	in->stack_a = in->tmp;
	return (in->tmp);
}
