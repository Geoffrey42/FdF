/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:03:00 by ggane             #+#    #+#             */
/*   Updated: 2017/10/21 21:29:00 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		is_not_valid_non_digit(char c)
{
	if (c != ' ' && c != '-' && c != ',' && c != '\n')
		return (-1);
	return (0);
}

int				is_invalid_characters(char *map_copy)
{
	int		i;

	i = 0;
	while (map_copy[i])
	{
		if (is_not_valid_non_digit(map_copy[i]) && !ft_isalnum(map_copy[i]))
			return (-1);
		i++;
	}
	return (0);
}

int				print_error_msg(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
		return (-1);
}
