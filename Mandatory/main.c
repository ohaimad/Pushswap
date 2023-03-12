/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:09:00 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/12 18:43:27 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_data	data;
	char	*strn;

	data.stack_a = NULL;
	data.stack_b = NULL;
	strn = NULL;
	data.len = ac - 1;
	if (ac >= 2)
	{
		data.k = 0;
		strn = ft_strjoin(ac - 1, av + 1, " ");
		data.list = ft_split(strn, ' ');
		free(strn);
		if (!data.list)
			ft_exit();
		check_signe(data.list);
		add_to_a(&data);
		check_order(data.stack_a);
		data.stack_a = ft_index(&data);
		gd_order(&data);
		ft_vars_main(data);
	}
	else
		return (0);
}
