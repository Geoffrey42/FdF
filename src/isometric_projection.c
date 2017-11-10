/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 20:43:15 by ggane             #+#    #+#             */
/*   Updated: 2017/11/09 23:35:52 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_x_for_isometric_projection(int old_x, int y)
{
	return (CONST1 * old_x - CONST2 * y);
}

int		get_y_for_isometric_projection(int x, int old_y, int z)
{
	return (z + (CONST1 / 2) * x + (CONST2 / 2) * old_y);
}
