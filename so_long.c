/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:41:32 by laugarci          #+#    #+#             */
/*   Updated: 2022/12/19 15:46:13 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.c"

void	ft_check_letters(char *buf, game *game)
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

void	ft_read_map(int fd)
{
	char	*buf;
	int		rdbytes;
		
	rdbytes = 1;
	while (rdbytes > 0)
	{
		rdbytes = read(fd, buf, 1);
		if (rdbytes > 0)
	}
}

void	ft_open_map(char *av, t_game *game)
{
	int		i;
	int 	fd;
	char	*buf;

	i = 0;
	fd = open(&av[1], O_RDONLY);
	if (fd < 1)
	{
		ft_puterror();
		exit(1);
	}
	buf = ft_read_map(fd);
	ft_check_letters(buf, game);
	game->map = get_next_line(buf);
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
	int	i;
	int len;

	i = 0;
	len = 0;
	if (ac != 2)
	{
		ft_puterror();
		exit(1);
	}
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
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
	ft_open_map(av, &game)
	return (0);
}
