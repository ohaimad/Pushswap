/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:28:37 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/26 23:17:12 by ohaimad          ###   ########.fr       */
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

	data->res = 0;
	data->signe = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			data->signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		data->res = data->res * 10;
		data->res = data->res + str[i] - '0';
		i++;
	}
	if((data->res * data->signe) > 2147483647 || (data->res * data->signe) < -2147483648)
	{
		ft_lstclear(&data->stack_a);
		ft_exit();
	}
	return (data->res * data->signe);
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
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
		free(*lst);
		*lst = new;
	}
	*lst = 0;
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*str;
	size_t	i;
	size_t	x;

	s = (char *)s1;
	i = 0;
	x = ft_strlen(s) + 1;
	str = malloc(x);
	if (str == 0)
		return (NULL);
	while (s[i] && i <= x)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}