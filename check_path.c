/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:56:35 by laugarci          #+#    #+#             */
/*   Updated: 2023/01/31 14:35:01 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"

void	ft_copy_map(t_game *game, char **av)
{
	int	fd;
	int	count;
	int	i;
	int	k;

	i = 0;
	k = 0;
	count = game->row;
	fd = open(av[1], O_RDONLY);
	game->map = malloc(sizeof(char) * (game->col) * (game->row));
	while (count > 0)
	{
		game->map[i] = get_next_line(fd);
		count--;
		i++;
	}
	close(fd);
}

int	*ft_start(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (NULL);
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				pos[0] = x;
				pos[1] = y;
				return (pos);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	ft_find_path(t_game *game, int x, int y)
{
	if (game->map[x][y] != '1')
	{
		if (game->map[x][y] == 'E')
			game->ex--;
		if (game->map[x][y] == 'C')
			game->c--;
		game->map[x][y] = '1';
		ft_find_path(game, x, y + 1);
		ft_find_path(game, x, y - 1);
		ft_find_path(game, x + 1, y);
		ft_find_path(game, x - 1, y);
	}
}

void	ft_check_path(t_game *game)
{
	int	*pos;
	int	c;
	int	ex;

	c = game->c;
	ex = game->ex;
	pos = ft_start(game->map);
	ft_find_path(game, pos[0], pos[1]);
	if (game->ex != 0 && game->c != 0)
		write(1, "El mapa no se puede resolver\n", 29);
	game->c = c;
	game->ex = ex;
}
