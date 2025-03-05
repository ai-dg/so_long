/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:18:50 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 14:27:57 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	end_process_check_filepath(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_printf("Error opening the filepath\n");
	exit(EXIT_FAILURE);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	check_closed_map_conditional(t_data *data, int i, int j)
{
	if (j <= data->map->width - 2)
	{
		if (i == 0 && data->map->map[i][j] != '1')
			end_process_check(data,
				"The map is not closed/surrounded by walls\n");
		if (i == data->map->height - 1 && data->map->map[i][j] != '1')
			end_process_check(data,
				"The map is not closed/surrounded by walls\n");
		if (j == 0 && data->map->map[i][j] != '1')
			end_process_check(data,
				"The map is not closed/surrounded by walls\n");
		if (j == data->map->width - 2 && data->map->map[i][j] != '1')
			end_process_check(data,
				"The map is not closed/surrounded by walls\n");
	}
}

void	set_values_3(t_data *data)
{
	data->map->width = 0;
	data->map->height = 0;
	data->map->map = NULL;
	data->map->capacity = 0;
	data->map->wall = NULL;
	data->map->coin = NULL;
	data->map->player = NULL;
	data->map->exit = NULL;
	data->map->background = NULL;
	data->img->img_width_wall = 0;
	data->img->img_height_wall = 0;
	data->img->img_width_coin = 0;
	data->img->img_height_coin = 0;
	data->img->img_width_player = 0;
	data->img->img_height_player = 0;
	data->img->img_width_exit = 0;
	data->img->img_height_exit = 0;
	data->img->img_width_background = 0;
	data->img->img_height_background = 0;
}

void	set_values_2(t_data *data)
{
	data->x_tmp = 0;
	data->y_tmp = 0;
	data->movements = 0;
	data->current_coins = 0;
	data->count_coins = 0;
	data->total_coins = 0;
	data->total_player = 0;
	data->total_exit = 0;
	data->row_quantity_wall = 0;
	data->window_width = 0;
	data->window_height = 0;
	data->capacity = 0;
	data->start_x = 0;
	data->start_y = 0;
	data->x = 0;
	data->y = 0;
	data->map_copy = NULL;
	data->accessible_zeros = 0;
	data->total_zeros = 0;
	data->exit_count = 0;
	set_values_3(data);
}
