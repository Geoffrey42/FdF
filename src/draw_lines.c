/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:19:48 by ggane             #+#    #+#             */
/*   Updated: 2017/11/19 23:33:13 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> // to delete

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

void			draw_lines(t_data *data, int x, int y)
{
	t_dot		*current_point;
	t_dot		*above_point;
	t_dot		*next_point;

	current_point = set_isometric_point(x, y, data->coordinates[y][x]);
	above_point = NULL;
	next_point = NULL;
	printf("x1 : %d - y1 : %d - z1 : %d\n", x, y, data->coordinates[y][x]);
	if (exist_above_point(y))
	{
		above_point = set_isometric_point(x, y - 1, \
				data->coordinates[y - 1][x]);
		printf("above point : x2 : %d - y2 : %d - z2 : %d\n", x, y - 1, data->coordinates[y - 1][x]);
		draw_one_line(data, current_point, above_point);
	}
	if (exist_next_point(data, x))
	{
		next_point = set_isometric_point(x + 1, y, data->coordinates[y][x + 1]);
		printf("next point : x3 : %d - y3 : %d - z3 : %d\n", x + 1, y, data->coordinates[y][x + 1]);
		draw_one_line(data, current_point, next_point);
	}
	ft_putendl("-----------------------------------------------");
	reset_point(&current_point);
	reset_point(&above_point);
	reset_point(&next_point);
}
