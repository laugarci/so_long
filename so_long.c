/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:41:32 by laugarci          #+#    #+#             */
/*   Updated: 2023/01/30 15:00:16 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "so_long.h"
//#include "so_long_utils.c"
//#include "check_limits.c"
//#include "check_path.c"
//#include "ft_window.c"
#include "./get_next_line/get_next_line.h"

void	ft_check_map(char *buf, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_check_limits(buf[0]); //envia primera columna
	while (buf[i])
	{
		if (buf[i] != '0' && buf[i] != 'P' && buf[i] != 'C' && buf[i] != 'E'
			&& buf[i] != '\n' && buf[i] != '1')
		{
			write(1, "Hay caracteres erroneos en el mapa\n", 35);
			exit(1);
		}
		if (buf[i] == '\n')
			game->row++;
		if (game->row < 1) //envia primera fila
			ft_check_limits(buf[i]);
		game->chr++;
		i++;
	}
	game->col = i - 1;
	i = 0;
	while (buf[i])
		game->last_line[j++] = buf[i++];
}

void	ft_open_map(char **av, t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error de lectura\n", 17);
		exit(1);
	}
	while (fd)
	{	
		game->line = get_next_line(fd);
		if (game->line == NULL)
			break ;
		ft_check_letters(game->line, game);
		ft_check_map(game->line, game);
	}
	ft_check_last_line(game->last_line); //envia la ultima linea
	if (game->p > 1 || game->ex > 1 || game->c < 1)
		write(1, "Faltan elementos en el mapa\n", 28);
	if ((game->col * game->row) != (game->chr - game->row))
		write(1, "El mapa no es valido\n", 21);
	close(fd);
}

void	*ft_init_var(t_game *game)
{
	game->row = 0;
	game->col = 0;
	game->p = 0;
	game->c = 0;
	game->ex = 0;
	game->chr = 0;
	game->line = 0;
	game->last_line = malloc(sizeof(char) * (game->col));
	if (!game->last_line)
		return (NULL);
	return (0);
}

void	ft_check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "Debe haber un archivo .ber\n", 27);
		exit(1);
	}
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".ber", ft_strlen_sl(av[1])))
		{
			write(1, "El archivo debe ser .ber\n", 25);
			exit (1);
		}
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_check_arg(ac, av);
	ft_init_var(&game);
	ft_open_map(av, &game);
	ft_copy_map(&game, av);
	ft_check_path(&game);
	ft_copy_map(&game, av);
	ft_open_window();

	return (0);
}
