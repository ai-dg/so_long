/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:49:18 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/14 15:44:45 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width_nbr_uint(const char *nbr, t_print flag, unsigned int *c,
		int *len_str)
{
	int	x;

	x = 0;
	if (flag.width_nbr > (int)ft_strlen(nbr))
	{
		while (x + (int)ft_strlen(nbr) < flag.width_nbr)
			x += write(1, " ", 1);
		*len_str += x;
		print_width_nbr_1_uint(nbr, flag, len_str, c);
	}
	else
		print_width_nbr_1_uint(nbr, flag, len_str, c);
	ft_minus(flag, len_str);
}

static int	ft_nbr_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (len = 1);
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

static char	*ft_itoa_unsigned(unsigned int c)
{
	char			*str;
	unsigned int	nbr;
	size_t			len_total;

	len_total = ft_nbr_len(c);
	nbr = (unsigned)c;
	str = (char *)malloc(sizeof(char) * (len_total + 1));
	if (str != NULL)
	{
		str[len_total] = '\0';
		if (c == 0)
			str[0] = '0';
		else
		{
			while (nbr > 0)
			{
				str[--len_total] = (char)(nbr % 10 + '0');
				nbr /= 10;
			}
		}
	}
	return (str);
}

int	ft_unsigned(unsigned int c, t_print flag)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_itoa_unsigned(c);
	print_width_nbr_uint(nbr, flag, &c, &len);
	free(nbr);
	nbr = NULL;
	return (len);
}
