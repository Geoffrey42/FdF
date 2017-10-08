/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_map_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 15:01:42 by ggane             #+#    #+#             */
/*   Updated: 2017/10/08 15:23:47 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d    get_map_coordinates(char *map_name)
{
    t_3d    *raw_coordinates;

    (void)map_name;
    raw_coordinates = (t_3d *)malloc(sizeof(t_3d));
    return (*raw_coordinates);
}
