/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:43:33 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:00:34 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	update_done_status(t_data *data)
{
	data->repeat += 1;
	if ((data->move_right == 1 || data->move_left == 1 || data->move_up == 1
			|| data->move_down == 1) && data->done == 0)
		data->done += 1;
	if ((data->move_right == 1 || data->move_left == 1 || data->move_up == 1
			|| data->move_down == 1) && data->done == 1)
		move_player(data);
}

void	reset_repeat_and_done(t_data *data)
{
	if (data->repeat == 200)
	{
		data->done = 0;
		data->repeat = 0;
	}
}

void	move_player(t_data *data)
{
	int	player_moved;
	int	y;
	int	x;

	player_moved = 0;
	y = 0;
	x = 0;
	while (y < data->map->height && !player_moved)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->map[y][x] == 'P')
			{
				if (data->move_right == 1 || data->move_left == 1
					|| data->move_up == 1 || data->move_down == 1)
				{
					data->player_x = x;
					data->player_y = y;
				}
			}
			x++;
		}
		y++;
	}
}
