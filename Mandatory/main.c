/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:09:00 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/11 21:20:22 by ohaimad          ###   ########.fr       */
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
		data.k = 0;
		data.list = ft_split(ft_strjoin(ac - 1, av + 1, " "), ' ');
		if(!data.list)
			ft_exit();
		check_signe(data.list);
		while(data.list[data.k])
		{
			ft_lstadd_back(&data.stack_a, ft_lstnew(ft_atoi(data.list[data.k], &data), -1));
			free(data.list[data.k++]);
		}
		free(data.list);
		check_order(data.stack_a);
		data.stack_a = ft_index(&data);
		gd_order(&data);
		ft_vars_main(data);
	}
	else 
		ft_exit();	
}
