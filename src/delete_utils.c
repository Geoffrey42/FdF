/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:08:23 by ggane             #+#    #+#             */
/*   Updated: 2017/11/25 01:21:04 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		erase_whole_data_structure(t_data **data)
{
	if (*data)
	{
		free(*data);
		*data = NULL;
	}
}

static void		erase_3d_coordinates(int **coordinates, int y_max)
{
	int		i;

	i = 0;
	if (coordinates)
	{
		while (i < y_max)
		{
			free(coordinates[i]);
			coordinates[i] = NULL;
			i++;
		}
		free(coordinates);
		coordinates = NULL;
	}
}

void			delete_data(t_data **data)
{
	mlx_destroy_image((*data)->mlx, (*data)->image_id);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	ft_strdel(&(*data)->map_cpy);
	erase_3d_coordinates((*data)->coordinates, (*data)->y_max);
	erase_whole_data_structure(data);
}

void			reset_point(t_dot **point)
{
	if (*point)
	{
		free(*point);
		*point = NULL;
	}
}
