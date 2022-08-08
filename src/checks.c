/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:32:58 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/08 02:28:21 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_isnumeric(char *argv[], int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		if (argv[i][0] == '-')
			j = 1;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j++]))
				msg(ERR_NONUM);
		}
		i++;
	}
}

void	check_duplicates(int *vet, int size)
{
	int	i;

	i = 0;
	if (size == 1 || (size == 2 && vet[0] < 0 && vet[1] == 0))
		return ;
	while (i < size - 1)
	{
		if (vet[i] == vet[i + 1])
		{
			free(vet);
			msg(ERR_DUPLIC);
		}
		i++;
	}
}

int	check_is_sorted(int *vet, int size)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (size == 1)
		return (1);
	if (size == 2 && vet[0] < 0 && vet[1] == 0)
		return (1);
	while (i < size - 1)
	{
		if (vet[i + 1] < vet[i])
			check++;
		i++;
	}
	if (check == 0)
		return (1);
	return (0);
}
