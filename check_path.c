/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:56:35 by laugarci          #+#    #+#             */
/*   Updated: 2023/01/27 12:33:46 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./get_next_line/get_next_line.h"

void	ft_copy_map(t_game *game, char **av)
{
	int fd;
	int count;
	int i;
	int k;

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
}


