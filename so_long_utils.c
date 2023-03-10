/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:45:13 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/21 14:57:05 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
char	*ft_free_sl(char **pt)
{
	int	i;

	i = 0;
	while (pt[i])
		free(pt[i++]);
	free(pt);
	return (NULL);
}*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	c = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && little[j] != '\0' && j + i < len)
			j++;
		while (little[c] != '\0')
			c++;
		if (j == c)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen_sl(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}
