/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:43:58 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 15:17:14 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	*load_image(char *path, t_data *data, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr, path, width, height);
	if (!img)
	{
		ft_printf("Error\nFailed to load image %s\n", path);
		free_resources(data);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	load_xpm(t_data *data)
{
	data->img->img_width_wall = 0;
	data->img->img_height_wall = 0;
	data->img->img_width_coin = 25;
	data->img->img_height_coin = 25;
	data->img->img_width_player = 0;
	data->img->img_height_player = 0;
	data->img->img_width_exit = 0;
	data->img->img_height_exit = 0;
	data->img->img_width_background = 0;
	data->img->img_height_background = 0;
	data->map->wall = load_image("./xpm/bloc.xpm", data,
			&data->img->img_width_wall, &data->img->img_height_wall);
	data->map->coin = load_image("./xpm/coin/coin_0.xpm", data,
			&data->img->img_width_coin, &data->img->img_height_coin);
	data->map->player = load_image("./xpm/player/player.xpm", data,
			&data->img->img_width_player, &data->img->img_height_player);
	data->map->exit = load_image("./xpm/exit.xpm", data,
			&data->img->img_width_exit, &data->img->img_height_exit);
	data->map->background = load_image("./xpm/background.xpm", data,
			&data->img->img_width_background,
			&data->img->img_height_background);
}

void	draw_background_coins_wall(char tile, t_data *data)
{
	if (tile == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->map->background, data->x_tmp * 50, data->y_tmp * 50);
	if (tile == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->map->wall,
			data->x_tmp * 50, data->y_tmp * 50);
	if (tile == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->map->coin,
			data->x_tmp * 50 + (50 - data->img->img_width_coin) / 2, data->y_tmp
			* 50 + (50 - data->img->img_height_coin) / 2);
}

void	draw_img(t_data *data)
{
	char	tile;

	tile = data->map->map[data->y_tmp][data->x_tmp];
	draw_background_coins_wall(tile, data);
	if (tile == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->map->exit,
			data->x_tmp * 50 + (50 - data->img->img_width_exit) / 2, data->y_tmp
			* 50 + (50 - data->img->img_height_exit) / 2);
	if (tile == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->map->player,
			(data->x_tmp * 50 + (50 - data->img->img_width_player) / 2),
			data->y_tmp * 50 + (50 - data->img->img_height_player) / 2);
	if (tile != '1' && tile != 'C' && tile != 'E' && tile != 'P' && tile != '0'
		&& tile != '\n' && tile != 0)
	{
		ft_printf("Error\n Invalid map character at  x = %d, y = %d\n",
			data->x_tmp + 1, data->y_tmp + 1);
		end_game(data);
	}
}

void	draw_map(t_data *data)
{
	data->x_tmp = 0;
	data->y_tmp = 0;
	while (data->y_tmp < data->map->height)
	{
		data->x_tmp = 0;
		while (data->x_tmp < data->map->width)
		{
			draw_img(data);
			data->x_tmp++;
		}
		data->y_tmp++;
	}
}
