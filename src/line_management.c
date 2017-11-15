/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:21:13 by ggane             #+#    #+#             */
/*   Updated: 2017/11/15 19:22:43 by ggane            ###   ########.fr       */
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
		yn = p_1->y + (((xn - p_1->x) * (p_2->y - p_1->y)) / (p_2->x - p_1->x));
		data->pixel_function(data, xn++, yn);
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
		data->pixel_function(data, xn++, yn);
	}
}

static void		draw_horizontal_line(t_data *data, t_dot *p_1, int x2)
{
	int		xn;

	xn = p_1->x;
	while (xn <= x2)
		data->pixel_function(data, xn++, p_1->y);
}

static void		draw_vertical_line(t_data *data, t_dot *p_1, int y2)
{
	int		yn;

	yn = p_1->y;
	while (yn <= y2)
		data->pixel_function(data, p_1->x, yn++);
}

void			draw_one_line(t_data *data, t_dot *start, t_dot *end)
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
