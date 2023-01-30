/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abre_ventana.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:09:34 by laugarci          #+#    #+#             */
/*   Updated: 2023/01/30 13:10:57 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

int main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 640, "Prueba");
	mlx_loop(mlx);
}
