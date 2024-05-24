#include "so_long.h"

int	display_animation(t_game *game)
{
	static int	i = 0;
	int			j;

	j = 0;
	check_exit(game);
	check_lose(game);
	player_animation(game, i);
	display_foes(game, i);
	mlx_do_sync(game->mlx);
	usleep(120000);
	if (i % 3 == 0)
	{
		while (j < game->num_foes)
		{
			xpm_to_window(game, "textures/file64.xpm",
				game->foes[j].x, game->foes[j].y);
			j++;
		}
		update_enemy_position(game);
	}
	i = (i + 1) % 3;
	return (1);
}
