/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:26:24 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/07/29 10:11:35 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_recursive_power(int nb, int power)
{
	int	pot;

	if ((nb == 0 && power == 0) || (nb != 0 && power == 0))
		return (1);
	if (power < 0)
		return (0);
	else
	{
		pot = nb * ft_recursive_power(nb, power - 1);
	}
	return (pot);
}
