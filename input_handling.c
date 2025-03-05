/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:43:45 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:00:50 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

int	handle_key_press(int key, t_data *data)
{
	if (key == XK_w || key == XK_W)
	{
		data->move_up = 1;
		data->move_action1 = "W";
	}
	else if (key == XK_s || key == XK_S)
	{
		data->move_down = 1;
		data->move_action1 = "S";
	}
	else if (key == XK_a || key == XK_A)
	{
		data->move_left = 1;
		data->move_action1 = "A";
	}
	else if (key == XK_d || key == XK_D)
	{
		data->move_right = 1;
		data->move_action1 = "D";
	}
	else if (key == XK_Escape || key == 17)
		data->close = 1;
	return (0);
}

int	handle_close(t_data *data)
{
	data->close = 1;
	return (0);
}

int	handle_key_release(int key, t_data *data)
{
	if (key == XK_w || key == XK_W)
	{
		data->move_up = 0;
		data->move_action1 = "NULL";
	}
	else if (key == XK_s || key == XK_S)
	{
		data->move_down = 0;
		data->move_action1 = "NULL";
	}
	else if (key == XK_a || key == XK_A)
	{
		data->move_left = 0;
		data->move_action1 = "NULL";
	}
	else if (key == XK_d || key == XK_D)
	{
		data->move_right = 0;
		data->move_action1 = "NULL";
	}
	return (0);
}

void	monitor_key(t_data *data)
{
	ft_printf("Number of movements: %d\n", data->movements);
}
