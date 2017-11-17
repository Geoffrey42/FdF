/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:56:01 by ggane             #+#    #+#             */
/*   Updated: 2017/11/17 16:05:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <stdio.h>
#include <math.h>

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

static void		choose_drawing_function(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	if (x1 < x2 && y1 > y2)
	{
		printf("x1 < x2 && y1 > y2\n");
		draw_ascending_line(mlx, win, x1, y1, x2, y2);
	}
	else if (x1 > x2 && y1 < y2)
	{
		printf("x1 > x2 && y1 < y2\n");
		draw_ascending_line(mlx, win, x2, y2, x1, y1);
	}
	else if (x1 < x2 && y1 < y2)
	{
		printf("x1 < x2 && y1 < y2\n");
		draw_descending_line(mlx, win, x1, y1, x2, y2);
	}
	else if (x1 > x2 && y1 > y2)
	{
		printf("x1 > x2 && y1 > y2\n");
		draw_descending_line(mlx, win, x2, y2, x1, y1);
	}
	else if (x1 < x2 && y1 == y2)
	{
		printf("x1 < x2 && y1 == y2\n");
		draw_horizontal_line(mlx, win, x1, y1, x2);
	}
	else if (x1 > x2 && y1 == y2)
	{
		printf("x1 > x2 && y1 == y2\n");
		draw_horizontal_line(mlx, win, x2, y2, x1);
	}
	else if (x1 == x2 && y1 < y2)
	{
		printf("x1 == x2 && y1 < y2\n");
		draw_vertical_line(mlx, win, x1, y1, y2);
	}
	else if (x1 == x2 && y1 > y2)
	{
		printf("x1 == x2 && y1 > y2\n");
		draw_vertical_line(mlx, win, x2, y2, y1);
	}
}

t_dot			*set_isometric_point(int x, int y, int z)
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

int				main(void)
{
	t_dot	*p1;
	t_dot	*p2;
	t_data	*d1 = set_data_structure();
	t_data	*d2 = set_data_structure();
	t_data	*d3 = set_data_structure();
	t_data	*d4 = set_data_structure();
	t_data	*d5 = set_data_structure();
	t_data	*d6 = set_data_structure();
	t_data	*d7 = set_data_structure();
	t_data	*d8 = set_data_structure();

	ft_putendl("Test d'une ligne ascendante normale");
	p1 = set_isometric_point(20, 300, 0);
	p2 = set_isometric_point(40, 35, 10);
	draw_one_line(d1, p1, p2);
	ft_putendl("Test d'une ligne ascendante inverse");
	ft_putendl("Test d'une ligne descendante normale");
	ft_putendl("Test d'une ligne descendante inverse");
	ft_putendl("Test d'une ligne horizontale normale");
	ft_putendl("Test d'une ligne horizontale inverse");
	ft_putendl("Test d'une ligne verticale normale");
	ft_putendl("Test d'une ligne verticale inverse");
	mlx_loop(d1->mlx);
	//reset_point(&p1);
	//reset_point(&p2);
	//delete_data(&d1);
    return (0);
}
