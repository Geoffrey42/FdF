/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:56:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/26 15:54:19 by ggane            ###   ########.fr       */
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
		yn = (((x2 - xn) * (y2 - y1)) / (x2 - x1));
		mlx_pixel_put(mlx, win, xn++, y1 + yn, WHITE);
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

int				main(void)
{
	void	*mlx;
	void	*win1, *win2, *win3, *win4, *win5, *win6, *win7, *win8;

	mlx = mlx_init();
	win1 = mlx_new_window(mlx, 500, 500, "test 1 : ascendante normale");
	win2 = mlx_new_window(mlx, 500, 500, "test 2 : ascendante inverse");
	win3 = mlx_new_window(mlx, 500, 500, "test 3 : descendante normale");
	win4 = mlx_new_window(mlx, 500, 500, "test 4 : descendante inverse");
	win5 = mlx_new_window(mlx, 500, 500, "test 5 : horizontale normale");
	win6 = mlx_new_window(mlx, 500, 500, "test 6 : horizontale inverse");
	win7 = mlx_new_window(mlx, 500, 500, "test 7 : verticale normale");
	win8 = mlx_new_window(mlx, 500, 500, "test 8 : verticale inverse");
	ft_putendl("Test d'une ligne ascendante normale");
	choose_drawing_function(mlx, win1, 40, 140, 190, 70);
	ft_putendl("Test d'une ligne ascendante inverse");
	choose_drawing_function(mlx, win2, 190, 70, 40, 140);
	ft_putendl("Test d'une ligne descendante normale");
	choose_drawing_function(mlx, win3, 40, 70, 190, 140);
	ft_putendl("Test d'une ligne descendante inverse");
	choose_drawing_function(mlx, win4, 190, 140, 40, 70);
	ft_putendl("Test d'une ligne horizontale normale");
	choose_drawing_function(mlx, win5, 40, 140, 190, 140);
	ft_putendl("Test d'une ligne horizontale inverse");
	choose_drawing_function(mlx, win6, 190, 140, 40, 140);
	ft_putendl("Test d'une ligne verticale normale");
	choose_drawing_function(mlx, win7, 190, 70, 190, 140);
	ft_putendl("Test d'une ligne verticale inverse");
	choose_drawing_function(mlx, win8, 190, 140, 190, 70);
	mlx_loop(mlx);
    return (0);
}
