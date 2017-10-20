/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:32:41 by ggane             #+#    #+#             */
/*   Updated: 2017/10/20 14:15:50 by ggane            ###   ########.fr       */
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

static void		get_image_memory_area(t_image *i)
{
	i->memory_area = mlx_get_data_addr(i->id, &i->bpp, &i->size_line,\
			&i->endian);
}

static void		fill_image_with_colors(t_image *image, t_2d **c, t_mlx *d)
{
	int		i;
	char	*tmp;
	int		size;

	i = 0;
	tmp = image->memory_area;
	(void)d;
	//ft_putstr("nombre de coordonnees : ");
	//ft_putnbrdl((int)c[0]->len);
	while (i < (int)c[0]->len)
	{
		size = (c[i]->y * image->size_line) + (image->bpp / 8 * c[i]->x);
		ft_putstr("y (fill_image_with_colors()) : ");
		ft_putnbrdl(c[i]->y);
		//ft_putstr("size : ");
		//ft_putnbrdl(size);
		//tmp = tmp + size; 
		//get_least_significant_bits(image, d->mlx, tmp);
		//tmp = image->memory_area;
		i++;
	}
	exit(0);
}

t_image			*get_image_from(t_2d **coordinates, t_mlx *data)
{
	t_image		*image;

	image = create_image(data);
	get_image_memory_area(image);
	fill_image_with_colors(image, coordinates, data);
	return (image);
}
