/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:34:49 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 19:34:55 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_image_in_window(t_image *image, t_mlx *data)
{
	mlx_put_image_to_window(data->mlx, data->win, image->id, WIDTH, HEIGHT);
}
