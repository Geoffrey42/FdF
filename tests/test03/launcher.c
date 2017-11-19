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
#include <math.h>

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
	d1->draw_pixel = &display_pixel;
	/*
	t_data	*d2 = set_data_structure();
	t_data	*d3 = set_data_structure();
	t_data	*d4 = set_data_structure();
	t_data	*d5 = set_data_structure();
	t_data	*d6 = set_data_structure();
	t_data	*d7 = set_data_structure();
	t_data	*d8 = set_data_structure();
	*/

	ft_putendl("Test d'une ligne ascendante normale");
	p1 = set_isometric_point(300, 199, 0);
	p2 = set_isometric_point(301, 200, 200);
	draw_one_line(d1, p1, p2);
	//reset_point(&p1);
	//reset_point(&p2);
	//delete_data(&d1);
	if (escape_key_is_pressed(d1))
		return (1);
	mlx_loop(d1->mlx);
	ft_putendl("Test d'une ligne ascendante inverse");
	ft_putendl("Test d'une ligne descendante normale");
	ft_putendl("Test d'une ligne descendante inverse");
	ft_putendl("Test d'une ligne horizontale normale");
	ft_putendl("Test d'une ligne horizontale inverse");
	ft_putendl("Test d'une ligne verticale normale");
	ft_putendl("Test d'une ligne verticale inverse");
    return (0);
}
