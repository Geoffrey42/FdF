/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_directly_in_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:40:03 by ggane             #+#    #+#             */
/*   Updated: 2017/11/07 22:25:16 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_dot	*set_point(int x, int y)
{
	t_dot	*point;

	if (!(point = (t_dot *)malloc(sizeof(t_dot))))
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

int		exist_above_point(t_data *data, t_dot *point)
{
	if (data->coord[point->y][point->x - data->x_max])
		return (1);
	else
		return (0);
}

int		exist_next_point(t_data *data, t_dot *point)
{
	if (data->coord[point->y][point->x + 1])
		return (1);
	else
		return (0);
}

static void		draw_lines(t_data *data, t_dot *current_point)
{
	t_dot		*above_point;
	t_dot		*next_point;

	if (exist_above_point(data, current_point))
	{
		above_point = set_point(current_point->x - data->x_max, \
				current_point->y);
		draw_a_line(data, current_point, above_point);	
	}
	if (exist_next_point(data, current_point))
	{
		next_point = set_point(current_point->x + 1, current_point->y);
		draw_a_line(data, current_point, next_point);
	}
	reset_point(&above_point);	
	reset_point(&next_point);	
}

void			draw_directly_in_window(t_data *data)
{
	t_dot		*current;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < data->y_max)
	{
		while (x < data->x_max)
		{
			current = set_point(x, y);
			draw_lines(data, current);
			reset_point(&current);
		}
		x = 0;
		y++;
	}
	mlx_loop(data->mlx);
}
