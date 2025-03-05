/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:30:02 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:00:21 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

char	**allocate_map(t_data *data)
{
	char	**map;

	map = (char **)malloc(data->map->height * sizeof(char *));
	if (!map)
		end_process_check(data, "Failed to allocate memory for map copy\n");
	return (map);
}

char	**copy_map(t_data *data)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = allocate_map(data);
	while (i < data->map->height)
	{
		map_copy[i] = (char *)malloc((data->map->width + 1) * sizeof(char));
		if (!map_copy[i])
		{
			free_map_copy(map_copy, i);
			end_process_check(data,
				"Failed to allocate memory for map copy row\n");
		}
		ft_strncpy(map_copy[i], data->map->map[i], data->map->width + 1);
		i++;
	}
	return (map_copy);
}

bool	is_safe(t_data *data)
{
	return (data->x >= 0 && data->x < data->map->width - 2 && data->y >= 0
		&& data->y < data->map->height
		&& data->map_copy[data->x][data->y] != '1');
}

int	*initialize_dx(t_data *data)
{
	int	*dx;

	dx = (int *)malloc(sizeof(int) * 4);
	if (dx == NULL)
		end_process_check(data, "Memory allocation failed dx\n");
	dx[0] = -1;
	dx[1] = 0;
	dx[2] = 1;
	dx[3] = 0;
	return (dx);
}

int	*initialize_dy(t_data *data)
{
	int	*dy;

	dy = (int *)malloc(sizeof(int) * 4);
	if (dy == NULL)
		end_process_check(data, "Memory allocation failed dy\n");
	dy[0] = 0;
	dy[1] = 1;
	dy[2] = 0;
	dy[3] = -1;
	return (dy);
}
