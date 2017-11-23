/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:26:43 by ggane             #+#    #+#             */
/*   Updated: 2017/11/23 13:26:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_max_coordinate(int coord_1, int coord_2)
{
	if (coord_1 > coord_2)
		return (coord_1);
	else
		return (coord_2);
}

int		get_min_coordinate(int coord_1, int coord_2)
{
	if (coord_1 < coord_2)
		return (coord_1);
	else
		return (coord_2);
}
