/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 23:33:50 by ggane             #+#    #+#             */
/*   Updated: 2017/11/10 04:22:55 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_map_line_nb(char *map)
{
	int		y_max;
	int		fd;
	int		ret;
	char	*line;

	y_max = 0;
	fd = open(map, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		y_max++;
		ft_strdel(&line);
	}
	close(fd);
	return (y_max);
}

static int		get_map_max_col(char *map)
{
	int		x_max;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	get_next_line(fd, &line);
	x_max = get_word_nb(line, ' ');
	close(fd);
	ft_strdel(&line);
	return (x_max);
}

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

	data->y_max = get_map_line_nb(map);
	data->x_max = get_map_max_col(map);
	char_map = copy_file_to_str_array(data, map);
	convert_array_str_to_array_int(char_map, data);
	erase_char_array(char_map);
}
