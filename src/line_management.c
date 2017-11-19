/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:21:13 by ggane             #+#    #+#             */
/*   Updated: 2017/11/20 00:34:27 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_one_almost_vertical_line(t_data *d, t_dot *p1, t_dot *p2, int choice)
{
	int		xn;
	int		yn;

	if (choice == 1 && d->color == RED)
		ft_putendl("BEFOR DRAWING !!!!!!!!");
	if (p1->y < p2->y)
	{
		yn = p1->y;
		while (yn <= p2->y)
		{
			xn = p1->x + ((p2->x - p1->x) * (yn - p1->y)) / (p2->y - p1->y);
			if (choice == 1 && d->color == RED)
			{
				ft_putstr("REEEEEEEEEEED");
				ft_putstr("\tx1 : ");
				ft_putnbrdl(p1->x);
				ft_putstr("\ty1 : ");
				ft_putnbrdl(p1->y);
			}
			d->draw_pixel(d, xn, yn++);
		}
	}
	else
	{
		yn = p2->y;
		while (yn <= p1->y)
		{
			xn = p1->x + ((p2->x - p1->x) * (yn - p1->y)) / (p2->y - p1->y);
			if (choice == 1 && d->color == RED)
			{
				ft_putstr("REEEEEEEEEEED");
				ft_putstr("\tx1 : ");
				ft_putnbrdl(p1->x);
				ft_putstr("\ty1 : ");
				ft_putnbrdl(p1->y);
			}
			d->draw_pixel(d, xn, yn++);
		}
	}
}

static void		draw_one_almost_horizontal_line(t_data *d, t_dot *p1, t_dot *p2, int choice)
{
	int		xn;
	int		yn;

	xn = p1->x;
	(void)choice;
	while (xn <= p2->x)
	{
		yn = p1->y + ((p2->y - p1->y) * (xn - p1->x)) / (p2->x - p1->x);
		d->draw_pixel(d, xn++, yn);
	}
}

static void		print_point(t_dot *p)
{
	ft_putstr("iso x : ");
	ft_putnbrdl(p->x);
	ft_putstr("iso y : ");
	ft_putnbrdl(p->y);
}

static void		choose_line_angle_and_draw_it(t_data *d, t_dot *p1, t_dot *p2, int choice)
{
	if (p1->x < p2->x && p1->y > p2->y)
	{
		if (choice == 1)
		{
			d->color = RED;
			ft_putendl("RED");
		}
		else
			ft_putendl("WHITE1");
		ft_putendl("----\np1 :");
		print_point(p1);
		ft_putendl("**\np2 :");
		print_point(p2);
		ft_putendl("---");
		d->draw_corresponding_line(d, p1, p2, choice);
	}
	else if (p1->x < p2->x && p1->y < p2->y)
	{
		if (choice == 1)
		{
			d->color = GREEN;
			ft_putendl("GREEN");
		}
		else
			ft_putendl("WHITE2");
		d->draw_corresponding_line(d, p1, p2, choice);
	}
	else if (p1->x > p2->x && p1->y < p2->y)
	{
		if (choice == 1)
		{
			d->color = BLUE;
			ft_putendl("BLUE");
		}
		else
			ft_putendl("WHITE3");
		d->draw_corresponding_line(d, p2, p1, choice);
	}
	else if (p1->x > p2->x && p1->y > p2->y)
	{
		if (choice == 1)
		{
			d->color = ORANGE;
			ft_putendl("ORANGE");
		}
		else
			ft_putendl("WHITE4");
		d->draw_corresponding_line(d, p2, p1, choice);
	}
}

static int		need_several_x_for_each_y(t_dot *p1, t_dot *p2)
{
	if ((p2->x - p1->x) >= abs(p2->y - p1->y))
		return (1);
	return (0);
}

void			draw_one_line(t_data *data, t_dot *p1, t_dot *p2)
{
	int		choice = 0;
	static int	i = 1;

	if (need_several_x_for_each_y(p1, p2))
	{
		//data->color = WHITE;
		data->draw_corresponding_line = &draw_one_almost_horizontal_line;
		choose_line_angle_and_draw_it(data, p1, p2, choice);
	}
	else
	{
		choice = 1;
		data->draw_corresponding_line = &draw_one_almost_vertical_line;
		choose_line_angle_and_draw_it(data, p1, p2, choice);
	}
	ft_putstr("i : ");
	ft_putnbrdl(i++);
}
