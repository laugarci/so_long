/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:01:16 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/14 17:16:38 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "so_long.h"
#include "./mlx/mlx.h"

void	ft_win(t_game *game)
{
	int total1;
	int total2;

	total1 = game->pxl * game->row;
	total2 = game->pxl * game->col;
	game->mlx_init = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_init, game->pxl * game->col, game->pxl * game->row, "So_long");
	game->file = mlx_xpm_file_to_image(game->mlx_init, "./sprites/win.xpm", &total1, &total2);
	mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->file, game->pxl * game->col_x, game->pxl * game->row_y);
}*/
