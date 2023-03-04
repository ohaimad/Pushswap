/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:09:00 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/04 22:33:15 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void f()
// {
// 	system("leaks push_swap");
// }

int main(int ac, char **av)
{
	
	// atexit(f);
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
		ft_size(&data);
		while (data.stack_a)
		{
			printf("a == %d / ", data.stack_a->content);
			printf("ia == %d\n", data.stack_a->position);
			data.stack_a = data.stack_a->next;
		}
		while (data.stack_b)
		{
			printf("b == %d / ", data.stack_b->content);
			printf("ib == %d\n", data.stack_b->position);
			data.stack_b = data.stack_b->next;
		}
		freeall(data.list, data.len);
		ft_lstclear(&data.stack_a);
	}
	else
		ft_exit();
}
