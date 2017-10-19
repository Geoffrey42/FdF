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

static t_image  *create_image(t_mlx *data)
{
	t_image		*image;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	image->id = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	return (image);
}

static void		get_image_memory_area(t_image *i, t_mlx *d)
{
	data->memory_area = mlx_get_data_addr(i->id, i->&bpp, i->&size_line,\
			&i->endian);
}

static void		fill_image_with_colors(t_image *image, t_2d **c, t_mlx *d)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = d->memory_area;
	while (i < (int)c[0]->len)
	{
		tmp = tmp + c[i]->y * image->size_line + image->bpp * c[i]->x;
		*tmp = get_least_significant_bits(mlx_get_color_value(d->mlx, RED));
		i++;
	}
}

void	        *get_image_from(t_2d **coordinates, t_mlx *data)
{
	t_image		*image;

	image = create_image(data);
	get_image_memory_area(image, data);
	fill_image_with_colors(image, coordinates, data);
	return (image);
}
