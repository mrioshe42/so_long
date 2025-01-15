/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_invalid_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:42:09 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/17 19:43:33 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_invalid_map(t_game *game, char *msg)
{
	ft_printf("Error\n%s\n", msg);
	mlx_loop_end(game->mlx);
	mlx_destroy_image(game->mlx, game->player->p_img);
	game->player->p_img = NULL;
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->img);
	free(game->player);
	free(game->mlx);
	free_map(game);
	free(game->foes);
	exit(EXIT_SUCCESS);
}

void	error_invalid_map_path(t_game *game, char *msg, t_map *map_copy)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		free(map_copy->data[i]);
		i++;
	}
	free(map_copy->data);
	ft_printf("Error\n%s\n", msg);
	mlx_loop_end(game->mlx);
	mlx_destroy_image(game->mlx, game->player->p_img);
	game->player->p_img = NULL;
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->img);
	free(game->player);
	free(game->mlx);
	free_map(game);
	free(game->foes);
	exit(EXIT_SUCCESS);
}
