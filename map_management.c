/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:43:52 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:01:00 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	free_map(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		free(data->map->map[y]);
		y++;
	}
	free(data->map->map);
	data->map->map = NULL;
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("Map: \n");
	while (i < data->map->height)
	{
		ft_printf("%s", data->map->map[i]);
		i++;
	}
}
