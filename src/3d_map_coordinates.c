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
    t_3d    **coord;
    int     i;
    int     j;
    int     line;
    int     column;

    i = 0;
    j = 0;
    line = 0;
    column = 0;
    if (!(coord = (t_3d **)malloc(sizeof(get_coord_nb(map_name)))))
        return (NULL);
    while (map[i])
    {
        if (ft_isdigit(map[i]))
        {
            coord[j]->x = column;
            coord[j]->y = line;
            if (is_more_than_single_digit(map, i))
            {
               coord[j]->z = get_whole_number(map, i); 
               i = go_to_last_digit(map, i);
            }
            else
                coord[j]->z = ft_atoi(map[i]);
            j++;
        }
        else if (map[i] == '\n')
        {
            column = 0;
            line++;
        }
        i++;
    }
    return (*coord);
}
