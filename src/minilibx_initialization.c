/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_initialization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 12:19:42 by ggane             #+#    #+#             */
/*   Updated: 2017/10/20 12:19:44 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*initialize_minilibx(void)
{
	t_mlx	*data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	data->mlx = mlx_init();
	return (data);
}
