/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:06:52 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/14 14:29:19 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width_nbr_int(const char *nbr, t_print flag, int *c,
		int *len_str)
{
	int	x;

	x = 0;
	if (flag.width_nbr > (int)ft_strlen(nbr))
	{
		if (*c < 0)
		{
			while (x + (int)ft_strlen(nbr) < flag.width_nbr - 1)
				x += write(1, " ", 1);
			*len_str += flag.width_nbr - ft_strlen(nbr) - 1;
		}
		else
		{
			while (x + (int)ft_strlen(nbr) < flag.width_nbr)
				x += write(1, " ", 1);
			*len_str += flag.width_nbr - ft_strlen(nbr);
		}
		print_width_nbr_1_int(nbr, flag, len_str, c);
	}
	else
		print_width_nbr_1_int(nbr, flag, len_str, c);
	ft_minus(flag, len_str);
}

int	ft_int(int c, t_print flag)
{
	char	*nbr;
	long	a;
	int		len_str;

	len_str = 0;
	a = (long)c;
	if (c < 0)
		a *= -1;
	nbr = ft_itoa_flag(a);
	print_width_nbr_int(nbr, flag, &c, &len_str);
	free(nbr);
	return (len_str);
}
