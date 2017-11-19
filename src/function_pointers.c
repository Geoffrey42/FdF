/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:20:14 by ggane             #+#    #+#             */
/*   Updated: 2017/11/19 22:02:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		display_pixel(t_data *data, int x, int y)
{
	return (mlx_pixel_put(data->mlx, data->win, POS + x, POS + y, data->color));
}

int		turn_on_pixel_in_image(t_data *d, int x, int y)
{
	int		size;

	x += POS;
	y += POS;
	if (x >= HEIGHT || y >= WIDTH || x <= 0 || y <= 0)
		return (-1);
	if (d->endian == 0)
	{
		size = ((y * d->size_line) + (x * d->bpp / 8));
		d->memory_area[size] = mlx_get_color_value(d->mlx, d->color);
		d->memory_area[size + 1] = mlx_get_color_value(d->mlx, d->color >> 8);
		d->memory_area[size + 2] = mlx_get_color_value(d->mlx, d->color >> 16);
	}
	else
	{
		size = ((y * d->size_line) + (x * d->bpp / 8));
		d->memory_area[size] = mlx_get_color_value(d->mlx, d->color >> 16);
		d->memory_area[size + 1] = mlx_get_color_value(d->mlx, d->color >> 8);
		d->memory_area[size + 2] = mlx_get_color_value(d->mlx, d->color);
	}
	return (0);
}
