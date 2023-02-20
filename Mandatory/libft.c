/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:28:37 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/20 23:05:25 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	x = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (x);
}

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		*dst = src[i];
		i++;
		dst++;
	}
	return (dst);
}

long long	ft_atoi(char *str, t_data *data)
{
	int		i;
	long long		signe;
	long long		res;

	res = 0;
	signe = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	if((res * signe) > 2147483647 || (res * signe) < -2147483648)
	{
		check_error(data);
		ft_exit();
	}
	return (res * signe);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!new)
		return ;
	head = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new;
}

t_list	*ft_lstnew(int content, int position)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->position = position;
	node->next = NULL;
	return (node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*new;

	if (!lst)
		return ;
	new = *lst;
	while (new)
	{
		new = new->next;
		free(lst);
		*lst = new;
	}
	*lst = 0;
}