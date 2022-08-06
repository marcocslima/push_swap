/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:41:20 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/06 11:32:15 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	**push_stack(t_stack **scks, t_stack *scks_font, t_stack *scks_dest)
{
	t_stack	*aux;

	aux = NULL;
	if (scks_dest == NULL)
	{
		scks_dest = scks_font;
		scks_font = scks_font->next;
		scks_dest->next = NULL;
	}
	else
	{
		aux = scks_font->next;
		scks_font->next = scks_dest;
		scks_dest = scks_font;
		scks_font = aux;
	}
	scks[0] = scks_font;
	scks[1] = scks_dest;
	ft_putstr_fd("pb\n", 1);
	return (scks);
}

t_stack	*rotate_stack(t_stack	*sck)
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

t_stack	**return_stack(t_stack **scks, t_stack *scks_font, t_stack *scks_dest)
{
	t_stack	*aux;

	aux = NULL;
	if (scks_dest == NULL)
	{
		scks_dest = scks_font;
		scks_font = scks_font->next;
		scks_dest->next = NULL;
	}
	else
	{
		aux = scks_font->next;
		scks_font->next = scks_dest;
		scks_dest = scks_font;
		scks_font = aux;
	}
	scks[1] = scks_font;
	scks[0] = scks_dest;
	ft_putstr_fd("pa\n", 1);
	return (scks);
}

t_stack	**return_to_a(t_stack **stcs)
{
	t_stack	*aux;

	aux = stcs[1];
	while (stcs[1])
	{
		return_stack(stcs, stcs[1], stcs[0]);
		if (stcs[1])
			aux = stcs[1];
		else
		{
			aux = stcs[0]->next;
			break ;
		}
	}
	return (stcs);
}

t_stack	**moviment(t_stack **stcs, int i, int size)
{
	int		j;
	t_stack	*aux;

	j = 0;
	aux = stcs[0];
	while (j < size)
	{
		if (((*aux->index >> i) & 1) == 1)
		{
			stcs[0] = rotate_stack(stcs[0]);
			aux = stcs[0];
		}
		else
			push_stack(stcs, stcs[0], stcs[1]);
		j++;
		aux = stcs[0];
	}
	stcs = return_to_a(stcs);
	return (stcs);
}
