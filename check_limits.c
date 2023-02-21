/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:06 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/21 13:17:57 by laugarci         ###   ########.fr       */
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
		exit(-1);
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
			exit(-1);
		}
		i++;
	}
}

void	ft_check_elements(t_game *game)
{
	if (game->p != 1 || game->ex != 1 || game->c < 1)
	{
		write(1, "Faltan elementos en el mapa\n", 28);
		exit(-1);
	}
	if ((game->col * game->row) != (game->chr - game->row))
	{
		write(1, "El mapa no es valido\n", 21);
		exit(-1);
	}
}

void	*ft_find_last_line(char *buf, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!game->last_line)
	{
		game->last_line = malloc(sizeof(char *) * ((game->col) + 1));
		if (!game->last_line)
			return (NULL);
	}
	while (buf[i])
		game->last_line[j++] = buf[i++];
	return (0);
}
