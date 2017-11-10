/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_directly_in_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:40:03 by ggane             #+#    #+#             */
/*   Updated: 2017/11/10 05:59:09 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_dot	*set_isometric_point(int x, int y, int z)
{
	t_dot	*point;

	if (!(point = (t_dot *)malloc(sizeof(t_dot))))
		return (NULL);
	x = set_correct_zoom(x, 'x');
	y = set_correct_zoom(y, 'y');
	z = set_correct_zoom(z, 'z');
	point->x = get_x_for_isometric_projection(x, y);
	point->y = get_y_for_isometric_projection(x, y, z);
	return (point);
}

static int		exist_above_point(int y)
{
	if (y - 1 >= 0)
		return (1);
	else
		return (0);
}

static int		exist_next_point(t_data *data, int x)
{
	if (x < data->x_max - 1)
		return (1);
	else
		return (0);
}

static void		draw_lines(t_data *data, int x, int y)
{
	t_dot		*current_point;
	t_dot		*above_point;
	t_dot		*next_point;

	current_point = set_isometric_point(x, y, data->coordinates[y][x]);
	above_point = NULL;
	next_point = NULL;
	if (exist_above_point(y))
	{
		above_point = set_isometric_point(x, y - 1, \
				data->coordinates[y - 1][x]);
		draw_a_line(data, current_point, above_point);
	}
	if (exist_next_point(data, x))
	{
		next_point = set_isometric_point(x + 1, y, data->coordinates[y][x + 1]);
		draw_a_line(data, current_point, next_point);
	}
	reset_point(&current_point);
	reset_point(&above_point);
	reset_point(&next_point);
}

void			draw_directly_in_window(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->y_max)
	{
		while (x < data->x_max)
			draw_lines(data, x++, y);
		x = 0;
		y++;
	}
	//mlx_key_hook(data->win, print_pressed_key, 0);
	if (escape_key_is_pressed(data))
		return ;
	mlx_loop(data->mlx);
}
