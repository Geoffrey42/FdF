/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:07:13 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 00:18:29 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		have_different_length_lines(char *map_copy)
{
	int		line_length_reference;
	int		new_line_length;
	int		i;
	int		line_nb;

	ft_putendl("-------------------------------------------------------------");
	ft_putstr(map_copy);
	ft_putendl("-------------------------------------------------------------");
	line_length_reference = len_till_c(map_copy, '\n');
	ft_putstr("\tlength_reference = ");
	ft_putnbrdl(line_length_reference);
	ft_putstr("\tmap_copy[length_reference] : [");
	ft_putchar(map_copy[line_length_reference]);
	ft_putstr("]\n");
	//i = line_length_reference + 1;
	i = 0;
	line_nb = 1;
	//while (map_copy[i] != '\n' || map_copy[i] != '\0')
	while (1)
	{
		new_line_length = len_till_c(map_copy + i, '\n');
		ft_putstr("\tnew_line_length = ");
		ft_putnbrdl(new_line_length);
		if (new_line_length != line_length_reference)
			return (1);
		i += (new_line_length + 1);
		if (i >= (int)ft_strlen(map_copy))
			break ;
		ft_putstr("\tmap_copy[");
		ft_putnbr(i);
		ft_putstr("] : [");
		ft_putchar(map_copy[i]);
		ft_putstr("]\n");
		line_nb++;
		ft_putstr("\tline_nb : ");
		ft_putnbr(line_nb);
		ft_putendl("\t\t*****");
	}
	return (0);
}

/*
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
		ft_strdel(&line);
	}
	close(fd);
	ft_strdel(&line);
	return (0);
}
*/

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
	//else if (is_invalid_lines(map_name))
	//	ret = -1;
	else if (have_different_length_lines(map_copy))
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
