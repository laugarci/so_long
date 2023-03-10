/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:36:15 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/22 12:43:48 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

void	ft_put_limits(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx_init,
			"./sprites/toy.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx_init, game->mlx_win,
		game->file, (game->pxl * game->col_x), (game->pxl * game->row_y));
}

void	ft_put_collect(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx_init,
			"./sprites/bottle.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx_init, game->mlx_win,
		game->file, (game->pxl * game->col_x), (game->pxl * game->row_y));
}

void	ft_put_player(t_game *game)
{
	if (game->direction == 0)
		game->file = mlx_xpm_file_to_image(game->mlx_init,
				"./sprites/down.xpm", &game->pxl, &game->pxl);
	else if (game->direction == 1)
		game->file = mlx_xpm_file_to_image(game->mlx_init,
				"./sprites/up.xpm", &game->pxl, &game->pxl);
	else if (game->direction == 2)
		game->file = mlx_xpm_file_to_image(game->mlx_init,
				"./sprites/left.xpm", &game->pxl, &game->pxl);
	else if (game->direction == 3)
		game->file = mlx_xpm_file_to_image(game->mlx_init,
				"./sprites/right.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx_init, game->mlx_win,
		game->file, (game->pxl * game->col_x), (game->pxl * game->row_y));
	game->p_y = game->row_y;
	game->p_x = game->col_x;
}

void	ft_put_exit(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx_init,
			"sprites/baby_stroller.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->file,
		(game->pxl * game->col_x), (game->pxl * game->row_y));
}
