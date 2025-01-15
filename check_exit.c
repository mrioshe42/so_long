/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:44:36 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/17 19:48:21 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	win_banner(void)
{
	ft_printf("█   █ ████ █  █  █       █ █ ██  █\n");
	ft_printf(" █ █  █  █ █  █   █     █  █ █ █ █\n");
	ft_printf("  █   █  █ █  █    █ █ █   █ █  ██\n");
	ft_printf("  █   ████ ████     █ █    █ █   █\n");
}

void	open_exit(t_game *game)
{
	void	*img_ptr;

	game->exit = true;
	img_ptr = mlx_xpm_file_to_image(game->mlx, "textures/ExitO64.xpm",
			&game->img->width, &game->img->height);
	mlx_put_image_to_window(game->mlx, game->win, img_ptr,
		game->x_exit * PIXEL_SIZE, game->y_exit * PIXEL_SIZE);
	mlx_destroy_image(game->mlx, img_ptr);
	game->map->data[game->y_exit][game->x_exit] = 'C';
}

void	check_exit(t_game *game)
{
	if (game->p_items == game->num_items && !game->exit)
		open_exit(game);
	if (game->player->x == game->x_exit && game->player->y == game->y_exit)
	{
		mlx_loop_end(game->mlx);
		clean_mlx(game);
		win_banner();
		exit(EXIT_SUCCESS);
	}
}
