/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:49:49 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/22 12:52:03 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
