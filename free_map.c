/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:39:23 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/17 19:41:22 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map && game->map->data)
	{
		while (i < game->map->height)
		{
			if (game->map->data[i])
				free(game->map->data[i]);
			i++;
		}
		free(game->map->data);
	}
	free(game->map);
}

void	free_stuff(t_game *game)
{
	free(game->img->img_ptr);
	if (game->img)
		free(game->img);
	if (game->img && game->img->img_ptr)
	{
		mlx_destroy_image(game->mlx, game->img->img_ptr);
		game->img->img_ptr = NULL;
	}
	if (game->foes)
	{
		free(game->foes);
		game->foes = NULL;
	}
	if (game->player)
	{
		if (game->player->p_img)
			mlx_destroy_image(game->mlx, game->player->p_img);
		free(game->player);
	}
	clean_mlx(game);
	free_map(game);
}
