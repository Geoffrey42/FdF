/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 23:33:50 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 16:48:12 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_map_line_nb(char *map)
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

int		get_map_max_col(char *map)
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
	return (char_map);
}

static void		get_x_values(int *rows, char **splitted, int x_max)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (splitted[i])
	{
		if (!(rows = (int *)malloc(sizeof(int) * x_max))) 
			return ;
		while (splitted[i][j])
		{
			j++;
		}
		j = 0;
		i++;
	}
}

static void		convert_str_to_int(t_data *data, char **char_map)
{
	int		y;
	char	**splitted;

	y = 0;
	while (y < data->y_max)
	{
		splitted = ft_strsplit(char_map[y], ' ');
		get_x_values(data->coordinates[y], splitted, data->x_max);
		y++;
	}
}

static void		convert_array_str_to_array_int(char **char_map, t_data *data)
{
	if (!(data->coordinates = (int **)malloc(sizeof(int *) * data->y_max)))
		return ;
	convert_str_to_int(data, char_map);
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
