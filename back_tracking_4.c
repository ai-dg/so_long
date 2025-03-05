/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:30:02 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:00:28 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	check_exit_position(t_data *data, int x_exit, int y_exit)
{
	if (x_exit == -1)
		end_process_check(data, "There is no exit in the map\n");
	if (data->map->map[x_exit + 1][y_exit] == '1' && data->map->map[x_exit
		- 1][y_exit] == '1' && data->map->map[x_exit][y_exit + 1] == '1'
		&& data->map->map[x_exit][y_exit - 1] == '1')
		end_process_check(data, "Exit is surrounded by walls\n");
}

void	check_exit_path(t_data *data)
{
	int	i;
	int	j;
	int	x_exit;
	int	y_exit;

	i = 0;
	j = 0;
	x_exit = -1;
	y_exit = -1;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width - 1)
		{
			if (data->map->map[i][j] == 'E')
			{
				x_exit = i;
				y_exit = j;
				break ;
			}
			j++;
		}
		i++;
	}
	check_exit_position(data, x_exit, y_exit);
}

void	fill_len_rows(int *len_rows, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		if (i < data->map->height - 1)
			len_rows[i] = ft_strlen_push_swap(data->map->map[i]) - 1;
		else
			len_rows[i] = ft_strlen_push_swap(data->map->map[i]);
		i++;
	}
}

void	check_rows_symetrie(t_data *data)
{
	int	*len_rows;
	int	i;
	int	first;

	len_rows = (int *)malloc(sizeof(int) * data->map->height);
	if (len_rows == NULL)
		end_process_check(data, "Memory allocation failed\n");
	fill_len_rows(len_rows, data);
	first = len_rows[0];
	i = 0;
	while (i < data->map->height)
	{
		if (first != len_rows[i])
		{
			free(len_rows);
			end_process_check(data,
				"Please set up the lines with the same amount of characters\n");
		}
		i++;
	}
	free(len_rows);
}

void	check_rectangular_form(t_data *data)
{
	if (data->map->height == data->map->width - 1)
		end_process_check(data, "The map is not rectangular\n");
}
