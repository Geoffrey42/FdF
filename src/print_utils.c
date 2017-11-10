/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:48:46 by ggane             #+#    #+#             */
/*   Updated: 2017/11/10 00:58:43 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_one_point(int x, int y, int z)
{
	ft_putstr("x : ");
	ft_putnbrdl(x);
	ft_putstr("y : ");
	ft_putnbrdl(y);
	ft_putstr("z : ");
	ft_putnbrdl(z);
	ft_putendl("-------");
}

void	print_coordinates(t_data *data)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	while (y < data->y_max)
	{
		while (x < data->x_max)
		{
			z = data->coordinates[y][x];
			print_one_point(x, y, z);
			x++;
		}
		x = 0;
		y++;
	}
}
