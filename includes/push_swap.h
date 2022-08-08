/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:48:42 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/08 10:46:58 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include "../libraries/libft/libft.h"

# define ERR_NONUM		"some arguments aren’t integers\n"
# define ERR_DUPLIC		"there are duplicates\n"
# define ERR_INTMAX		"some arguments are bigger than an integer\n"
# define ERR_INTMIN		"some arguments are smaller than an integer\n"
# define ERR_NUMARG		"number of arguments\n"
# define ERR_NOBASE		"base not loaded\n"

int		msg(char *err);
void	check_isnumeric(char *argv[], int size);
void	check_duplicates(int *vet, int size);
int		check_is_sorted(int *vet, int size);
int		*vet_cpy(int *vet, int size);
int		*sort_entry(int *vet, int size);
int		*init_entry(char *argv[], int size);
int		*vet_index(int *vet_entry, int *vet_sort, int size);
t_stack	*init_stack(int *vet_entry, int *vet_sort, int size);
t_stack	**push_stack(t_stack **scks, t_stack *scks_font, t_stack *scks_dest);
t_stack	*rotate_stack(t_stack	*sck);
t_stack	**return_stack(t_stack **scks, t_stack *scks_font, t_stack *scks_dest);
t_stack	**return_to_a(t_stack **stcs);
t_stack	**moviment(t_stack **stcs, int i, int size);
t_stack	*sa(t_stack *sck);
t_stack	*ra(t_stack	*sck);
t_stack	*rra(t_stack *sck);
t_stack	*sort_two(t_stack *sck);
t_stack	*sort_three(t_stack *sck);
void	sort_five(t_stack **scks);
void	free_stacks(t_stack **stcs);

#endif