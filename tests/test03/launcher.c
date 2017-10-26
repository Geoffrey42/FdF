/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:56:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/26 13:44:58 by ggane            ###   ########.fr       */
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
	ft_putendl("Test draw_ascending_line()");
	printf("yn : %d\ny2 : %d\n------------\n", yn, y2);
	while (xn <= x2)
	{
		yn = (((xn - x1) * (y2 - y1)) / (x2 - x1));
		//printf("yn : %d\n", yn);
		mlx_pixel_put(mlx, win, xn++, y1 + yn, WHITE);
	}
}

int				main(void)
{
	void	*mlx;
	void	*win1;
	int		x1, y1, x2, y2;

	x2 = 40;
	y2 = 140;
	x1 = 190;
	y1 = 70;
	mlx = mlx_init();
	win1 = mlx_new_window(mlx, 1000, 1000, "test 1");
	if (x1 < x2 && y1 > y2)
	{
		printf("x1 < x2 && y1 > y2\n");
		draw_ascending_line(mlx, win1, x1, y1, x2, y2);
	}
	else if (x1 > x2 && y1 < y2)
	{
		printf("x1 > x2 && y1 < y2\n");
		draw_ascending_line(mlx, win1, x2, y2, x1, y1);
	}
	mlx_loop(mlx);
    return (0);
}
