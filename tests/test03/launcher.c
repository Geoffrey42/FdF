/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:56:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/26 10:32:00 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <stdio.h>

void		
int		main(void)
{
	void	*mlx;
	void	*win1;

	mlx = mlx_init();
	win1 = mlx_new_window(mlx, 500, 500, "test 1");
	draw_ascending_line(mlx);
	mlx_loop();
    return (0);
}
