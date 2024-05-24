#include "so_long.h"

void	count_items(t_game *game)
{
	if (game->map->data[game->player->y][game->player->x] == 'C')
	{
		game->map->data[game->player->y][game->player->x] = '0';
		game->p_items++;
	}
}

void	update_player_position(t_game *game, int x, int y)
{
	int		next_x;
	int		next_y;
	char	*move_count;

	next_x = game->player->x + x;
	next_y = game->player->y + y;
	if (game->map->data[next_y][next_x] != '1'
			&& game->map->data[next_y][next_x] != 'E')
	{
		count_items(game);
		xpm_to_window(game, "textures/file64.xpm", game->player->x,
			game->player->y);
		game->player->x = next_x;
		game->player->y = next_y;
		mlx_put_image_to_window(game->mlx, game->win, game->player->p_img,
			game->player->x * PIXEL_SIZE, game->player->y * PIXEL_SIZE);
		game->p_moves++;
		xpm_to_window(game, "textures/tree64.xpm", 3, 0);
		move_count = ft_itoa(game->p_moves);
		mlx_string_put(game->mlx, game->win, 200, 30, 0x00FFFFFF,
			move_count);
		free(move_count);
	}
}
