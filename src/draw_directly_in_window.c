/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_directly_in_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:40:03 by ggane             #+#    #+#             */
/*   Updated: 2017/10/26 16:29:25 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_ascending_line(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	int		xn, yn;

	xn = x1;
	yn = y1;
	while (xn <= x2)
	{
		yn = (((xn - x1) * (y2 - y1)) / (x2 - x1));
		mlx_pixel_put(mlx, win, xn++, y1 + yn, WHITE);
	}
}

static void		draw_descending_line(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	int		xn, yn;

	xn = x1;
	yn = y1;
	while (xn <= x2)
	{
		yn = y2 - (((x2 - xn) * (y2 - y1)) / (x2 - x1));
		mlx_pixel_put(mlx, win, xn++, yn, WHITE);
	}
}

static void		draw_horizontal_line(void *mlx, void *win, int x1, int y1, int x2)
{
	int		xn;

	xn = x1;
	while (xn <= x2)
		mlx_pixel_put(mlx, win, xn++, y1, WHITE);
}

static void		draw_vertical_line(void *mlx, void *win, int x1, int y1, int y2)
{
	int		yn;

	yn = y1;
	while (yn <= y2)
		mlx_pixel_put(mlx, win, x1, yn++, WHITE);
}

static void		draw_straigh_lines(t_data *data, int x1, int y1, int x2, int y2)
{
	if (x1 < x2 && y1 > y2)
		draw_ascending_line(data->mlx, data->win, x1, y1, x2, y2);
	else if (x1 > x2 && y1 < y2)
		draw_ascending_line(data->mlx, data->win, x2, y2, x1, y1);
	else if (x1 < x2 && y1 < y2)
		draw_descending_line(data->mlx, data->win, x1, y1, x2, y2);
	else if (x1 > x2 && y1 > y2)
		draw_descending_line(data->mlx, data->win, x2, y2, x1, y1);
	else if (x1 < x2 && y1 == y2)
		draw_horizontal_line(data->mlx, data->win, x1, y1, x2);
	else if (x1 > x2 && y1 == y2)
		draw_horizontal_line(data->mlx, data->win, x2, y2, x1);
	else if (x1 == x2 && y1 < y2)
		draw_vertical_line(data->mlx, data->win, x1, y1, y2);
	else if (x1 == x2 && y1 > y2)
		draw_vertical_line(data->mlx, data->win, x2, y2, y1);
}

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
			//mlx_pixel_put(data->mlx, data->win, (x_2d + 50) * ZOOM, (y_2d + 50) * ZOOM, WHITE);
			draw_straigh_lines(data, (x_2d + 75) * ZOOM, (y_2d  + 75) * ZOOM, (next_x_2d + 75) * ZOOM, (next_y_2d + 75) * ZOOM);
			x++;
		}
		x = 0;
		y++;
	}	
	mlx_loop(data->mlx);
}
