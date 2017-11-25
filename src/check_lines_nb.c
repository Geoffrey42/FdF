/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:00:47 by ggane             #+#    #+#             */
/*   Updated: 2017/11/25 01:26:55 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		is_forbidden_char(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

static int		get_nb_of_coordinates(char *map)
{
	int			i;
	int			coordinates_nb;

	i = 0;
	coordinates_nb = 0;
	while (map[i])
	{
		if (i == 0 && !is_forbidden_char(map[i]))
			coordinates_nb++;
		if (!is_forbidden_char(map[i]) && i > 0 && is_forbidden_char(map[i - 1]))
			coordinates_nb++;
		i++;
	}
	return (coordinates_nb);
}

int				get_nb_of_coordinates_in_a_line(char *map)
{
	int		nb_of_coordinates_in_a_line;
	char	*line;
	size_t	len;

	len = len_till_c(map, '\n');
	if (!(line = (char *)malloc(sizeof(char) * len)))
		return (-1);
	line[len] = '\0';
	line = ft_strncpy(line, map, len);
	nb_of_coordinates_in_a_line = get_nb_of_coordinates(line);
	ft_strdel(&line);
	return (nb_of_coordinates_in_a_line);
}

int				get_nb_of_lines(char *map)
{
	int		nb_of_lines;
	int		i;

	nb_of_lines = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			nb_of_lines++;
		i++;
	}
	if (map[i] == '\0' && map[i - 1] != '\n')
		nb_of_lines++;
	return (nb_of_lines);
}

int				have_different_length_lines(char *map)
{
	int		nb_of_coordinates_in_a_line;
	int		total_nb_of_coordinates;
	int		nb_of_lines;

	nb_of_coordinates_in_a_line = get_nb_of_coordinates_in_a_line(map);
	nb_of_lines = get_nb_of_lines(map);
	total_nb_of_coordinates = get_nb_of_coordinates(map);
	if (nb_of_coordinates_in_a_line * nb_of_lines != total_nb_of_coordinates)
		return (1);
	return (0);
}
