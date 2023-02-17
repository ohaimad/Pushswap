/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:09:00 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/17 20:54:17 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		char *str;
		char **list;
		int i;

		i = 0;
		str = ft_strjoin(ac - 1, av + 1, " ");
		if(!str)
			ft_exit();
		list = ft_split(str, ' ');
		check_signe(list);
		while(list[i])
		{
			printf("%s\n", list[i++]);
		}
	}
	else
		ft_exit();
}