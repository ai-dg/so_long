/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:45:58 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:18:40 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_3(const char str, va_list *args, t_print flag)
{
	int	len;

	len = 0;
	if (str == 'c')
		(len += ft_char(va_arg(*args, int), flag));
	if (str == 's')
		(len += ft_string(va_arg(*args, char *), flag));
	else if (str == 'p')
		len += ft_hex((unsigned long long)va_arg(*args, void *), str, flag);
	else if (str == 'd')
		(len += ft_int(va_arg(*args, int), flag));
	else if (str == 'i')
		(len += ft_int(va_arg(*args, int), flag));
	else if (str == 'u')
		(len += ft_unsigned(va_arg(*args, unsigned int), flag));
	else if (str == 'X' || str == 'x')
		(len += ft_hex(va_arg(*args, unsigned int), str, flag));
	else if (str == '%')
		(len += ft_char_sub('%'));
	return (len);
}

static void	ft_check_2(const char *str, int *index, t_print *flag)
{
	if (str[0] == '#')
		flag->hash = 1;
	else if (str[0] == ' ')
	{
		flag->space = 1;
		flag->space_width = ft_space_count(str);
	}
	else if (str[0] == '+')
		flag->plus = 1;
	else if (str[0] == '0')
	{
		flag->zero_width = ft_atoi_flag(str + 1, index);
		flag->zero = 1;
	}
	else if (str[0] == '-')
	{
		flag->width_minus = ft_atoi_flag(str + 1, index);
		flag->minus = 1;
	}
	else if (str[0] == '.')
	{
		flag->point_width = ft_atoi_flag(str + 1, index);
		flag->point = 1;
	}
}

static void	handle_flags(const char *str, int *index, t_print *flag)
{
	if (ft_check_list(str[(*index) + 1], "-0.# +"))
		ft_check_2(str + (*index) + 1, index, flag);
	else
	{
		flag->width_nbr = ft_atoi_flag(str + (*index) + 1, index);
		(*index)--;
	}
}

static int	ft_check_1(const char *str, int *index, va_list *args)
{
	int		total;
	t_print	flag;

	total = 0;
	ft_set_list(&flag);
	while (ft_check_list(str[(*index) + 1], "123456789-0.# +"))
	{
		handle_flags(str, index, &flag);
		(*index)++;
	}
	total += ft_check_3(str[*index + 1], args, flag);
	(*index)++;
	return (total);
}

int	ft_printf(const char *str, ...)
{
	int		index;
	int		count;
	va_list	args;

	va_start(args, str);
	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '%')
			count += ft_check_1(str, &index, &args);
		else
			count += ft_char_sub(str[index]);
		index++;
	}
	va_end(args);
	return (count);
}
