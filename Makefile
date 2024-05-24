NAME = so_long

CC = cc

FLAGS = -Wall -Werror -Wextra

MLXFLAGS = -L ./minilibx-linux -lmlx_Linux -lXext -lX11

LIBFT = ./Libft/libft.a

LIBFTDIR = ./Libft

MINILIBX_PATH = minilibx-linux

MINILIBX = $(MINILIBX_PATH)/libmlx.a

SRC = check_exit.c check_lose.c check_valid_map.c check_valid_map_utils.c \
      display_animation.c display_counter.c display_foes.c display_to_window.c \
      error_invalid_map.c free_map.c ft_strcat.c ft_strcpy.c get_next_line.c \
      handle_input.c init_map.c init_struct.c main.c player_animation.c \
      read_ber_file.c update_enemy_position.c update_player_position.c

OBJ = $(SRC:%.c=%.o)

all: ${NAME}

${NAME}: $(OBJ)
	$(MAKE) -C $(MINILIBX_PATH)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(FLAGS) -lm $(SRC) $(MLXFLAGS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./Libft
	$(MAKE) clean -C ./minilibx-linux
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./Libft
	@rm -rf $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
