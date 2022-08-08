/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:59:47 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/07 23:08:36 by mcesar-d         ###   ########.fr       */
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
