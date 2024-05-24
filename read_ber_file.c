#include "so_long.h"

void	init_map_row(t_game *game, int y)
{
	int	i;

	i = 0;
	game->map->data[y] = malloc(sizeof(char) * (game->map->width + 1));
	if (!game->map->data[y])
	{
		while (i < game->map->height)
		{
			free(game->map->data[i]);
			i++;
		}
		free(game->map->data);
		exit(EXIT_FAILURE);
	}
	ft_memset(game->map->data[y], 0, game->map->width + 1);
}

void	handle_foe(t_game *game, int x, int y)
{
	t_foe	*new_foes;
	int		i;

	i = 0;
	new_foes = malloc(sizeof(t_foe) * (game->num_foes + 1));
	if (!new_foes)
	{
		free(game->foes);
		exit(EXIT_FAILURE);
	}
	while (i < game->num_foes)
	{
		new_foes[i] = game->foes[i];
		i++;
	}
	new_foes[game->num_foes].x = x;
	new_foes[game->num_foes].y = y;
	game->num_foes++;
	free(game->foes);
	game->foes = new_foes;
}

void	handle_character(t_game *game, char buffer, int x, int y)
{
	if (buffer == 'P')
	{
		game->player->x = x;
		game->player->y = y;
		game->player->p_img = mlx_xpm_file_to_image(game->mlx,
				"textures/C1.xpm", &game->player->width, &game->player->height);
		mlx_put_image_to_window(game->mlx, game->win, game->player->p_img,
			game->player->x * PIXEL_SIZE, game->player->y * PIXEL_SIZE);
	}
	else if (buffer == 'C')
		game->num_items++;
	else if (buffer == 'F')
		handle_foe(game, x, y);
	else if (buffer == 'E')
	{
		game->x_exit = x;
		game->y_exit = y;
	}
}

void	read_ber_file(char *file, t_game *game)
{
	int		fd;
	char	buffer;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
		{
			x = 0;
			y++;
			continue ;
		}
		if (x == 0)
			init_map_row(game, y);
		handle_character(game, buffer, x, y);
		game->map->data[y][x] = buffer;
		x++;
	}
	close(fd);
}
