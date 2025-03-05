/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:30:02 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 15:26:09 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

bool	back_tracking_entry(t_data *data)
{
	bool	found_path;

	data->start_x = -1;
	data->start_y = -1;
	data->map_copy = copy_map(data);
	if (!find_start_point(data, &data->start_x, &data->start_y))
	{
		free_map_copy(data->map_copy, data->map->height);
		end_process_check(data, "No starting point 'P' found on the map\n");
		return (false);
	}
	found_path = back_tracking(data);
	free_map_copy(data->map_copy, data->map->height);
	return (found_path);
}

void	check_map_empty_or_invalid(t_data *data)
{
	if (data->map->map == NULL || data->map->height == 0
		|| data->map->width == 0)
		end_process_check(data, "The map is empty\n");
}

void	check_character_counts(t_data *data, char c)
{
	if (c == 'P' && ++data->total_player > 1)
		end_process_check(data, "Duplicate player in the map\n");
	if (c == 'E' && ++data->total_exit > 1)
		end_process_check(data, "Duplicate exit in the map\n");
}

void	total_coins_count(t_data *data)
{
	int	i;
	int	j;

	check_rectangular_form(data);
	check_exit_path(data);
	check_map_empty_or_invalid(data);
	i = 0;
	while (i < data->map->height)
	{
		data->row_quantity_wall = 0;
		j = 0;
		while (j < data->map->width - 1)
		{
			data->total_coins += (data->map->map[i][j] == 'C');
			check_character_counts(data, data->map->map[i][j]);
			data->row_quantity_wall += (data->map->map[i][j] == '1');
			j++;
		}
		i++;
	}
	check_total_coins(data);
	if (!back_tracking_entry(data))
		end_process_check(data, "There is no path to win the game\n");
}
