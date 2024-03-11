NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude
FRAMEWORK = -framework Cocoa -framework OpenGL -framework IOKit
LGLFW = -lglfw -L"/Users/saroca-f/.brew/opt/glfw/lib/"
MLX_PATH = ./MLX42
MLX = $(MLX_PATH)/libmlx42.a
PRINTF_PATH = ./printf
PRINT = $(PRINTF_PATH)/libftprintf.a

SRCS = 	so_long.c \
		so_long_utils.c \
		so_long_utils2.c \
		game.c \
		game_define.c \
		games_utils.c \
		key_moves.c \
		split.c \
		split_tools.c \
		get_next_line.c \
		get_next_line_utils.c \
		./check_map/check_map.c \
		./check_map/check_map_utils.c \
		./check_map/check_map_utils2.c \
		./check_map/error_exit.c \

SRCS_BONUS = so_long.c \
			so_long_utils.c \
			so_long_utils2.c \
			./bonus/game_bonus.c \
			game_define.c \
			./bonus/games_utils_bonus.c \
			./bonus/key_moves_bonus.c \
			./bonus/game_p_moves.c \
			./bonus/ft_itoa.c \
			split.c \
			split_tools.c \
			get_next_line.c \
			get_next_line_utils.c \
			./check_map/check_map.c \
			./check_map/check_map_utils.c \
			./check_map/check_map_utils2_bonus.c \
			./check_map/error_exit.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(MLX) $(PRINT)
	$(CC) $(CFLAGS) $(LGLFW) $(FRAMEWORK) $(OBJS) $(MLX) $(PRINT) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(MLX) $(PRINT)
	$(CC) $(CFLAGS) $(LGLFW) $(FRAMEWORK) $(OBJS_BONUS) $(MLX) $(PRINT) -o $(NAME_BONUS)

$(MLX):
	make -C $(MLX_PATH) all

$(PRINT):
	make -C $(PRINTF_PATH) all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(MLX_PATH) clean
	make -C $(PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(MLX_PATH) fclean
	make -C $(PRINTF_PATH) fclean

re : fclean all

.PHONY : all clean fclean re
