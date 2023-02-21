/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:10:17 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/21 12:06:51 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

void	ft_move_up(t_game *game)
{
	game->map[game->p_y][game->p_x] = '0';
	if (game->map[game->p_y - 1][game->p_x] == 'C')
		game->c--;
	game->map[game->p_y - 1][game->p_x] = 'P';
	game->moves++;
	game->direction = 1;
}

void	ft_move_down(t_game *game)
{
	game->map[game->p_y][game->p_x] = '0';
	if (game->map[game->p_y + 1][game->p_x] == 'C')
		game->c--;
	game->map[game->p_y + 1][game->p_x] = 'P';
	game->moves++;
	game->direction = 0;
}

void	ft_move_left(t_game *game)
{
	game->map[game->p_y][game->p_x] = '0';
	if (game->map[game->p_y][game->p_x - 1] == 'C')
		game->c--;
	game->map[game->p_y][game->p_x - 1] = 'P';
	game->moves++;
	game->direction = 2;
}

void	ft_move_right(t_game *game)
{
	game->map[game->p_y][game->p_x] = '0';
	if (game->map[game->p_y][game->p_x + 1] == 'C')
		game->c--;
	game->map[game->p_y][game->p_x + 1] = 'P';
	game->moves++;
	game->direction = 3;
}

int	ft_move(int mov, t_game *game)
{
	int i;

	i = 0;
	if (mov == ESC)
		ft_close_window(game);
	if (game->c == 0 && ((mov == RIGHT && game->map[game->p_y][game->p_x + 1] == 'E')
			|| (mov == DOWN && game->map[game->p_y + 1][game->p_x] == 'E')
			|| (mov == LEFT && game->map[game->p_y][game->p_x - 1] == 'E')
			|| (mov == UP && game->map[game->p_y - 1][game->p_x] == 'E')))
	{
		write(1, "WIN!\n", 4);
		while (i < game->row)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		ft_close_window(game);
	}
	if (mov == UP && game->map[game->p_y - 1][game->p_x] != '1'
			&& game->map[game->p_y - 1][game->p_x] != 'E')
		ft_move_up(game);
	if (mov == LEFT && game->map[game->p_y][game->p_x - 1] != '1'
			&& game->map[game->p_y][game->p_x - 1] != 'E')
		ft_move_left(game);
	if (mov == DOWN && game->map[game->p_y + 1][game->p_x] != '1'
		&& game->map[game->p_y + 1][game->p_x] != 'E')
		ft_move_down(game);
	if (mov == RIGHT && game->map[game->p_y][game->p_x + 1] != '1'
			&& game->map[game->p_y][game->p_x + 1] != 'E')
		ft_move_right(game);
	ft_put_all(game);
	return (0);
}
