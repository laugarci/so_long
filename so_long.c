/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:41:32 by laugarci          #+#    #+#             */
/*   Updated: 2023/01/13 20:45:56 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
//#include "so_long_utils.c"
#include "./get_next_line/get_next_line.c"
#include "./get_next_line/get_next_line_utils.c"
//#include "./get_next_line/get_next_line.h"


void	ft_check_letters(char *buf, t_game *game)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == 'P')
			game->p++;
		if (buf[i] == 'C')
			game->c++;
		if (buf[i] == 'E')
			game->ex++;
		if (buf[i] == '\n')
			game->row++;
		i++;
	}
}

void	ft_open_map(char **av, t_game *game)
{
	int		i;
	int 	fd;
//	char	*buf;

	write(1, "entra\n", 6);
	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_puterror();
		exit(1);
	}
//	ft_check_letters(buf, game);
	game->line = get_next_line(fd);
	while (game->map[0][i] != '\0')
	{
		game->col++;
		i++;
	}
//	ft_check_map(buf, game);
	close(fd);
}
void	ft_check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_puterror();
		exit(1);
	}
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".ber", ft_strlen_sl(av[1])))
		{
			ft_puterror();
			exit(1);
		}
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_check_arg(ac, av);
	ft_open_map(av, &game);
	return (0);
}
