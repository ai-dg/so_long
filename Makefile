SRC =	game_logic.c game_setup.c input_handling.c \
		main.c map_management.c movement_handling.c \
		rendering.c resource_cleanup.c window_management.c \
		get_next_line.c get_next_line_utils.c tools.c \
		tools_2.c back_tracking_1.c back_tracking_2.c \
		back_tracking_3.c back_tracking_4.c tools_3.c \
		ft_char.c ft_printf.c  ft_string.c \
		ft_hex_1.c ft_hex_2.c ft_int_1.c ft_int_2.c \
		ft_unsigned_1.c ft_unsigned_2.c ft_outils_1.c \
		ft_outils_2.c ft_outils_3.c ft_outils_4.c

OBJ =	$(SRC:.c=.o)
NAME = so_long

CC	= cc
CFLAGS = -Wall -Wextra -Werror -g

GPATH = ./minilibx-linux
MLX_PATH = $(GPATH)/libmlx_Linux.a
CFLAGS += -I$(GPATH) -I./libft -I./gnl -I.
LDFLAGS = -L ./minilibx-linux -lmlx -lX11 -lXext -lm -lbsd 

all : $(NAME)

$(NAME) : _mlx $(OBJ) $(MLX_PATH)
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

_mlx :
	@make -C $(GPATH)
	@make -C $(GPATH) -f Makefile.gen

clean :
	rm -rf $(OBJ)

fclean : clean
	make clean -C $(GPATH)
	rm -rf $(NAME)


re : fclean all

.PHONY : all clean fclean re _mlx
