/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:32:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/20 13:51:15 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <fcntl.h>
#include <stdio.h>

int             main(int ac, char **av)
{
    t_3d    **raw_coordinates;
    char    *map;

    if (is_not_a_correct_map(ac, av))
        return (-1);
    map = copy_map_in_a_string(av[1]);
    raw_coordinates = get_map_coordinates(map);
    print_3d_coordinates(raw_coordinates);
	ft_putstr(map);
    return (0);
}
