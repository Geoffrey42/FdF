/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversion_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:39:37 by ggane             #+#    #+#             */
/*   Updated: 2017/11/10 04:42:13 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**copy_file_to_str_array(t_data *data, char *map)
{
	char	**char_map;
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if (!(char_map = (char **)malloc(sizeof(char *) * data->y_max + 1)))
		return (NULL);
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		char_map[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	char_map[i] = NULL;
	close(fd);
	ft_strdel(&line);
	return (char_map);
}

void		convert_str_to_int(t_data *data, char **char_map)
{
	int		y;
	char	**splitted;

	y = 0;
	while (y < data->y_max)
	{
		splitted = ft_strsplit(char_map[y], ' ');
		if (!(data->coordinates[y] = (int *)malloc(sizeof(int) * data->x_max)))
			return ;
		get_x_values(data->coordinates[y], splitted);
		erase_char_array(splitted);
		y++;
	}
}

void		convert_array_str_to_array_int(char **char_map, t_data *data)
{
	if (!(data->coordinates = (int **)malloc(sizeof(int *) * data->y_max)))
		return ;
	convert_str_to_int(data, char_map);
}
