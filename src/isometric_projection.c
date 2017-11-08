/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 20:43:15 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 21:19:06 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_x_for_isometric_projection(int old_x, int y)
{
	return (CONST1 * old_x - CONST2 * y);
}

int		get_y_for_isometric_projection(int x, int old_y, int z)
{
	return (z + (CONST1 / 2) * x + (CONST2 / 2) * old_y);
}
/*
void	convert_coordinates_for_isometric_projection(t_data *data)
{
	int		i;

	i = 0;
	if (!(data->iso = (t_dot **)malloc(sizeof(t_dot *) * data->x_max)))
		return ;
	while (i < x_max)
	{
		if (!(data->iso[i] = (t_dot *)malloc(sizeof(t_dot))))
			return ;
		data->iso[i]->x = get_x_for_isometric_projection();
		data->iso[i]->y = get_y_for_isometric_projection();
		i++;
	}
}*/
