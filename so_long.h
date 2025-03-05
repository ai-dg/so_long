/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:47:33 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:25:01 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WINDOW_TITLE "so_long"
# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 450

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		capacity;
	void	*wall;
	void	*coin;
	void	*player;
	void	*exit;
	void	*background;
}			t_map;

typedef struct s_img
{
	int		img_width_wall;
	int		img_height_wall;
	int		img_width_coin;
	int		img_height_coin;
	int		img_width_player;
	int		img_height_player;
	int		img_width_exit;
	int		img_height_exit;
	int		img_width_background;
	int		img_height_background;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		key;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		close;
	char	*move_action1;
	char	*atk_action1;
	char	*av;
	int		player_x;
	int		player_y;
	int		done;
	int		repeat;
	int		x_tmp;
	int		y_tmp;
	int		movements;
	int		current_coins;
	int		count_coins;
	int		total_coins;
	int		total_player;
	int		total_exit;
	int		row_quantity_wall;
	int		window_width;
	int		window_height;
	int		capacity;
	int		start_x;
	int		start_y;
	int		x;
	int		y;
	char	**map_copy;
	int		accessible_zeros;
	int		total_zeros;
	int		exit_count;
	t_map	*map;
	t_img	*img;
}			t_data;

void		open_windows(t_data *data);
int			handle_key_press(int key, t_data *data);
int			handle_key_release(int key, t_data *data);
void		monitor_key(t_data *data);
int			loop_hook(void *param);
void		read_map(t_data *data, char *filepath);
void		print_map(t_data *data);
void		draw_map(t_data *data);
void		free_map(t_data *data);
void		free_images(t_data *data);
void		move_player(t_data *data);
void		set_values(t_data *data, char *av);
void		free_resources(t_data *data);
void		update_done_status(t_data *data);
void		handle_movement_right(t_data *data);
void		handle_movement_left(t_data *data);
void		handle_movement_up(t_data *data);
void		handle_movement_down(t_data *data);
void		reset_repeat_and_done(t_data *data);
int			check_file_extension(char *filepath);
char		**allocate_initial_map(t_data *data);
void		read_and_resize_map(int fd, int *capacity, int *row, t_data *data);
void		*load_image(char *path, t_data *data, int *width, int *height);
void		load_xpm(t_data *data);
void		draw_img(t_data *data);
int			handle_close(t_data *data);
void		end_game(t_data *data);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *src);
size_t		ft_strlen_push_swap(const char *s);
void		total_coins_count(t_data *data);
void		check_closed_map(t_data *data);
void		end_process_check(t_data *data, char *msg);
void		end_process_check_filepath(t_data *data);
void		total_coins_count(t_data *data);
void		explore_zeros(t_data *data);
void		free_map_copy(char **map_copy, int height);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		**copy_map(t_data *data);
bool		find_start_point(t_data *data, int *start_x, int *start_y);
bool		back_tracking(t_data *data);
void		check_closed_map_conditional(t_data *data, int i, int j);
void		set_values_2(t_data *data);
int			*initialize_dx(t_data *data);
int			*initialize_dy(t_data *data);
void		check_exit_path(t_data *data);
void		check_rows_symetrie(t_data *data);
void		check_rectangular_form(t_data *data);
void		check_total_coins(t_data *data);
void		*ft_realloc(void *ptr, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		check_game_setup(t_data *data);

#endif