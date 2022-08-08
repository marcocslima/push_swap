/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_litle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:33:25 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/07 23:12:21 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*sort_two(t_stack *sck)
{
	sck = sa(sck);
	return (sck);
}

t_stack	*sort_three(t_stack *sck)
{
	int		fe;
	int		me;
	int		le;

	fe = *sck->index;
	me = *sck->next->index;
	le = *sck->next->next->index;
	if ((fe > me) && (fe < le))
		sck = sa(sck);
	else if ((fe > me) && (me > le))
	{
		sck = sa(sck);
		sck = rra(sck);
	}
	else if ((fe > me) && (fe > le) && (me < le))
		sck = ra(sck);
	else if ((fe < me) && (fe < le) && (me > le))
	{
		sck = sa(sck);
		sck = ra(sck);
	}
	else
		sck = rra(sck);
	return (sck);
}

void	sort_five(t_stack **scks)
{
	int		i;
	t_stack	**aux;

	i = 0;
	while (i < 5)
	{
		aux = scks;
		if (*aux[0]->index == 0 || *aux[0]->index == 1)
			scks = push_stack(scks, aux[0], scks[1]);
		else
			aux[0] = ra(scks[0]);
		i++;
	}
	if (!((*aux[0]->index < *aux[0]->next->index)
			&& (*aux[0]->next->index < *aux[0]->next->next->index)))
		aux[0] = sort_three(aux[0]);
	scks = return_stack(scks, scks[1], aux[0]);
	scks = return_stack(scks, scks[1], scks[0]);
	if (*scks[0]->index > *scks[0]->next->index)
		scks[0] = sa(scks[0]);
}
