/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_directly_in_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:48:40 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 22:25:11 by ggane            ###   ########.fr       */
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
	while (y < data->y_max)
	{
		while (x < data->x_max)
		{
			z = data->coordinates[y][x];
			x_2d = get_x_for_isometric_projection(x, y);
			y_2d = get_y_for_isometric_projection(x, y, z);
			if (x + 1 < data->x_max && y + 1 < data->y_max)
			{
				next_z = data->coordinates[y + 1][x + 1];
				next_x_2d = get_x_for_isometric_projection(x + 1, y + 1);
				next_y_2d = get_y_for_isometric_projection(x + 1, y + 1, next_z);
			}
			mlx_pixel_put(data->mlx, data->win, (x_2d + 50) * ZOOM, (y_2d + 50) * ZOOM, WHITE);
			//draw_line((x_2d + 75) * ZOOM, (y_2d  + 75) * ZOOM, (next_x_2d + 75) * ZOOM, (next_y_2d + 75) * ZOOM, data);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_loop(data->mlx);
}
