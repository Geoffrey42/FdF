/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 05:38:17 by ggane             #+#    #+#             */
/*   Updated: 2017/11/15 19:20:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> // to delete

int		check_key(int keycode, t_data *data)
{
	printf("data : %p\n", data);
	printf("data->coordinates : %p\n", data->coordinates);
	if (keycode == ESCAPE_KEY)
	{
		delete_data(&data);
		exit(1);
	}
	return (0);
}

int		escape_key_is_pressed(t_data *data)
{
	mlx_key_hook(data->win, check_key, data);
	return (0);
}
