/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:56:05 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/14 16:40:08 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_check_int_2(t_print flag, int *len_str, const char *nbr,
		int *c)
{
	int	nbr_len;

	nbr_len = ft_strlen(nbr);
	if (*c < 0)
	{
		nbr_len += 1;
	}
	if (*c == 0)
		*len_str += write(1, "0", 1);
	if (*c < 0)
		write(1, "-", 1);
	print_padding(len_str, flag.zero_width - nbr_len, '0');
}

static void	zero_check_int_1(t_print flag, int *len_str, const char *nbr,
		int *c)
{
	int	space_padding;
	int	nbr_len;

	nbr_len = ft_strlen(nbr);
	if (*c < 0)
	{
		nbr_len += 1;
	}
	space_padding = 0;
	if (*c == 0)
		nbr_len -= 1;
	if (*c < 0)
		nbr_len -= 1;
	space_padding = flag.zero_width - max(flag.point_width, nbr_len);
	if (*c < 0)
		space_padding -= 1;
	print_padding(len_str, space_padding, ' ');
	if (*c < 0)
		write(1, "-", 1);
	print_padding(len_str, flag.point_width - nbr_len, '0');
}

static void	zero_check_int(t_print flag, const char *nbr, int *len_str, int *c)
{
	if (flag.point == 1 && flag.zero == 0)
	{
		if (*c < 0)
			write(1, "-", 1);
		print_width_point_int(flag, nbr, len_str, c);
	}
	else if (flag.zero == 1 && flag.point == 0)
	{
		zero_check_int_2(flag, len_str, nbr, c);
	}
	else if (flag.point == 1 && flag.zero == 1)
	{
		zero_check_int_1(flag, len_str, nbr, c);
	}
	else if (flag.zero == 0 && flag.point == 0)
	{
		if (*c == 0)
			*len_str += write(1, "0", 1);
		if (*c < 0)
			write(1, "-", 1);
	}
}

static void	print_int(const char *nbr, int *len_str, t_print flag, int *c)
{
	int	x;

	x = 0;
	if (*c < 0)
	{
		*len_str += 1;
	}
	ft_space_plus(flag, len_str, (int *)c);
	if (nbr[0] == '0')
	{
		zero_check_int(flag, nbr, len_str, c);
		return ;
	}
	else
	{
		zero_check_int(flag, nbr, len_str, c);
		print_number(nbr, len_str);
	}
}

void	print_width_nbr_1_int(const char *nbr, t_print flag, int *len_str,
		int *c)
{
	int	spaces_to_add;
	int	x;

	x = 0;
	print_int(nbr, len_str, flag, c);
	if (flag.minus == 1)
	{
		spaces_to_add = flag.width_minus - *len_str;
		while (x < spaces_to_add)
			x += write(1, " ", 1);
		*len_str += x;
	}
}
