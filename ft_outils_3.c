/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:28:12 by dagudelo          #+#    #+#             */
/*   Updated: 2023/12/14 15:48:34 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	len_nbr(long long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_flag(long long unsigned int n)
{
	char			*str;
	unsigned int	nbr;
	size_t			len_total;

	len_total = len_nbr(n);
	nbr = (unsigned)n;
	str = (char *)malloc(sizeof(char) * (len_total + 1));
	if (str != NULL)
	{
		str[len_total--] = '\0';
		if (n == 0)
			str[0] = '0';
		while (nbr > 0)
		{
			str[len_total--] = (char)(nbr % 10 + '0');
			nbr /= 10;
		}
	}
	return (str);
}

int	ft_check_list(char c, char *base)
{
	int	x;

	x = 0;
	while (base[x])
	{
		if (base[x] == c)
			return (1);
		x++;
	}
	return (0);
}

void	ft_str_extract(char c, char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	str[x] = c;
}

int	ft_atoi_flag(const char *str, int *index)
{
	int	x;
	int	nbr;

	nbr = 0;
	x = 0;
	while (str[x] >= '0' && str[x] <= '9')
	{
		nbr = nbr * 10 + (str[x] - '0');
		x++;
		(*index)++;
	}
	return (nbr);
}
