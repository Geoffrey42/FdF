/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_coordinates_test_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:00:38 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 19:19:06 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		print_structure_content(t_3d *coordinate)
{
	ft_putstr("x : ");
	ft_putnbr(coordinate->x);
	ft_putstr(" | ");
	ft_putstr("y : ");
	ft_putnbr(coordinate->y);
	ft_putstr(" | ");
	ft_putstr("z : ");
	ft_putnbr(coordinate->z);
	ft_putstr(" |\n");
}

void			print_3d_coordinates(t_3d **coordinates)
{
	int		i;
	int		size;

	i = 0;
	size = (int)coordinates[0]->len;
	while (i < size)
		print_structure_content(coordinates[i++]);
}
