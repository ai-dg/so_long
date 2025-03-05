/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_cleanup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:44:02 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 14:27:09 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	free_images(t_data *data)
{
	if (data->map->wall != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->map->wall);
		data->map->wall = NULL;
	}
	if (data->map->coin != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->map->coin);
		data->map->coin = NULL;
	}
	if (data->map->player != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->map->player);
		data->map->player = NULL;
	}
	if (data->map->exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->map->exit);
		data->map->exit = NULL;
	}
	if (data->map->background != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->map->background);
		data->map->background = NULL;
	}
}
