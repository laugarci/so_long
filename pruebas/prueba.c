/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:09:34 by laugarci          #+#    #+#             */
/*   Updated: 2023/01/17 18:27:48 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "so_long.h"
#include "mlx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

int main(void)
{
	void *mlx;
	t_data img;
	void *mlx_win;
	int i;
	int j;

	i = 404;
	j = 275;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 808, 600, "Prueba");
	img.img = mlx_new_image(mlx, 808, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	while (i > 100)
	{
		mlx_string_put(
		i--;
		j++;
	}

//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
