/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:01:54 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/14 15:27:35 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space_plus(t_print flag, int *len_str, int *c)
{
	int	x;

	x = 0;
	if (flag.space == 1)
	{
		if (*c >= 0)
		{
			while (x < flag.space_width)
			{
				write(1, " ", 1);
				x++;
			}
			*len_str += x;
		}
	}
	if (flag.plus == 1)
	{
		if (*c >= 0)
		{
			*len_str += write(1, "+", 1);
		}
	}
}

void	ft_minus(t_print flag, int *len_str)
{
	int	spaces_to_add;
	int	x;

	x = 0;
	spaces_to_add = 0;
	if (flag.minus == 1)
	{
		spaces_to_add = flag.width_minus - *len_str;
		while (x < spaces_to_add)
			x += write(1, " ", 1);
		*len_str += x;
	}
}

void	ft_hash(t_print flag, const char *nbr, int *len_str, char index)
{
	if (flag.hash == 1)
	{
		if (nbr[0] != '0')
		{
			if (index == 'x')
				write(1, "0x", 2);
			if (index == 'X')
				write(1, "0X", 2);
			*len_str += 2;
		}
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_set_list(t_print *flag)
{
	flag->hash = 0;
	flag->space = 0;
	flag->width_nbr = 0;
	flag->space_width = 0;
	flag->plus = 0;
	flag->minus = 0;
	flag->point = 0;
	flag->point_width = -1;
	flag->zero = 0;
	flag->zero_width = -1;
	flag->width_minus = 0;
}
