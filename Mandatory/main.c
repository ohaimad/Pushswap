/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:09:00 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/11 01:16:51 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int ac, char **av)
{
	t_data data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	data.len = ac - 1;
	if (ac >= 2)
	{
		char *str;
		int i;

		i = 0;
		str = ft_strjoin(ac - 1, av + 1, " ");
		if(!str)
			ft_exit();
		data.list = ft_split(str, ' ');
		free(str);
		check_signe(data.list);
		while(data.list[i])
		{
			ft_lstadd_back(&data.stack_a, ft_lstnew(ft_atoi(data.list[i], &data), -1));
			i++;
		}
		check_order(data.stack_a);
		data.stack_a = ft_index(&data);
		if(ft_lstsize(data.stack_a) == 1)
			return(0);
		gd_order(&data);
		ft_vars_main(data);
		freeall(data.list, data.len);
		ft_lstclear(&data.stack_a);
	}
	else
		ft_exit();
}
