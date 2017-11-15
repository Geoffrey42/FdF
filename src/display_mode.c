/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:57 by ggane             #+#    #+#             */
/*   Updated: 2017/11/15 19:19:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_coordinates_in_image(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->pixel_function = &turn_on_pixel_in_image;
	while (y < data->y_max)
	{
		while (x < data->x_max)
			draw_lines(data, x++, y);
		x = 0;
		y++;
	}
}

void	draw_directly_in_window(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->pixel_function = &display_pixel;
	while (y < data->y_max)
	{
		while (x < data->x_max)
			draw_lines(data, x++, y);
		x = 0;
		y++;
	}
	if (escape_key_is_pressed(data))
		return ;
	mlx_loop(data->mlx);
}
