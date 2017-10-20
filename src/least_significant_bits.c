/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_significant_bits.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:17:51 by ggane             #+#    #+#             */
/*   Updated: 2017/10/20 13:40:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		take_last_bits(void *mlx, char *area)
{
	*area = mlx_get_color_value(mlx, RED >> 16);
	*(area + 1) = mlx_get_color_value(mlx, RED >> 8);
	*(area + 2) = mlx_get_color_value(mlx, RED);
}

static void		take_first_bits(void *mlx, char *area)
{
	*area = mlx_get_color_value(mlx, RED);
	*(area + 1) = mlx_get_color_value(mlx, RED >> 8);
	*(area + 2)  = mlx_get_color_value(mlx, RED >> 16);
}

void			get_least_significant_bits(t_image *i, void *mlx, char *area)
{
	if (i->endian == THE_BIG_ENDIAN)
		take_last_bits(mlx, area);
	else if (i->endian == THE_LITTLE_ENDIAN)
		take_first_bits(mlx, area);
}
