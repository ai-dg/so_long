/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:52:45 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/28 14:59:54 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c, t_print flag)
{
	int	x;

	x = 0;
	while (x + 1 < flag.width_nbr)
		x += ft_char_sub(' ');
	x += ft_char_sub(c);
	while (x < flag.width_minus)
		x += ft_char_sub(' ');
	return (x);
}
