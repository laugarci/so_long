/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:06 by laugarci          #+#    #+#             */
/*   Updated: 2023/01/19 16:33:50 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	ft_check_limits(char limit)
{
//	printf("%c\n", limit);
	if (limit != '1')
		write(1, "Los limites del mapa no son validos\n", 36);
}
