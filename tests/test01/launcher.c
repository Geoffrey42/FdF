/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:56:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/21 23:48:23 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <stdio.h>

static void		display_data_fields(t_data *data)
{
	printf("mlx : [%p]\n", data->mlx);
	printf("win : [%p]\n", data->win);
	printf("image_id : [%p]\n", data->image_id);
	printf("memory_area : [%p]\n", data->memory_area);
	printf("bpp : [%d]\n", data->bpp);
	printf("endian : [%d]\n", data->endian);
	printf("size_line : [%d]\n", data->size_line);
	printf("coordinates : [%p]\n", data->coordinates);
	printf("x_max : [%d]\n", data->x_max);
	printf("y_max : [%d]\n", data->y_max);
	printf("-----------------------------------------\n");
}

int             main(void)
{
	t_data	*data;

	printf("test of data ");
	data = set_data_structure();
	//display_data_fields(data);
	delete_data(&data);
	/*
	if (data)
		display_data_fields(data);
	*/
	if (data)
		printf(" failed, data is not NULL\n");
	else
		printf(" succeeded\n");
    return (0);
}
