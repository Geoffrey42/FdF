/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 15:12:40 by ggane             #+#    #+#             */
/*   Updated: 2017/11/25 01:15:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data	*data;

	data = set_data_structure();
	data->map_cpy = copy_map_in_a_string(av[1]);
	if (check_errors(ac, data->map_cpy))
	{
		delete_data(&data);
		return (-1);
	}
	get_map_3d_coordinates(data, av[1]);
	print_coordinates_in_image(data);
	display_image_in_window(data);
	delete_data(&data);
	return (0);
}
