/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 05:38:17 by ggane             #+#    #+#             */
/*   Updated: 2017/11/10 06:28:23 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_key(int keycode, t_data *data)
{
	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_image(data->mlx, data->image_id);
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	return (0);
}

int		escape_key_is_pressed(t_data *data)
{
	mlx_key_hook(data->win, check_key, data); 
	return (0);
}
