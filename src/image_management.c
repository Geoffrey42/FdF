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

static t_image  *create_image(t_2d *coordinates)
{
    t_image     *image;

    if (!(image = (t_image *)malloc(sizeof(t_image))))
        return (NULL);
    image->id = mlx_new_image();
    return (image);
}

void	        *get_image_from(t_2d **converted_coordinates, t_mlx *data)
{
	t_image     *image;

	image = create_image(converted_coordinates);
    fill_image(image, converted_coordinates, data);
	return (image);
}
