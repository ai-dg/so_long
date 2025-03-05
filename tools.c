/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:18:27 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 15:26:58 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}
	if (*s1 == '\0')
	{
		return (-(*s2));
	}
	if (*s2 == '\0')
	{
		return (*s1);
	}
	if (*s1 != *s2)
	{
		return (*s1 - *s2);
	}
	return (ft_strcmp(s1 + 1, s2 + 1));
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;
	int		i;

	if (src == NULL)
		return (NULL);
	len = ft_strlen_push_swap(src) + 1;
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen_push_swap(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	end_process_check(t_data *data, char *msg)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data);
	ft_printf("Error\n%s", msg);
	exit(EXIT_FAILURE);
}

void	check_closed_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			check_closed_map_conditional(data, i, j);
			j++;
		}
		i++;
	}
}
