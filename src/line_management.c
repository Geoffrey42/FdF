/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:21:13 by ggane             #+#    #+#             */
/*   Updated: 2017/11/17 02:34:00 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_one_almost_vertical_line(t_data *d, t_dot *p1, t_dot *p2)
{
	int		xn;
	int		yn;

	yn = p1->y;
	while (yn <= p2->y)
	{
		xn = p1->x + ((p2->x - p1->x) * (yn - p1->y)) / (p2->y - p1->y);
		d->draw_pixel(d, xn, yn++);
	}
}

static void		draw_one_almost_horizontal_line(t_data *d, t_dot *p1, t_dot *p2)
{
	int		xn;
	int		yn;

	xn = p1->x;
	while (xn <= p2->x)
	{
		yn = p1->y + ((p2->y - p1->y) * (xn - p1->x)) / (p2->x - p1->x);
		d->draw_pixel(d, xn++, yn);
	}
}

static void		choose_line_angle_and_draw_it(t_data *d, t_dot *p1, t_dot *p2)
{
	if (p1->x < p2->x && p1->y > p2->y)
		d->draw_corresponding_line(d, p1, p2);
	else if (p1->x < p2->x && p1->y < p2->y)
		d->draw_corresponding_line(d, p1, p2);
	else if (p1->x > p2->x && p1->y < p2->y)
		d->draw_corresponding_line(d, p2, p1);
	else if (p1->x > p2->x && p1->y > p2->y)
		d->draw_corresponding_line(d, p2, p1);
}

static int		need_several_x_for_each_y(t_dot *p1, t_dot *p2)
{
	if ((p2->x - p1->x) >= abs(p2->y - p1->y))
		return (1);
	return (0);
}

void			draw_one_line(t_data *data, t_dot *p1, t_dot *p2)
{
	if (need_several_x_for_each_y(p1, p2))
	{
		data->draw_corresponding_line = &draw_one_almost_horizontal_line;
		choose_line_angle_and_draw_it(data, p1, p2);
	}
	else
	{
		data->draw_corresponding_line = &draw_one_almost_vertical_line;
		choose_line_angle_and_draw_it(data, p1, p2);
	}
}
