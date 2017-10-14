/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:07:31 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 22:34:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_3d	**t3d_coordinates;
	t_2d	**d2d_coordinates;
	char	*map;
	t_image *image;

	if (is_not_a_correct_map(ac, av))
		return (-1);
	map = copy_map_in_a_string(av[1]);
	t3d_coordinates = get_map_coordinates(map);
	ft_strdel(&map);
	d2d_coordinates = convert_3d_coordinates_for_isometric_projection(\
			t3d_coordinates);
	image = get_image_from(d2d_coordinates);
	display_image_in_window(image);
    erase_image(image);
	erase_both_arrays(t3d_coordinates, d2d_coordinates);
	return (0);
}
