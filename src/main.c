/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 15:12:40 by ggane             #+#    #+#             */
/*   Updated: 2017/10/21 20:41:05 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data	*data;

	if (check_errors(ac, av[1]))
		return (-1);
	data = set_data_structure();
	data->coordinates = get_map_3d_coordinates(av[1]);
	print_coordinates_in_image(data);
	print_image_in_window(data);
	delete_data(&data);
	return (0);
}
