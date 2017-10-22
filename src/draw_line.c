/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:52:58 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 21:56:23 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(int x1, int y1, int x2, int y2, t_data *data)
{
	int		xn;
	int		swap;
	int		yn;
	int		coef_directeur;
	int		ordonnee_a_lorigine;

	xn = x1;
	if (x1 == x2)
    {
        yn = y1;
        if (y1 > y2)
		{
			swap = y2;
			yn = y2;
			xn = x2;
			y2 = y1;
			y1 = swap;
		}
		while (yn <= y2)
			mlx_pixel_put(data->mlx, data->win, xn++, yn++, RED);
		return ;
	}
	if (x1 > x2)
	{
		swap = x1;
		x1 = x2;
		xn = x1;
		x2 = swap;
		swap = y1;
		y1 = y2;
		y2 = swap;
	}
	coef_directeur = (y2 - y1) / (x2 - x1);
	ordonnee_a_lorigine = y1 - coef_directeur * x1;
	while (xn <= x2)
	{
		yn = coef_directeur * xn + ordonnee_a_lorigine;
		mlx_pixel_put(data->mlx, data->win, xn, yn, RED);
		xn++;
	}
}
