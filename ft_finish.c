/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:21:24 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/21 13:24:24 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

void	ft_finish(t_game *game)
{
	int	i;

	i = 0;
	write(1, "WIN!\n", 4);
	while (i < game->row)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	ft_close_window(game);
}
