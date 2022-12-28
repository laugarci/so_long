/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:45:13 by laugarci          #+#    #+#             */
/*   Updated: 2022/12/16 18:31:25 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free(char **pt)
{
	free(*pt);
	*pt = NULL;
	return (NULL);
}

int		ft_puterror(void)
{
	write(1, "Error\n", 6);
	return (0);
}

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

size_t	ft_strlen(const char *str)
{
	int	c;
	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}
