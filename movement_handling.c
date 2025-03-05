/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:43:55 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:01:05 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	end_game(t_data *data)
{
	free_resources(data);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	handle_movement_right(t_data *data)
{
	if (data->map->map[data->player_y][data->player_x + 1] == '1')
		ft_printf("There are a wall\n");
	else if (data->map->map[data->player_y][data->player_x + 1] == 'E')
	{
		if (data->current_coins == data->total_coins)
		{
			ft_printf("You won ! \n");
			end_game(data);
		}
		else
			ft_printf("You have to get all the coins !\n");
	}
	else
	{
		if (data->map->map[data->player_y][data->player_x + 1] == 'C')
			data->current_coins++;
		data->map->map[data->player_y][data->player_x + 1] = 'P';
		data->map->map[data->player_y][data->player_x] = '0';
		data->movements++;
	}
	data->done += 1;
	monitor_key(data);
}

void	handle_movement_left(t_data *data)
{
	if (data->map->map[data->player_y][data->player_x - 1] == '1')
		ft_printf("There are a wall \n");
	else if (data->map->map[data->player_y][data->player_x - 1] == 'E')
	{
		if (data->current_coins == data->total_coins)
		{
			ft_printf("You won ! \n");
			end_game(data);
		}
		else
			ft_printf("You have to get all the coins !\n");
	}
	else
	{
		if (data->map->map[data->player_y][data->player_x - 1] == 'C')
			data->current_coins++;
		data->map->map[data->player_y][data->player_x - 1] = 'P';
		data->map->map[data->player_y][data->player_x] = '0';
		data->movements++;
	}
	data->done += 1;
	monitor_key(data);
}

void	handle_movement_up(t_data *data)
{
	if (data->map->map[data->player_y - 1][data->player_x] == '1')
	{
		ft_printf("There are a wall \n");
	}
	else if (data->map->map[data->player_y - 1][data->player_x] == 'E')
	{
		if (data->current_coins == data->total_coins)
		{
			ft_printf("You won ! \n");
			end_game(data);
		}
		else
			ft_printf("You have to get all the coins !\n");
	}
	else
	{
		if (data->map->map[data->player_y - 1][data->player_x] == 'C')
			data->current_coins++;
		data->map->map[data->player_y - 1][data->player_x] = 'P';
		data->map->map[data->player_y][data->player_x] = '0';
		data->movements++;
	}
	data->done += 1;
	monitor_key(data);
}

void	handle_movement_down(t_data *data)
{
	if (data->map->map[data->player_y + 1][data->player_x] == '1')
	{
		ft_printf("There are a wall \n");
	}
	else if (data->map->map[data->player_y + 1][data->player_x] == 'E')
	{
		if (data->current_coins == data->total_coins)
		{
			ft_printf("You won ! \n");
			end_game(data);
		}
		else
			ft_printf("You have to get all the coins !\n");
	}
	else
	{
		if (data->map->map[data->player_y + 1][data->player_x] == 'C')
			data->current_coins++;
		data->map->map[data->player_y + 1][data->player_x] = 'P';
		data->map->map[data->player_y][data->player_x] = '0';
		data->movements++;
	}
	data->done += 1;
	monitor_key(data);
}
