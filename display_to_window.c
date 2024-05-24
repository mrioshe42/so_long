#include "so_long.h"

void	put_to_map(t_game *game, char c)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->data[y][x] == c)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->img_ptr, x * PIXEL_SIZE, y * PIXEL_SIZE);
			}
			x++;
		}
		y++;
	}
}

void	xpm_to_window(t_game *game, char *file, int x, int y)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx, file,
			&game->img->width, &game->img->height);
	mlx_put_image_to_window(game->mlx, game->win,
		img_ptr, x * PIXEL_SIZE, y * PIXEL_SIZE);
	mlx_destroy_image(game->mlx, img_ptr);
}

void	display_border(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->data[y][x] == '1')
			{
				if (x == 0 || y == 0 || x == game->map->width - 1
					|| y == game->map->height - 1)
					xpm_to_window(game, "textures/tree64.xpm", x, y);
				else
					xpm_to_window(game, "textures/wallRock64.xpm", x, y);
			}
			x++;
		}
		y++;
	}
}

void	load_image(t_game *game, void **img_ptr, const char *file)
{
	if (*img_ptr)
	{
		mlx_destroy_image(game->mlx, *img_ptr);
		*img_ptr = NULL;
	}
	*img_ptr = mlx_xpm_file_to_image(game->mlx, (char *)file,
			&game->img->width, &game->img->height);
}

void	display_background_and_items(t_game *game)
{
	load_image(game, &game->img->img_ptr, "textures/file64.xpm");
	put_to_map(game, '0');
	load_image(game, &game->img->img_ptr, "textures/apple64.xpm");
	put_to_map(game, 'C');
	load_image(game, &game->img->img_ptr, "textures/ExitC64.xpm");
	put_to_map(game, 'E');
}
