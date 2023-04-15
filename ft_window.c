/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:38:10 by laugarci          #+#    #+#             */
/*   Updated: 2023/04/15 11:36:55 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

void	ft_putnbr_moves(int moves)
{
	char	c;

	if (moves < 10)
	{
		c = moves + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_moves(moves / 10);
		c = (moves % 10) + 48;
		write(1, &c, 1);
	}
}

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_init, game->mlx_win);
	exit(1);
	return (0);
}

void	ft_put_floor(t_game *game)
{
	game->col_x = 0;
	game->file = mlx_xpm_file_to_image(game->mlx_init, "./sprites/floor.xpm",
			&game->pxl, &game->pxl);
	while (game->col_x < game->col)
	{
		game->row_y = 0;
		while (game->row_y < game->row)
		{
			mlx_put_image_to_window(game->mlx_init, game->mlx_win,
				game->file, (game->pxl * game->col_x), game->pxl * game->row_y);
			game->row_y++;
		}
		game->col_x++;
	}
}

void	ft_put_all(t_game *game)
{
	ft_put_floor(game);
	game->row_y = 0;
	while (game->row_y < game->row)
	{
		game->col_x = 0;
		while (game->col_x < game->col)
		{
			if (game->map[game->row_y][game->col_x] == '1')
				ft_put_limits(game);
			else if (game->map[game->row_y][game->col_x] == 'C')
				ft_put_collect(game);
			else if (game->map[game->row_y][game->col_x] == 'P')
				ft_put_player(game);
			else if (game->map[game->row_y][game->col_x] == 'E')
				ft_put_exit(game);
			game->col_x++;
		}
		game->row_y++;
	}
	write(1, "Movements: ", 11);
	ft_putnbr_moves(game->moves);
	write(1, "\n", 1);
}

void	ft_open_window(t_game *game)
{
	game->pxl = 50;
	game->mlx_init = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_init, game->pxl * game->col,
			game->pxl * game->row, "So_long");
	ft_put_all(game);
}
