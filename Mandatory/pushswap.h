/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:15:13 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/23 23:30:14 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>

typedef struct s_list
{
	int	content;
	struct s_list	*next;
	int		position;
}	t_list;

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

typedef struct s_data
{
	int len;
	t_list	*stack_a;
	char **list;
	long long		signe;
	
	long long		res;
} t_data;




int		ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strcpy(char *dst, char *src);
int		ft_len (int s, char **str, int space);
int	check_av(char **string);
char	*ft_strjoin(int size, char **string, char *arg);
char	**ft_split(char const *s, char c);
long long	ft_atoi(char *str, t_data *data);
void	ft_exit(void);
int		check_signe (char **num);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content, int position);
void	ft_lstclear(t_list **lst);
void	freeall(char **s, int len);
void	check_order(t_list *ord);
void	ft_swap(t_list **swp, int st);
t_list	*ft_index(t_data *in);

