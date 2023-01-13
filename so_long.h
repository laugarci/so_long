/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:42:17 by laugarci          #+#    #+#             */
/*   Updated: 2023/01/11 18:27:21 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int		row;
	int		col;
	int		p;
	int		c;
	int		ex;
} t_game;


//CHECKS//
void	ft_check_arg(int ac, char **av);
void	ft_open_map(char **av, struct game_map *game);
void	ft_check_letters(char *buf, struct game_map *game);
//char	*ft_read_map(int fd);


//UTILS//
int		ft_puterror(void);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen_sl(const char *str);
char	*ft_free_sl(char **pt);

#endif
