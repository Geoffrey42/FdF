/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 23:33:50 by ggane             #+#    #+#             */
/*   Updated: 2017/11/25 01:29:27 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			get_x_values(int *coordinates_row, char **splitted)
{
	int		i;

	i = 0;
	while (splitted[i])
	{
		coordinates_row[i] = ft_atoi(splitted[i]);
		i++;
	}
}

void			get_map_3d_coordinates(t_data *data, char *map)
{
	char	**char_map;

	data->y_max = get_nb_of_lines(data->map_cpy);
	data->x_max = get_nb_of_coordinates_in_a_line(data->map_cpy);
	char_map = copy_file_to_str_array(data, map);
	convert_array_str_to_array_int(char_map, data);
	erase_char_array(char_map);
}
