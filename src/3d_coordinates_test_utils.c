/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_coordinates_test_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:00:38 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 13:08:26 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void     print_3d_coordinates_x(t_3d **coordinates)
{
    int     i;
    int     size;

    i = 0;
    size = (int)coordinates[0]->len;
    while (i < size)
    {
        ft_putnbr(coordinates[i]->x);
        if (i != size)
            ft_putstr(" | ");
    }
}

static void     print_3d_coordinates_y(t_3d **coordinates)
{
    int     i;
    int     size;

    i = 0;
    size = (int)coordinates[0]->len;
    while (i < size)
    {
        ft_putnbr(coordinates[i]->y);
        if (i != size)
            ft_putstr(" | ");
    }
}

static void     print_3d_coordinates_z(t_3d **coordinates)
{
    int     i;
    int     size;

    i = 0;
    size = (int)coordinates[0]->len;
    while (i < size)
    {
        ft_putnbr(coordinates[i]->z);
        if (i != size)
            ft_putstr(" | ");
    }
}

void            print_3d_coordinates(t_3d **coordinates)
{
    print_3d_coordinates_x(coordinates);
    ft_putchar('\n');
    print_3d_coordinates_y(coordinates);
    ft_putchar('\n');
    print_3d_coordinates_z(coordinates);
    ft_putchar('\n');
}
