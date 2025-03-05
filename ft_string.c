/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:29 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/14 14:48:20 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_precision_point(t_print flag, const char *str, int *len_str)
{
	int			x;
	const char	*str_null = "(null)";

	x = 0;
	if (flag.point_width == -1)
		flag.point_width = 0;
	if (flag.point_width < 6 && !str)
		return ;
	else if (flag.point_width >= 6 && !str)
		str = str_null;
	if (str)
	{
		while (str[x] && x < flag.point_width)
		{
			*len_str += write(1, &str[x], 1);
			x++;
		}
	}
}

static void	print_string(const char *str, int *len_str, t_print flag)
{
	if (flag.point == 1)
		print_precision_point(flag, str, len_str);
	else if (str)
		*len_str += write(1, str, ft_strlen(str));
	else
		*len_str += write(1, "(null)", 6);
}

static void	print_width_str(const char *str, t_print flag, int *len_str)
{
	int	x;
	int	required_len;

	x = 0;
	if (flag.point_width == -1)
		flag.point_width = 0;
	if (str)
		required_len = ft_strlen(str);
	else
		required_len = 6;
	if (flag.point == 1 && flag.point_width < required_len)
		required_len = flag.point_width;
	while (x + required_len < flag.width_nbr)
	{
		*len_str += write(1, " ", 1);
		x++;
	}
	print_string(str, len_str, flag);
}

int	ft_string(char *str, t_print flag)
{
	int	len_str;

	len_str = 0;
	print_width_str(str, flag, &len_str);
	while (len_str < flag.width_minus)
		len_str += write(1, " ", 1);
	return (len_str);
}
