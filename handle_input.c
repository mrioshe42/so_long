#include "so_long.h"

void	clean_mlx(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img_ptr);
	game->img->img_ptr = NULL;
	mlx_destroy_image(game->mlx, game->player->p_img);
	game->player->p_img = NULL;
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->img);
	free(game->player);
	free(game->mlx);
	free_map(game);
	free(game->foes);
}

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx);
	clean_mlx(game);
	exit(EXIT_SUCCESS);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == 65307)
	{
		mlx_loop_end(game->mlx);
		clean_mlx(game);
		exit(EXIT_SUCCESS);
	}
	else if (keysym == 100)
		update_player_position(game, 1, 0);
	else if (keysym == 97)
		update_player_position(game, -1, 0);
	else if (keysym == 119)
		update_player_position(game, 0, -1);
	else if (keysym == 115)
		update_player_position(game, 0, 1);
	return (0);
}
