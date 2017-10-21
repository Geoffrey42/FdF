/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:07:13 by ggane             #+#    #+#             */
/*   Updated: 2017/10/21 21:47:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		is_invalid_lines(char *map_name)
{
	int		fd;
	int		element_nb;
	char	*line;

	fd = get_map_fd(map_name);
	get_next_line(fd, &line);
	element_nb = get_word_nb(line, ' ');
	ft_strdel(&line);
	while (get_next_line(fd, &line) != 0)
	{
		if (get_word_nb(line, ' ') != element_nb)
		{
			close(fd);
			ft_strdel(&line);
			return (-1);
		}
	}
	close(fd);
	ft_strdel(&line);
	return (0);
}

static int		is_not_valid_format(char *map_name)
{
	char	*map_copy;
	int		ret;

	ret = 0;
	map_copy = copy_map_in_a_string(map_name);
	if (ft_strlen(map_copy) == 0 || ft_strlen(map_copy) == 1)
		ret = -1;
	else if (is_invalid_characters(map_copy))
		ret = -1;
	else if (is_invalid_lines(map_name))
		ret = -1;
	ft_strdel(&map_copy);
	return (ret);
}

int				check_errors(int ac, char *file)
{
	if (ac != 2)
		return (print_error_msg("Usage : ./fdf <filename>"));
	else if (is_not_valid_format(file))
		return (print_error_msg("invalid map format"));
	else
		return (0);
}
