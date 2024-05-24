#include "so_long.h"

t_directions	get_random_direction(void)
{
	return ((t_directions)(rand() % NUM_DIRECTIONS));
}

void	calculate_next_position(int *next_x, int *next_y, t_directions dir)
{
	if (dir == LEFT)
		(*next_x) -= 1;
	else if (dir == RIGHT)
		(*next_x) += 1;
	else if (dir == UP)
		(*next_y) -= 1;
	else if (dir == DOWN)
		(*next_y) += 1;
}

void	update_enemy_position(t_game *game)
{
	int				i;
	int				next_x;
	int				next_y;
	t_directions	dir;

	i = 0;
	while (i < game->num_foes)
	{
		dir = get_random_direction();
		next_x = game->foes[i].x;
		next_y = game->foes[i].y;
		calculate_next_position(&next_x, &next_y, dir);
		if (game->map->data[next_y][next_x] != '1'
				&& (game->map->data[next_y][next_x] != 'C'
				&& (game->map->data[next_y][next_x] != 'E')))
		{
			game->foes[i].x = next_x;
			game->foes[i].y = next_y;
		}
		i++;
	}
}
