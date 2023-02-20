/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:09:00 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/20 22:34:17 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int ac, char **av)
{
	t_data data;

	data.stack_a = NULL;
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
			ft_lstadd_back(&data.stack_a, ft_lstnew(ft_atoi(data.list[i], &data), i));
			printf("%s\n", data.list[i++]);
		}
		free(data.list);
	}
	
	else
		ft_exit();
}