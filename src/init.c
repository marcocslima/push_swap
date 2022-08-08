/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:37:14 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/08 02:30:06 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*vet_cpy(int *vet, int size)
{
	int	i;
	int	*vet_cpy;

	i = 0;
	vet_cpy = malloc(sizeof(int) * size);
	while (i < size)
	{
		vet_cpy[i] = vet[i];
		i++;
	}
	return (vet_cpy);
}

int	*sort_entry(int *vet, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	*cpy;

	cpy = vet_cpy(vet, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (cpy[j] > cpy[i])
			{
				tmp = cpy[i];
				cpy[i] = cpy[j];
				cpy[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (cpy);
}

int	*init_entry(char *argv[], int size)
{
	int		i;
	int		*vet;
	long	tmp;

	i = 0;
	vet = malloc(sizeof(int) * size);
	if (!vet)
		exit(EXIT_FAILURE);
	while (i < size)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			free(vet);
			msg(ERR_SIZEINT);
		}
		vet[i] = (int)tmp;
		i++;
	}
	return (vet);
}

int	*vet_index(int *vet_entry, int *vet_sort, int size)
{
	int	i;
	int	counter;
	int	*vet_index;

	i = 0;
	vet_index = malloc(sizeof(int) * size);
	if (!vet_index)
		exit(EXIT_FAILURE);
	while (i < size)
	{
		counter = 0;
		while (vet_entry[i] != vet_sort[counter])
			counter++;
		vet_index[i] = counter;
		i++;
	}
	return (vet_index);
}

t_stack	*init_stack(int *vet_entry, int *vet_sort, int size)
{
	t_stack	*stack;
	int		i;

	i = 1;
	if (!vet_entry || !vet_sort)
		msg(ERR_NOBASE);
	stack = ft_stcknewone(&vet_entry[0], &vet_sort[0]);
	while (i < size)
	{
		ft_stckadd_back(&stack, ft_stcknewone(&vet_entry[i], &vet_sort[i]));
		i++;
	}
	return (stack);
}
