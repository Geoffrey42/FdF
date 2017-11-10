/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:48:46 by ggane             #+#    #+#             */
/*   Updated: 2017/11/10 05:37:11 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_pressed_key(int keycode, void *param)
{
	(void)param;
	ft_putstr("pressed key is : ");
	ft_putnbrdl(keycode);
	ft_putendl("--------");
	return (keycode);
}

void	print_2d_point(t_dot *point)
{
	if (point)
	{
		ft_putstr("x : ");
		ft_putnbrdl(point->x);
		ft_putstr("y : ");
		ft_putnbrdl(point->y);
	}
	else
		ft_putendl("NULL");
	ft_putendl("-------");
}

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
