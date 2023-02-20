/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:53:58 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/20 23:05:34 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_space(char **sp)
{
	int i;
	int j;

	i = 0;
	while(sp[i])
	{
		j = 0;
		while (sp[i][j])
		{
			if((sp[i][j] == '-' || sp[i][j] == '+') && (sp[i][j + 1] == '\0'))
				ft_exit();
			j++;
		}
		i++;
	}
}

int	check_signe (char **num)
{
	int i;
	int j;

	i = 0;
	while(num[i])
	{
		j = 0;
		while (num[i][j])
		{
			if((num[i][j] == '+' || num[i][j] == '-')
					&& (num[i][j + 1] == '+' || num[i][j + 1] == '-'))
				ft_exit();
			else if(!((num[i][j] >= '0' && num[i][j] <= '9')
					|| num[i][j] == '+' || num[i][j] == '-'))
				ft_exit();
			j++;
		}
		i++;
	}
	check_space(num);
	return(0);
}

void	check_error(t_data *data)
{
	if(data->stack_a)
		ft_lstclear(&data->stack_a);
	free(data->list);
}