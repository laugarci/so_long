/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:56:17 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/13 20:28:09 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"


int	ft_close_window(t_game *game)
{
   mlx_destroy_window(game->mlx_init, game->mlx_win);
   exit(1);
   return (0);
}


void	ft_fill_floor(t_game *game)
{
	game->col_x = 0;
	while(game->col_x < game->col)
	{
		game->row_y = 0;
		while (game->row_y < game->row)
		{
			game->file = mlx_xpm_file_to_image(game->mlx_init, "./sprites/suelo.xpm", &game->pxl, &game->pxl);
			mlx_put_image_to_window(game->mlx_init, game->mlx_win, game->file, game->pxl * game->col_x, game->pxl * game->row_y);
			game->row_y++;
		}
		game->col_x++;
	}
}

void	ft_fill_window(t_game *game)
{
	ft_fill_floor(game);
	game->row_y = 0;
	while(game->row_y < game->row)
	{
		game->col_x = 0;
		while (game->col_x < game->col)
		{
			if (game->map[game->row_y][game->col_x] == '1')
				ft_put_limits(game);
			if (game->map[game->row_y][game->col_x] == 'C')
				ft_put_collect(game);
			if (game->map[game->row_y][game->col_x] == 'P')
				ft_put_player(game);
			if (game->map[game->row_y][game->col_x] == 'E')
				ft_put_exit(game);
			game->col_x++;
		}
		game->row_y++;
	}
}

void	ft_open_window(t_game *game)
{
	game->pxl = 50;
	game->mlx_init = mlx_init(); //inicia la mlx
	game->mlx_win = mlx_new_window(game->mlx_init, game->pxl * game->col, game->pxl * game->row, "So_long"); //abre una ventana
	ft_fill_window(game);
}
