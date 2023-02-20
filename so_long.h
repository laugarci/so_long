/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:09:41 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/20 16:19:52 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./get_next_line/get_next_line.h"
#include "mlx/mlx.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//KEYS
# define ESC 53
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2

typedef struct game_map
{
	char	**map;
	char	*line;
	char	*last_line;
	char	*file;
	int		row;
	int		col;
	int		row_y;
	int		col_x;
	int		p;
	int		p_x;
	int		p_y;
	int		moves;
	int		c;
	int		ex;
	int		chr;
	int		pxl;
//	int		pos;
	void	*mlx_init;
	void	*mlx_win;
}	t_game;

//CHECKS//
void	ft_check_arg(int ac, char **av);
void	ft_init_var(t_game *game);
void	ft_open_map(char **av, struct game_map *game);
void	ft_check_letters(char *buf, struct game_map *game);
void	ft_check_limits(char limit);
void	ft_check_map(char *buf, t_game *game);
void	ft_check_last_line(char *limit);
void	*ft_copy_map(t_game *game, char **av);
void	ft_check_path(t_game *game);
int		*ft_start(char **map);
void	ft_find_path(t_game *game, int x, int y);

//UTILS//
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen_sl(const char *str);
char	*ft_free_sl(char **pt);

//WINDOW//
void		ft_open_window(t_game *game);
void		ft_put_all(t_game *game);
void		ft_put_floor(t_game *game);
void		ft_put_limits(t_game *game);
void		ft_put_collect(t_game *game);
void		ft_put_player(t_game *game);
void		ft_put_exit(t_game *game);
int			ft_close_window(t_game *game);
int			ft_move(int mov, t_game *game);
void		ft_win(t_game *game);

#endif
