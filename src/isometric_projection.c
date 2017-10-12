/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:33:17 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 22:16:23 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_2d		**allocate_memory_for_coordinates(size_t size)
{
	t_2d	**new;
	int		i;

	i = 0;
	if (!(new = (t_2d **)malloc(sizeof(t_2d *) * size)))
		return (NULL);
	while (i < (int)size)
	{
		if (!(new[i] = (t_2d *)ft_memalloc(sizeof(t_2d))))
			return (NULL);
		i++;
	}
	return (new);
}

t_2d			**convert_3d_coordinates_for_isometric_projection(t_3d **old)
{
	t_2d	**new;
	int		i;
	size_t	size;

	i = 0;
	size = old[0]->len;
	new = allocate_memory_for_coordinates(size);
	while (i < (int)size)
	{
		new[i]->x = CONST1 * old[i]->x - CONST2 * old[i]->y;
		new[i]->y = old[i]->z + CONST1 / 2 * old[i]->x + CONST2 / 2 * old[i]->y;
		new[i]->len = old[i]->len;
		i++;
	}
	return (new);
}
