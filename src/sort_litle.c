/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_litle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:33:25 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/05 10:41:37 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*sa(t_stack *sck)
{
	t_stack	*aux;

	aux = sck;
	sck = sck->next;
	aux->next = sck->next;
	sck->next = aux;
	ft_putstr_fd("sa\n", 1);
	return (sck);
}

t_stack	*ra(t_stack	*sck)
{
	t_stack	*aux;
	t_stack	*tmp;

	aux = sck;
	tmp = sck->next;
	while (aux->next)
		aux = aux->next;
	aux->next = sck;
	sck->next = NULL;
	ft_putstr_fd("ra\n", 1);
	return (tmp);
}

t_stack	*rra(t_stack *sck)
{
	t_stack	*aux;

	aux = sck;
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next->next = sck;
	sck = aux->next;
	aux->next = NULL;
	ft_putstr_fd("rra\n", 1);
	return (sck);
}

t_stack	*sort_three(t_stack *sck)
{
	t_stack	*aux;
	int		fe;
	int		me;
	int		le;

	fe = *sck->index;
	me = *sck->next->index;
	le = *sck->next->next->index;
	if ((fe > me) && (fe < le))
		aux = sa(sck);
	else if ((fe > me) && (me > le))
	{
		aux = sa(sck);
		aux = rra(aux);
	}
	else if ((fe > me) && (fe > le) && (me < le))
		aux = ra(sck);
	else if ((fe < me) && (fe < le) && (me > le))
	{
		aux = sa(sck);
		aux = ra(aux);
	}
	else
		aux = rra(sck);
	return (aux);
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
