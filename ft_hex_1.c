/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:49:09 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/14 15:48:15 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width_nbr(const char *nbr, t_print flag, int *len_str,
		char index)
{
	int	x;
	int	additional_length;

	x = 0;
	additional_length = 0;
	if ((index == 'X' || index == 'x') && nbr[0] == '0')
		additional_length = 1;
	if (index == 'p' && nbr[0] == '0')
		additional_length = 4;
	if (index == 'p' && nbr[0] != '0')
		additional_length = 2;
	if (flag.width_nbr > (int)ft_strlen(nbr) + additional_length)
	{
		while (x + (int)ft_strlen(nbr) + additional_length < flag.width_nbr)
		{
			*len_str += write(1, " ", 1);
			x++;
		}
	}
	print_width_nbr_1(nbr, flag, len_str, index);
}

static unsigned long long	ft_hex_len(unsigned long long nbr)
{
	unsigned long long	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned long long nbr, const char index, char *str,
		t_print flag)
{
	if (flag.point_width == -1)
		flag.point_width = 0;
	if (nbr == 0 && flag.point == 1 && flag.point_width == 0)
	{
		str[0] = '\0';
		return ;
	}
	if (nbr <= 9)
		ft_str_extract((nbr + '0'), str);
	else if (nbr >= 16)
	{
		ft_put_hex(nbr / 16, index, str, flag);
		ft_put_hex(nbr % 16, index, str, flag);
	}
	else
	{
		if (index != 'X')
			ft_str_extract((nbr - 10 + 'a'), str);
		else if (index == 'X')
			ft_str_extract((nbr - 10 + 'A'), str);
	}
}

int	ft_hex(unsigned long long nbr, const char index, t_print flag)
{
	unsigned long long	len;
	char				*str;

	str = (char *)malloc(sizeof(char) * ft_hex_len(nbr) + 3);
	if (str == NULL)
	{
		return (0);
	}
	ft_memset(str, 0, sizeof(char) * ft_hex_len(nbr) + 3);
	len = 0;
	ft_put_hex(nbr, index, str, flag);
	print_width_nbr(str, flag, (int *)&len, index);
	free(str);
	return (len);
}
