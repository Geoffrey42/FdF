/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:07:13 by ggane             #+#    #+#             */
/*   Updated: 2017/11/25 01:19:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		is_not_valid_format(char *map_copy)
{
	int		ret;

	ret = 0;
	if (ft_strlen(map_copy) == 0 || ft_strlen(map_copy) == 1)
		ret = -1;
	else if (is_invalid_characters(map_copy))
		ret = -1;
	else if (have_different_length_lines(map_copy))
		ret = -1;
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
