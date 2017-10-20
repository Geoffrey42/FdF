/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_3d_coordinates_values.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:39:04 by ggane             #+#    #+#             */
/*   Updated: 2017/10/20 14:08:34 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_z_value(char *map, int i)
{
	char	*to_convert;
	int		sign;
	int		z;
	int		j;

	j = 0;
	sign = 1;
	if (i != 0 && map[i - 1] == '-')
		sign = 2;
	if (!(to_convert = (char *)ft_memalloc(sizeof(char) * get_digit_size(\
	map, i) + sign)))
		return (-1);
	if (sign == 2)
		i -= 1;
	while (ft_isdigit(map[i]) || map[i] == '-')
	{
		to_convert[j] = map[i];
		j++;
		i++;
	}
	to_convert[j] = '\0';
	z = ft_atoi(to_convert);
	return (z);
}

int		get_x_value(char *map, int i)
{
	int		j;
	int		x;

	j = 0;
	x = 0;
	while (j != i)
	{
		if (ft_isdigit(map[j]))
		{
			x += 1;
			j = go_to_last_digit(map, j);
		}
		if (map[j] == '\n')
			x = 0;
		j++;
	}
	return (x);
}

int		get_y_value(char *map, int i)
{
	int		j;
	int		y;

	j = 0;
	y = 0;
	while (j != i)
	{
		if (map[j] == '\n')
			y++;
		j++;
	}
	return (y);
}
