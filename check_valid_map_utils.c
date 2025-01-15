/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:05:10 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/17 18:00:49 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_components_map(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			c = game->map->data[i][j];
			if (c != '0' && (c != '1' && (c != 'C' && (c != 'E'
							&& (c != 'P' && c != 'F')))))
				error_invalid_map(game, "Inalid component in map!");
			j++;
		}
		i++;
	}
}

void	count_components(t_game *game, int *e_num, int *c_num, int *p_num)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->data[i][j] == 'E')
				(*e_num)++;
			else if (game->map->data[i][j] == 'C')
				(*c_num)++;
			else if (game->map->data[i][j] == 'P')
				(*p_num)++;
			j++;
		}
		i++;
	}
}

int	check_num_components(t_game *game)
{
	int	e_num;
	int	c_num;
	int	p_num;

	e_num = 0;
	c_num = 0;
	p_num = 0;
	count_components(game, &e_num, &c_num, &p_num);
	return (e_num == 1 && (c_num >= 1 && p_num == 1));
}

void	check_border(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (x < game->map->width)
	{
		if (game->map->data[0][x] != '1' ||
			game->map->data[game->map->height - 1][x] != '1')
			error_invalid_map(game, "Invalid border for map!");
		x++;
	}
	y = 1;
	while (y < game->map->height - 1)
	{
		if (game->map->data[y][0] != '1' ||
			game->map->data[y][game->map->width - 1] != '1')
			error_invalid_map(game, "Invalid border for map!");
		y++;
	}
}

bool	check_valid_path(t_game *game, t_map *map_copy, int y, int x)
{
	char	current_char;
	bool	found_path;

	current_char = map_copy->data[y][x];
	if (current_char == 'E')
		return (true);
	if (current_char != 'C' && (current_char != 'P' && current_char != '0'))
		return (false);
	map_copy->data[y][x] = 'V';
	found_path = check_valid_path(game, map_copy, y, x + 1)
		|| check_valid_path(game, map_copy, y, x - 1)
		|| check_valid_path(game, map_copy, y + 1, x)
		|| check_valid_path(game, map_copy, y - 1, x);
	return (found_path);
}
