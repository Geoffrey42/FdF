/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_directly_in_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:48:40 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 21:48:28 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_directly_in_window(t_data *data)
{
	int		x;
	int		x_2d;
	int		next_x_2d;
	int		y;
	int		y_2d;
	int		next_y_2d;
	int		z;
	int		next_z;

	x = 0;
	y = 0;
	ft_putnbrdl(data->x_max);
	ft_putnbrdl(data->y_max);
	while (y < data->y_max)
	{
		while (x < data->x_max)
		{
			z = data->coordinates[y][x];
			x_2d = get_x_for_isometric_projection(x, y);
			ft_putendl("get_x_for_isometric_projection() for x ok");
			y_2d = get_y_for_isometric_projection(x, y, z);
			ft_putendl("get_y_for_isometric_projection() for y ok");
			if (x + 1 < data->x_max && y + 1 < data->y_max)
			{
				next_z = data->coordinates[y + 1][x + 1];
				next_x_2d = get_x_for_isometric_projection(x + 1, y + 1);
				ft_putendl("get_x_for_isometric_projection() for x + 1 ok");
				next_y_2d = get_y_for_isometric_projection(x + 1, y + 1, next_z);
				ft_putendl("get_y_for_isometric_projection() for y + 1 ok");
			}
			mlx_pixel_put(data->mlx, data->win, x_2d + 50, y_2d + 50, WHITE);
			ft_putendl("mlx_pixel_put() ok");
			//draw_line(x, y, x + 1, y + 1, data);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_loop(data->mlx);
}
