/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_coordinates_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:52:15 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 12:14:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int             get_z_value(char *map, int i)
{
    char    *to_convert;
    int     z;
    int     j;

    j = 0;
    if (!(to_convert = (char *)ft_memalloc(sizeof(char) * get_digit_size( \
    map, i) + 1)))
        return (-1);
    while (ft_isdigit(map[i]))
    {
        to_convert[j] = map[i];
        j++;
        i++;
    }
    to_convert[j] = '\0';
    z = ft_atoi(to_convert);
    return (z);
}

int     get_x_value(char *map, int i)
{
    int     j;
    int     x;

    j = 0;
    x = 0;
    while (j != i)
    {
        if (ft_isdigit(map[j]))
        {
            x += 1;
            j = go_to_last_digit(map, j);
        }
        j++;
    }
    return (x);
}

int     get_y_value(char *map, int i)
{
    int     j;
    int     y;

    y = 0;
    while (j != i)
    {
        if (map[j] == '\n')
            y++;
        j++;
    }
    return (y);
}
