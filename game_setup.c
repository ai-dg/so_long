/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:43:42 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:43:19 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	set_values(t_data *data, char *av)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->key = 0;
	data->move_up = 0;
	data->move_down = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->close = 0;
	data->move_action1 = NULL;
	data->atk_action1 = NULL;
	data->av = av;
	data->player_x = 0;
	data->player_y = 0;
	data->done = 0;
	data->repeat = 0;
	set_values_2(data);
}

int	check_file_extension(char *filepath)
{
	int	path_len;

	path_len = ft_strlen_push_swap(filepath);
	if (path_len < 4)
		return (0);
	if (ft_strcmp(&filepath[path_len - 4], ".ber") != 0)
		return (0);
	return (1);
}

char	**allocate_initial_map(t_data *data)
{
	char	**map;

	map = malloc(data->capacity * sizeof(char *));
	if (!map)
	{
		ft_printf("Error\nAllocation memory error map->map\n");
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_printf("Error opening the filepath\n");
		exit(EXIT_FAILURE);
	}
	return (map);
}

void	read_and_resize_map(int fd, int *capacity, int *row, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*row >= *capacity)
		{
			*capacity *= 2;
			data->map->map = ft_realloc(data->map->map, *capacity
					* sizeof(char *));
			if (!data->map->map)
				return (ft_printf("Error\nMalloc map\n"), free(line),
					mlx_destroy_display(data->mlx_ptr), free(data->map->map));
		}
		data->map->map[*row] = ft_strdup(line);
		if (*row == 0)
			data->map->width = ft_strlen_push_swap(line);
		free(line);
		(*row)++;
		line = get_next_line(fd);
	}
	data->map->height = *row;
	check_game_setup(data);
	free(line);
}

void	read_map(t_data *data, char *filepath)
{
	int	fd;
	int	row;

	if (!check_file_extension(filepath))
		end_process_check_filepath(data);
	data->capacity = 10;
	data->map->map = allocate_initial_map(data);
	if (!data->map->map)
		return ;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		free(data->map->map);
		end_process_check_filepath(data);
	}
	row = 0;
	read_and_resize_map(fd, &data->capacity, &row, data);
	close(fd);
}
