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

int		check_key(int keycode, void *escape_key)
{
	int		one;

	one = 1;
	if (keycode == ESCAPE_KEY)
	{
		ft_putendl("keycode == ESCAPE_KEY");
		escape_key = &one;
		ft_putstr("\tescape_key (in check_key()) : ");
		ft_putnbrdl(*((int *)escape_key));
	}
	return (0);
}

int		escape_key_is_pressed(t_data *data)
{
	mlx_key_hook(data->win, check_key, (void *)data->escape_key); 
	ft_putstr("escape_key : ");
	ft_putnbrdl(*(data->escape_key));
	ft_putnbrdl(*((int)data->escape_key));
	if (*((int *)data->escape_key) == 1)
		return (1);
	else
		return (0);
}
