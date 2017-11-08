/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 15:12:40 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 20:17:07 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data	*data;

	if (check_errors(ac, av[1]))
		return (-1);
	data = set_data_structure();
	get_map_3d_coordinates(data, av[1]);
	convert_coordinates_for_isometric_projection(data);
	draw_directly_in_window(data);
	//print_coordinates_in_image(data);
	//print_image_in_window(data);
	delete_data(&data);
	return (0);
}
