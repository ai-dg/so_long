/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:44:06 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:01:25 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	open_windows(t_data *data)
{
	data->window_height = data->map->height * 50;
	data->window_width = (data->map->width - 1) * 50;
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->window_width,
			data->window_height, WINDOW_TITLE);
	if (!data->mlx_win)
	{
		ft_printf("Failed to create window\n");
		free_resources(data);
		exit(EXIT_FAILURE);
	}
}

void	free_resources(t_data *data)
{
	free_map(data);
	free_images(data);
}
