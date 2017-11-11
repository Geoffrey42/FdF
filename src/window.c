/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:00:44 by ggane             #+#    #+#             */
/*   Updated: 2017/11/11 14:19:27 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		display_image_in_window(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, image->id, 0, 0);	
	mlx_loop(data->mlx);
}
