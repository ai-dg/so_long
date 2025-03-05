/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:45:45 by dagudelo          #+#    #+#             */
/*   Updated: 2025/03/05 19:58:50 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_check_int_2(t_print flag, int *len_str, const char *nbr,
		unsigned int *c)
{
	int	nbr_len;

	nbr_len = ft_strlen(nbr);
	if (*c == 0)
		*len_str += write(1, "0", 1);
	print_padding(len_str, flag.zero_width - nbr_len, '0');
}

static void	zero_check_int_1(t_print flag, int *len_str, const char *nbr,
		unsigned int *c)
{
	int	space_padding;
	int	nbr_len;

	nbr_len = ft_strlen(nbr);
	space_padding = 0;
	if (*c == 0)
		nbr_len -= 1;
	space_padding = flag.zero_width - max(flag.point_width, nbr_len);
	print_padding(len_str, space_padding, ' ');
	print_padding(len_str, flag.point_width - nbr_len, '0');
}

static void	zero_check_uint(t_print flag, const char *nbr, int *len_str,
		unsigned int *c)
{
	if (flag.point == 1 && flag.zero == 0)
		print_width_point_int(flag, nbr, len_str, (int *)c);
	else if (flag.zero == 1 && flag.point == 0)
		zero_check_int_2(flag, len_str, nbr, c);
	else if (flag.point == 1 && flag.zero == 1)
		zero_check_int_1(flag, len_str, nbr, c);
	else if (flag.zero == 0 && flag.point == 0)
		if (*c == 0)
			*len_str += write(1, "0", 1);
}

static void	print_uint(const char *nbr, int *len_str, t_print flag,
		unsigned int *c)
{
	ft_space_plus(flag, len_str, (int *)c);
	if (nbr[0] == '0')
	{
		zero_check_uint(flag, nbr, len_str, c);
		return ;
	}
	else
	{
		zero_check_uint(flag, nbr, len_str, c);
		print_number(nbr, len_str);
	}
}

void	print_width_nbr_1_uint(const char *nbr, t_print flag, int *len_str,
		unsigned int *c)
{
	int	spaces_to_add;
	int	x;

	x = 0;
	print_uint(nbr, len_str, flag, c);
	if (flag.minus == 1)
	{
		spaces_to_add = flag.width_minus - *len_str;
		while (x < spaces_to_add)
			x += write(1, " ", 1);
		*len_str += x;
	}
}
