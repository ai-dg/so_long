/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:43:49 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 15:45:00 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	initial_config(t_data *data)
{
	read_map(data, data->av);
	open_windows(data);
	load_xpm(data);
}

int	main(int ac, char *av[])
{
	t_data	data;
	t_map	map;
	t_img	img;

	data.map = &map;
	data.img = &img;
	if (ac != 2)
		return (ft_printf("Error\nUsage: %s <filepath.ber>\n", av[0]), 1);
	set_values(&data, av[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (ft_printf("Error\nFailed to initialize MLX\n"), 1);
	initial_config(&data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, handle_key_press, &data);
	mlx_hook(data.mlx_win, 17, 0L, handle_close, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, handle_key_release,
		&data);
	mlx_loop_hook(data.mlx_ptr, loop_hook, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free_resources(&data);
	return (0);
}

void	repeat_process(t_data *data)
{
	reset_repeat_and_done(data);
	draw_map(data);
	if (data->close == 1)
	{
		free_images(data);
		mlx_loop_end(data->mlx_ptr);
	}
}

int	loop_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	update_done_status(data);
	if (data->done == 1)
	{
		if (data->move_right == 1 && data->move_left == 0 && data->move_up == 0
			&& data->move_down == 0)
			handle_movement_right(data);
		if (data->move_left == 1 && data->move_right == 0 && data->move_up == 0
			&& data->move_down == 0)
			handle_movement_left(data);
		if (data->move_up == 1 && data->move_left == 0 && data->move_right == 0
			&& data->move_down == 0)
			handle_movement_up(data);
		if (data->move_down == 1 && data->move_left == 0 && data->move_up == 0
			&& data->move_right == 0)
			handle_movement_down(data);
	}
	repeat_process(data);
	return (0);
}
