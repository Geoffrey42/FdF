/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:32:41 by ggane             #+#    #+#             */
/*   Updated: 2017/10/13 00:02:16 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_image  *create_image(t_2d *coordinates, t_mlx *data)
{
	t_image		*image;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	image->id = mlx_new_image(data->mlx);
	return (image);
}

static void		fill_image(t_image *image, t_2d *coordinates, t_mlx *data)
{
	int		bpp;
	int		size_line;
	int		endian;

	data->str = mlx_get_data_addr(image->id, &bpp, &size_line, &endian);
}

void	        *get_image_from(t_2d **converted_coordinates, t_mlx *data)
{
	t_image		*image;

	image = create_image(converted_coordinates, data);
	fill_image(image, converted_coordinates, data);
	return (image);
}
