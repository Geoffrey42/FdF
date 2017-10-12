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

static size_t   get_coord_nb(char *map)
{
    size_t  size;
    int     i;

    size = 0;
    i = 0;
    while (map[i])
    {
        if (ft_isdigit(map[i]))
        {
            size++;
            if (is_more_than_single_digit(map, i))
                i = go_to_last_digit(map, i);
        }
        i++;
    }
    return (size);
}

static t_3d     **initialize_coordinates_array(char *map)
{
    t_3d    **coord;
    int     i;
    size_t  size;

    i = 0;
    size = get_coord_nb(map);
    if (!(coord = (t_3d **)ft_memalloc(sizeof(t_3d *) * size)))
        return (NULL);
    while (i < (int)size)
    {
        if (!(coord[i] = (t_3d *)ft_memalloc(sizeof(t_3d))))
            return (NULL);
        coord[i]->x = 0;
        coord[i]->y = 0;
        coord[i]->z = 0;
        i++;
    }
    return (coord);
}

t_3d            **get_map_coordinates(char *map)
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
    if (!(coord = initialize_coordinates_array(map)))
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
                coord[j]->z = map[i] + 48;
            j++;
        }
        else if (map[i] == '\n')
        {
            column = 0;
            line++;
        }
        i++;
    }
    return (coord);
}