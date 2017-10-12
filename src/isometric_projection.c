/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 15:04:08 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 17:21:18 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d    **convert_3d_coordinates_for_isometric_projection(t_3d **coordinates)
{
    t_2d    **converted_coordinates;

    (void)coordinates;
    converted_coordinates = (t_2d **)malloc(sizeof(t_2d *) * 2);
    return (converted_coordinates);
}
