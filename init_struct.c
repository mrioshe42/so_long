#include "so_long.h"

void	init_variables(t_game *game)
{
	game->foes = NULL;
	game->player->p_img = NULL;
	game->img->img_ptr = NULL;
	game->num_foes = 0;
	game->p_moves = 0;
	game->num_items = 0;
	game->p_items = 0;
	game->x_exit = 0;
	game->y_exit = 0;
}

void	init_struct(t_game *game)
{
	game->exit = false;
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		exit(EXIT_FAILURE);
	}
	game->img = malloc(sizeof(t_img));
	if (!game->img)
	{
		free(game->map);
		exit(EXIT_FAILURE);
	}
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		free(game->img);
		free(game->map);
		exit(EXIT_FAILURE);
	}
	init_variables(game);
}

void	inti_map_data(t_game *game)
{
	int	i;

	i = 0;
	game->map->data = malloc(sizeof(char *) * game->map->height);
	if (!game->map->data)
	{
		free(game->map);
		exit(EXIT_FAILURE);
	}
	while (i < game->map->height)
	{
		game->map->data[i] = NULL;
		i++;
	}
}
