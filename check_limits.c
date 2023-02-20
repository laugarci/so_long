/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:06 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/20 16:02:48 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	ft_check_letters(char *buf, t_game *game)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == 'P')
			game->p++;
		if (buf[i] == 'C')
			game->c++;
		if (buf[i] == 'E')
			game->ex++;
		i++;
	}
	ft_check_limits(buf[i - 2]);
}

void	ft_check_limits(char limit)
{
	if (limit != '1')
	{
		write(1, "Los limites del mapa no son validos\n", 36);
		return ;
	}
}

void	ft_check_last_line(char *limit)
{
	int	i;
	i = 0;
	while (limit[i] != '\n')
	{
		if (limit[i] != '1')
		{
			write(1, "Los limites del mapa no son validos\n", 39);
			return ;
		}
		i++;
	}
}
