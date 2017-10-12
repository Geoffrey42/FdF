/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:34:02 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 19:34:25 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		get_digit_size(char *map, int i)
{
	size_t		size;

	size = go_to_last_digit(map, i) - (size_t)i;
	return (size);
}

int			is_more_than_single_digit(char *map, int i)
{
	if (ft_isdigit(map[i + 1]))
		return (1);
	return (0);
}

int			go_to_last_digit(char *map, int i)
{
	while (ft_isdigit(map[i + 1]))
		i++;
	return (i);
}
