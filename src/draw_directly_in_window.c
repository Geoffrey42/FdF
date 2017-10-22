/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_directly_in_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:48:40 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 20:30:11 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_directly_in_window(t_data *data)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	ft_putstr("x_max : ");
	ft_putnbrdl(data->x_max);
	ft_putstr("y_max : ");
	ft_putnbrdl(data->y_max);
	while (y < data->y_max)
	{
		while (x < data->x_max)
		{
			z = data->coordinates[y][x];
			mlx_pixel_put(data->mlx, data->win, x, y, WHITE);
			//draw_line(x, y, x + 1, y + 1, data);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_loop(data->mlx);
}
