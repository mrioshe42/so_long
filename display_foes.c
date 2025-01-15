/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_foes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:29:41 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/20 14:33:53 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	display_foes(t_game *game, int frame)
{
	char	*files[3];
	void	*img_ptr;
	int		i;

	files[0] = "textures/C4.xpm";
	files[1] = "textures/C1.xpm";
	files[2] = "textures/C3.xpm";
	img_ptr = mlx_xpm_file_to_image(game->mlx, files[frame],
			&game->img->width, &game->img->height);
	i = 0;
	while (i < game->num_foes)
	{
		mlx_put_image_to_window(game->mlx, game->win, img_ptr,
			game->foes[i].x * PIXEL_SIZE, game->foes[i].y * PIXEL_SIZE);
		i++;
	}
	mlx_destroy_image(game->mlx, img_ptr);
}
