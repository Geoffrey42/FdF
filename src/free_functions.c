/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:31:47 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 19:32:13 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		erase_2d_array(t_2d **coord_2d)
{
	(void)coord_2d;
	return (0);
}

static int		erase_3d_array(t_3d **coord_3d)
{
	(void)coord_3d;
	return (0);
}

int				erase_both_arrays(t_3d **coord_3d, t_2d **coord_2d)
{
	if (!erase_3d_array(coord_3d) || !erase_2d_array(coord_2d))
		return (-1);
	else
		return (0);
}

int				erase_image(t_image *image)
{
	(void)image;
	return (0);
}

int				erase_data(t_mlx *data)
{
	(void)data;
	return (0);
}
