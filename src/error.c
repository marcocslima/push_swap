/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:17:11 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/08/03 10:46:31 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	msg(char *err)
{
	write(2, "Error: ", 7);
	write(2, err, ft_strlen(err));
	exit (EXIT_FAILURE);
}
