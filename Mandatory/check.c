/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:52:05 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/10 23:24:14 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	check_order(t_list *ord)
{
	t_list *ord1;

	while (ord)
	{
		ord1 = ord->next;
		while (ord1)
		{
			if (ord->content == ord1->content)
				ft_exit();
			ord1 = ord1->next;
		}
		ord = ord->next;
	}
}

int	check_av(char **string)
{
	int i;
	int j;

	i = 0;
	while(string[i])
	{
		j = 0;
		while (string[i][j])
		{
			if((string[i][j] >= '0' && string[i][j] <= '9'))
				break;
		j++;
		}
		if(j == ft_strlen(string[i]))
			return(0);
	i++;
	}
	return(1);
}

void	gd_order(t_data *data)
{
	t_list *tmp;

	tmp = data->stack_a;
	while(tmp->next)
	{
		if (tmp->position > tmp->next->position)
			return;
		tmp = tmp->next;
	}
	ft_exit();
}