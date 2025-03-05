/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:30:02 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:00:25 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	explore_direction(t_data *data, int dx, int dy)
{
	int	old_x;
	int	old_y;

	old_x = data->x + dx;
	old_y = data->y + dy;
	if (data->map_copy[old_x][old_y] == 'E')
		data->exit_count++;
	if (old_x >= 0 && old_x < data->map->height && old_y >= 0
		&& old_y < data->map->width && data->map_copy[old_x][old_y] != '1'
		&& data->map_copy[old_x][old_y] != 'V'
		&& data->map_copy[old_x][old_y] != 'E')
	{
		data->x = old_x;
		data->y = old_y;
		explore_zeros(data);
		data->x -= dx;
		data->y -= dy;
	}
}

void	explore_zeros(t_data *data)
{
	int	*dx;
	int	*dy;
	int	i;

	i = 0;
	dx = initialize_dx(data);
	dy = initialize_dy(data);
	if (data->map_copy[data->x][data->y] == '0')
		data->accessible_zeros++;
	if (data->map_copy[data->x][data->y] == 'C')
		data->count_coins++;
	data->map_copy[data->x][data->y] = 'V';
	while (i < 4)
	{
		explore_direction(data, dx[i], dy[i]);
		i++;
	}
	free(dx);
	free(dy);
}

bool	back_tracking(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->total_zeros = 0;
	data->accessible_zeros = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map_copy[i][j] == '0')
				data->total_zeros++;
			j++;
		}
		i++;
	}
	data->x = data->start_x;
	data->y = data->start_y;
	explore_zeros(data);
	return (data->count_coins == data->total_coins && data->exit_count > 0);
}

void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

bool	find_start_point(t_data *data, int *start_x, int *start_y)
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
			if (data->map_copy[i][j] == 'P')
			{
				*start_x = i;
				*start_y = j;
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
