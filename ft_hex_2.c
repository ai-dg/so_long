/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:52:21 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/14 15:47:17 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_prefix(int *len_str, char index, const char *nbr)
{
	if (index == 'p' && nbr[0] != '0')
		*len_str += write(1, "0x", 2);
}

static void	zero_check(t_print flag, const char *nbr, int *len_str, int nbr_len)
{
	int	space_padding;

	if (flag.point == 1 && flag.zero == 0)
		print_width_point(flag, nbr, len_str);
	else if (flag.zero == 1 && flag.point == 0)
		print_padding(len_str, flag.zero_width - nbr_len, '0');
	else if (flag.point == 1 && flag.zero == 1)
	{
		space_padding = flag.zero_width - max(flag.point_width, nbr_len);
		print_padding(len_str, space_padding, ' ');
		print_padding(len_str, flag.point_width - nbr_len, '0');
	}
}

static void	print_hex(const char *nbr, int *len_str, t_print flag, char index)
{
	int	nbr_len;

	nbr_len = ft_strlen(nbr);
	print_prefix(len_str, index, nbr);
	if (nbr[0] == '0')
	{
		if (index == 'p')
			*len_str += 5;
		else
			*len_str += 1;
		zero_check(flag, nbr, len_str, nbr_len);
		return ;
	}
	zero_check(flag, nbr, len_str, nbr_len);
	print_number(nbr, len_str);
}

void	print_width_nbr_1(const char *nbr, t_print flag, int *len_str,
		char index)
{
	int	spaces_to_add;
	int	x;

	x = 0;
	ft_hash(flag, nbr, len_str, index);
	print_hex(nbr, len_str, flag, index);
	if (index == 'p' && nbr[0] == '0')
		write(1, "(nil)", 5);
	if ((index == 'X' || index == 'x') && nbr[0] == '0')
		write(1, "0", 1);
	if (flag.minus == 1)
	{
		spaces_to_add = flag.width_minus - *len_str;
		while (x < spaces_to_add)
			x += write(1, " ", 1);
		*len_str += x;
	}
}
