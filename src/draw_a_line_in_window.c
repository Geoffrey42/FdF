/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a_line_in_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:58:13 by ggane             #+#    #+#             */
/*   Updated: 2017/11/07 22:14:27 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_ascending_line(t_data *data, t_dot *p_1, t_dot *p_2)
{
	int		xn;
	int		yn;

	xn = p_1->x;
	yn = p_1->y;
	while (xn <= p_2->x)
	{
		yn = (((xn - p_1->x) * (p_2->y - p_1->y)) / (p_2->x - p_1->x));
		mlx_pixel_put(mlx, win, xn++, p_1->y + yn, WHITE);
	}
}

static void		draw_descending_line(t_data *data, t_dot *p_1, t_dot *p_2)
{
	int		xn;
	int		yn;

	xn = p_1->x;
	yn = p_1->y;
	while (xn <= p_2->x)
	{
		yn = p_2->y - (((p_2->x - xn) * (p_2->y - p_1->y)) / (p_2->x - p_1->x));
		mlx_pixel_put(mlx, win, xn++, yn, WHITE);
	}
}

static void		draw_horizontal_line(t_data *data, t_dot *p_1, int x2)
{
	int		xn;

	xn = p_1->x;
	while (xn <= x2)
		mlx_pixel_put(mlx, win, xn++, p_1->y, WHITE);
}

static void		draw_vertical_line(t_data *data, t_dot *p_1, int y2)
{
	int		yn;

	yn = p_1->y;
	while (yn <= y2)
		mlx_pixel_put(mlx, win, p_1->x, yn++, WHITE);
}

void			draw_a_line(t_data *data, t_dot *start, t_dot *end)
{
	if (start->x < end->x && start->y > end->y)
		draw_ascending_line(data, start, end);
	else if (start->x > end->x && start->y < end->y)
		draw_ascending_line(data, end, start);
	else if (start->x < end->x && start->y < end->y)
		draw_descending_line(data, start, end);
	else if (start->x > end->x && start->y > end->y)
		draw_descending_line(data, end, start);
	else if (start->x < end->x && start->y == end->y)
		draw_horizontal_line(data, start, end->x);
	else if (start->x > end->x && start->y == end->y)
		draw_horizontal_line(data, end, start->x);
	else if (start->x == end->x && start->y < end->y)
		draw_vertical_line(data, start, end->y);
	else if (start->x == end->x && start->y > end->y)
		draw_vertical_line(data, end, start->y);
}
