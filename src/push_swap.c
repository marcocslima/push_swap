/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:44:49 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/08 02:35:32 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_stack **stcs)
{
	t_stack	*aux;

	while (stcs[0])
	{
		aux = stcs[0];
		stcs[0] = stcs[0]->next;
		free(aux);
	}
	free(stcs);
}

static void	big_base_sort(t_stack **stacks, int size, int n)
{
	t_stack	*aux;
	int		i;

	i = 0;
	while (i < n)
	{
		stacks = moviment(stacks, i, size);
		while (stacks[1])
		{
			return_stack(stacks, stacks[1], stacks[0]);
			if (stacks[1])
				aux = stacks[1];
			else
			{
				aux = stacks[0]->next;
				break ;
			}
		}
		i++;
	}
}

static void	sort(int *vet_entry, int *vet_sort, int size)
{
	t_stack	*stack_a;
	t_stack	**stacks;
	int		n;

	n = 0;
	stacks = malloc(sizeof(size_t) * 2);
	while (ft_recursive_power(2, n) <= size - 1)
		n++;
	stack_a = init_stack(vet_entry, vet_sort, size - 1);
	stacks[0] = stack_a;
	if (size - 1 == 2)
		stacks[0] = sort_two(stacks[0]);
	else if (size - 1 == 3)
		stacks[0] = sort_three(stacks[0]);
	else if (size - 1 == 5)
		sort_five(stacks);
	else
		big_base_sort(stacks, size - 1, n);
	free_stacks(stacks);
	free(vet_sort);
}

int	main(int argc, char *argv[])
{
	int	*vet_entry;
	int	*vet_sort;
	int	*ret_vet;

	if (argc < 2)
		exit(0);
	check_isnumeric(argv, argc);
	vet_entry = init_entry(argv, argc - 1);
	vet_sort = sort_entry(vet_entry, argc - 1);
	check_duplicates(vet_sort, argc - 1);
	if (check_is_sorted(vet_entry, argc - 1))
	{
		free(vet_entry);
		free(vet_sort);
		exit (EXIT_FAILURE);
	}
	ret_vet = vet_index(vet_entry, vet_sort, argc - 1);
	sort(vet_entry, ret_vet, argc);
	free(vet_entry);
	free(vet_sort);
	return (0);
}
