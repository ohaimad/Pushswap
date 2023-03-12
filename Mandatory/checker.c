/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:02:57 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/12 22:59:58 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_ordered(t_data *data)
{
	t_list	*tmp;

	tmp = data->stack_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return(1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int    do_instra(t_data *data, char *inst)
{
    if (!ft_strcmp(inst, "sa\n"))
        ft_swap(&data->stack_a, 10);
    else if (!ft_strcmp(inst, "sb\n"))
        ft_swap(&data->stack_b, 10);
    else if (!ft_strcmp(inst, "ss\n"))
        ft_ss(data);
    else if (!ft_strcmp(inst, "ra\n"))
        ft_ra(data, 0);
    else if (!ft_strcmp(inst, "rb\n"))
        ft_rb(data, 0);
    else if (!ft_strcmp(inst, "rr\n"))
        ft_rr(data, 0);
    else if (!ft_strcmp(inst, "rra\n"))
        ft_rra(data, 0);
    else if (!ft_strcmp(inst, "rrb\n"))
        ft_rrb(data, 0);
    else if (!ft_strcmp(inst, "rrr\n"))
        ft_rrr(data, 0);
    else if (!ft_strcmp(inst, "pa\n"))
        ft_push_a_(data);
    else if (!ft_strcmp(inst, "pb\n"))
        ft_push_b_(data);
    else
        return (write(1, "Error\n", 6), exit(1), 1);
    return (0);
}

int main(int ac, char **av)
{
    t_data	data;
	char	*strn;
    char    *line;

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
	}
	else
		return (0);
    while (1)
    {
        line = get_next_line(1);
        if (line == NULL)
            break ;
        do_instra(&data, line);
    }
    if (!is_ordered(&data))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    return (0);
}