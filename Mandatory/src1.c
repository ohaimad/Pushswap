/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:52:05 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/17 00:54:33 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		ft_len (int s, char **str, int space)
{
	int i;
	int len;

	i = -1;
	len = space * -1;
	while (++i < s)
		len += space + ft_strlen(str[i]);
	return (len);
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
