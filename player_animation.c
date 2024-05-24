#include "so_long.h"

void	player_animation(t_game *game, int i)
{
	char	*files[3];
	void	*new_img;

	files[0] = "textures/P164.xpm";
	files[1] = "textures/P364.xpm";
	files[2] = "textures/P264.xpm";
	new_img = mlx_xpm_file_to_image(game->mlx, files[i],
			&game->player->width, &game->player->height);
	mlx_put_image_to_window(game->mlx, game->win, new_img,
		game->player->x * PIXEL_SIZE, game->player->y * PIXEL_SIZE);
	if (game->player->p_img)
	{
		mlx_destroy_image(game->mlx, game->player->p_img);
		game->player->p_img = NULL;
	}
	game->player->p_img = new_img;
}
