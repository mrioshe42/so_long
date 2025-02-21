/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:19:10 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/20 14:14:21 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	display_counter(t_game *game)
{
	char	*moves_str;

	moves_str = ft_itoa(game->p_moves);
	if (!moves_str)
		return ;
	mlx_set_font(game->mlx, game->win, "9x15");
	mlx_string_put(game->mlx, game->win, 40, 30, 0x00FFFFFF,
		"Number of moves: ");
	mlx_string_put(game->mlx, game->win, 200, 30, 0x00FFFFFF,
		moves_str);
	free(moves_str);
}
