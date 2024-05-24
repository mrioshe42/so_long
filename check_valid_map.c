#include "so_long.h"

void	check_valid_map_two(t_game *game, t_map *map_copy)
{
	check_components_map(game);
	if (!check_num_components(game))
		error_invalid_map(game, "Invalid num components in map!");
	if (game->map->height >= game->map->width)
		error_invalid_map(game, "Map not rectangular!");
	if (!check_valid_path(game, map_copy, game->player->y, game->player->x))
		error_invalid_map_path(game, "Invalid path in map!", map_copy);
	check_border(game);
}

void	check_valid_map(t_game *game)
{
	t_map	map_copy;
	int		i;

	i = 0;
	map_copy.width = game->map->width;
	map_copy.height = game->map->height;
	map_copy.data = malloc(sizeof(char *) * game->map->height);
	while (i < game->map->height)
	{
		map_copy.data[i] = ft_strdup(game->map->data[i]);
		if (!map_copy.data[i])
			perror("Failed to duplicate row");
		i++;
	}
	check_valid_map_two(game, &map_copy);
	i = 0;
	while (i < game->map->height)
	{
		free(map_copy.data[i]);
		i++;
	}
	free(map_copy.data);
}
