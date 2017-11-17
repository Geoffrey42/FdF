/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:25:04 by ggane             #+#    #+#             */
/*   Updated: 2017/11/17 01:29:23 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		set_correct_zoom(int coordinate_value, char coordinate_name)
{
	if (coordinate_name == 'x' || coordinate_name == 'y')
		coordinate_value *= ZOOM / 2;
	else if (coordinate_name == 'z')
		coordinate_value *= ZOOM / -4;
	else
		exit(print_error_msg("wrong coordinate name for zoom settings"));
	return (coordinate_value);
}
