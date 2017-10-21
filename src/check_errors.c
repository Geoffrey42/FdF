/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 15:27:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/21 16:32:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	print_error_message(char *error_message)
{
	ft_putendl_fd(error_message, STDERR_FILENO);
	return (-1);
}

static int	is_invalid_argument_number(int ac)
{
	if (ac != 2)
		return (-1);
	return (0);
}

static int	is_invalid_file_extension(char *map_name)
{
	(void)map_name;
	return (0);
}

static int	is_invalid_map_format(char *map_name)
{
	(void)map_name;
	return (0);
}

int			check_errors(int ac, char **av)
{
	if (is_invalid_argument_number(ac))
		return (print_error_message("invalid argument number"));
	else if (is_invalid_file_extension(av[1]))
		return (print_error_message("invalid file extension"));
	else if (is_invalid_map_format(av[1]))
		return (print_error_message("invalid map format"));
	return (0);
}
