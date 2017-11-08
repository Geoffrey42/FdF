/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:08:23 by ggane             #+#    #+#             */
/*   Updated: 2017/11/07 21:43:38 by ggane            ###   ########.fr       */
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

static void		erase_3d_coordinates(int **coordinates)
{
	if (coordinates)
	{
		free(coordinates);
		coordinates = NULL;
	}
}

static void		erase_2d_coordinates(t_dot **iso)
{
	int		i;

	i = 0;
	if (!iso)
		return ;
	while (i < iso[0]->len)
	{
		free(iso[i]);
		iso[i] = NULL;
		i++;
	}
	free(iso);
	iso = NULL;
}

void			delete_data(t_data **data)
{
	mlx_destroy_image((*data)->mlx, (*data)->image_id);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	erase_3d_coordinates((*data)->coordinates);
	erase_2d_coordinates((*data)->iso);
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
