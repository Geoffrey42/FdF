/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:32:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 13:08:54 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <fcntl.h>
#include <stdio.h>

int             main(int ac, char **av)
{
    t_3d    **raw_coordinates;

    if (is_not_a_correct_map(ac, av))
        return (-1);
    raw_coordinates = get_map_coordinates(av[1]);
    print_3d_coordinates(coordinates);
    return (0);
}
