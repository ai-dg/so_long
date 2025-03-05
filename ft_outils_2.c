/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:01:32 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/14 16:51:40 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width_point_int(t_print flag, const char *nbr, int *len_str,
		int *c)
{
	int	x;
	int	zero_padding;

	if (flag.point_width == 0 && *c == 0)
		*len_str = 0;
	if (*c == 0 && flag.point_width == 1)
		*len_str += write(1, "0", 1);
	if (*c == 0)
		zero_padding = 1;
	else
		zero_padding = 0;
	x = 0;
	if (flag.point_width == -1)
		flag.point_width = 0;
	if (flag.point_width > (int)ft_strlen(nbr))
	{
		while (x + (int)ft_strlen(nbr) < flag.point_width + zero_padding)
			x += write(1, "0", 1);
		*len_str += x;
	}
}

void	print_width_point(t_print flag, const char *nbr, int *len_str)
{
	int	x;

	x = 0;
	if (flag.point_width == -1)
		flag.point_width = 0;
	if (flag.point_width > (int)ft_strlen(nbr))
	{
		while (x + (int)ft_strlen(nbr) < flag.point_width)
			x += write(1, "0", 1);
		*len_str += x;
	}
}

void	print_padding(int *len_str, int count, char padding_char)
{
	int	i;

	i = 0;
	while (i < count)
	{
		*len_str += write(1, &padding_char, 1);
		i++;
	}
}

void	print_number(const char *nbr, int *len_str)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		*len_str += write(1, &nbr[i], 1);
		i++;
	}
}

int	ft_space_count(const char *str)
{
	int	x;

	x = 0;
	while (str[x] == ' ')
		x++;
	return (x);
}
