/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_directly_in_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:40:03 by ggane             #+#    #+#             */
/*   Updated: 2017/11/10 03:31:28 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_dot	*set_isometric_point(int x, int y, int z)
{
	t_dot	*point;

	if (!(point = (t_dot *)malloc(sizeof(t_dot))))
		return (NULL);
	x = set_correct_zoom(x, 'x');
	y = set_coorect_zoom(y, 'y');
	z = set_coorect_zoom(z, 'z');
	point->x = get_x_for_isometric_projection(x, y);
	point->y = get_y_for_isometric_projection(x, y, z);
	return (point);
}

int		exist_above_point(int y)
{
	if (y - 1 >= 0)
		return (1);
	else
		return (0);
}

int		exist_next_point(t_data *data, int x)
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
		ft_putendl("gonna draw above line on :");
		above_point = set_isometric_point(x, y - 1, \
				data->coordinates[y - 1][x]);
		print_one_point(x, y, data->coordinates[y][x]);
		draw_a_line(data, current_point, above_point);	
	}
	if (exist_next_point(data, x))
	{
		ft_putendl("gonna draw next line on :");
		next_point = set_isometric_point(x + 1, y, data->coordinates[y][x + 1]);
		print_one_point(x, y, data->coordinates[y][x]);
		draw_a_line(data, current_point, next_point);
	}
	/*
	ft_putendl("current_point :");
	print_2d_point(current_point);
	ft_putendl("above_point :");
	print_2d_point(above_point);
	ft_putendl("next_point :");
	print_2d_point(next_point);
	*/
	reset_point(&current_point);
	reset_point(&above_point);
	reset_point(&next_point);
}

void			draw_directly_in_window(t_data *data)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	ft_putstr("y_max : ");
	ft_putnbrdl(data->y_max);
	ft_putstr("x_max : ");
	ft_putnbrdl(data->x_max);
	while (y < data->y_max)
	{
		while (x < data->x_max)
		{
			draw_lines(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_loop(data->mlx);
}
