/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:15:13 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/17 20:47:20 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>

struct s_split
{
	int			pi;
	char		**p;
	char const	*s;
	char		c;
	int			w;
	int			skip;
	int			line;
};

// static	void	freeall(char **s, int len);
int		ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strcpy(char *dst, char *src);
int		ft_len (int s, char **str, int space);
int	check_av(char **string);
char	*ft_strjoin(int size, char **string, char *arg);
// static int	nbrofwords(char const *s, char c);
// static	char	**added(struct s_split *z);
char	**ft_split(char const *s, char c);
void	ft_exit(void);
void	check_signe (char **num);
