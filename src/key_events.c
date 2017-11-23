/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 05:38:17 by ggane             #+#    #+#             */
/*   Updated: 2017/11/23 13:22:07 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				check_key(int keycode, t_data *data)
{
	if (keycode == ESCAPE_KEY)
	{
		delete_data(&data);
		exit(1);
	}
	return (0);
}

static int		close_window(void)
{
	exit(1);
}

int				close_button_is_clicked(t_data *data)
{
	mlx_hook(data->win, 17, 0L, close_window, data);
	return (0);
}

int				escape_key_is_pressed(t_data *data)
{
	mlx_key_hook(data->win, check_key, data);
	return (0);
}
