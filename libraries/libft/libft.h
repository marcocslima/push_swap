/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:28:41 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/08 02:56:04 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 42

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	int				*base;
	int				*index;
	struct s_stack	*next;
}					t_stack;

int		ft_recursive_power(int nb, int power);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
long	ft_atoi(const char *s);
void	ft_putstr_fd(char *s, int fd);
t_stack	*ft_stcknewone(int *base, int *index);
t_stack	*ft_stcklast(t_stack *lst);
void	ft_stckadd_back(t_stack **lst, t_stack *new);
void	ft_sckadd_front(t_stack **sck, t_stack *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
#endif
