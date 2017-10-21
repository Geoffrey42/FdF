/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 21:54:46 by ggane             #+#    #+#             */
/*   Updated: 2017/10/21 22:53:13 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data		*set_data_structure(void)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fdf");
	data->image_id = mlx_new_image(data->mlx, 0, 0);
	data->memory_area = mlx_get_data_addr(data->image_id, &data->bpp,\
			&data->size_line, &data->endian);
	data->coordinates = NULL;
	return (data);
}
