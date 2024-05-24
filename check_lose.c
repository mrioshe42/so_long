#include "so_long.h"

void	lose_banner(void)
{
	ft_printf("█   █ ████ █  █  █    ████  ████  ████\n");
	ft_printf(" █ █  █  █ █  █  █    █  █  █     █   \n");
	ft_printf("  █   █  █ █  █  █    █  █  ████  ████\n");
	ft_printf("  █   █  █ █  █  █    █  █     █  █   \n");
	ft_printf("  █   ████ ████  ████ ████  ████  ████\n");
}

void	check_lose(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->num_foes)
	{
		if (game->player->x == game->foes[i].x
			&& game->player->y == game->foes[i].y)
		{
			mlx_loop_end(game->mlx);
			clean_mlx(game);
			lose_banner();
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}
