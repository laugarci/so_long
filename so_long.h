/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:42:17 by laugarci          #+#    #+#             */
/*   Updated: 2023/01/27 11:53:37 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
typedef struct s_player
{

} player;

typedef struct s_collectibles
{

} col;
*/
typedef struct game_map
{
	char	**map;
	char	*line;
	char	*last_line;
	int		row;
	int		col;
	int		p;
	int		c;
	int		ex;
	int		chr;
}	t_game;

//CHECKS//
void	ft_check_arg(int ac, char **av);
void	ft_open_map(char **av, struct game_map *game);
void	ft_check_letters(char *buf, struct game_map *game);
void	ft_check_limits(char limit);
void	ft_check_map(char *buf, t_game *game);
void	ft_check_last_line(char *limit);
void	ft_copy_map(t_game *game, char **av);

//UTILS//
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen_sl(const char *str);
char	*ft_free_sl(char **pt);

#endif
