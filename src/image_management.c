/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:32:41 by ggane             #+#    #+#             */
/*   Updated: 2017/10/13 00:02:16 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*get_image_from(t_2d **converted_coordinates)
{
	t_image     *image;

	image_id = create_image(converted_coordinates);
    fill_image();
	return (imaged);
}
