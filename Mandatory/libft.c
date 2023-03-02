/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:28:37 by ohaimad           #+#    #+#             */
/*   Updated: 2023/03/01 21:35:38 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

char	*ft_strjoin(int size, char **string, char *arg)
{
	int		i;
	char	*res;
	int		len;
	if(!check_av(string))
		return(NULL);
	if (size == 0)
	{
		res = (char*)malloc(1);
		return (res);
	}
	len = ft_len(size, string, ft_strlen(arg));
	i = -1;
	if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	while (++i < size)
	{
		res = ft_strcpy(res, string[i]);
		if (i + 1 < size)
			res = ft_strcpy(res, arg);
	}
	*res = '\0';
	return (res - len);
}