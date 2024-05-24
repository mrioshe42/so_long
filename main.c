#include "so_long.h"

void	display_intro(t_game *game)
{
	char	filename[64];
	char	*num_str;
	int		i;
	void	*img_ptr;

	i = 0;
	game->win = mlx_new_window(game->mlx, 502, 502, "Intro");
	while (i < 94)
	{
		i++;
		num_str = ft_itoa(i);
		ft_strcpy(filename, "introXPM/intro");
		ft_strcat(filename, num_str);
		ft_strcat(filename, ".xpm");
		free(num_str);
		img_ptr = mlx_xpm_file_to_image(game->mlx, filename,
				&game->img->width, &game->img->height);
		mlx_put_image_to_window(game->mlx, game->win, img_ptr, 0, 0);
		mlx_destroy_image(game->mlx, img_ptr);
		usleep(80000);
	}
	usleep(3000000);
	mlx_destroy_window(game->mlx, game->win);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Compile: ./so_long <map.ber>");
		exit(EXIT_FAILURE);
	}
	init_struct(&game);
	init_map(argv[1], &game);
	game.mlx = mlx_init();
	display_intro(&game);
	game.win = mlx_new_window(game.mlx, game.map->width * PIXEL_SIZE,
			game.map->height * PIXEL_SIZE, "so_long");
	inti_map_data(&game);
	read_ber_file(argv[1], &game);
	check_valid_map(&game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	display_background_and_items(&game);
	display_border(&game);
	display_counter(&game);
	mlx_loop_hook(game.mlx, (void *)display_animation, &game);
	mlx_loop(game.mlx);
	free_stuff(&game);
	return (0);
}
