/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:56:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 17:52:10 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <stdio.h>
#define CORRECT_X_MAX 11
#define CORRECT_Y_MAX 9

static void		print_int_array(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->y_max)
	{
		while (x < data->x_max)
		{
			printf("x : %d - y : %d - z : %d\n", x, y, data->coordinates[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
}

static int		is_different_from_correct_array(t_data *data, int correct[CORRECT_Y_MAX][CORRECT_X_MAX])
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (data->x_max != CORRECT_X_MAX || data->y_max != CORRECT_Y_MAX)
		return (print_error_msg(" failed because of incorrect x_max or y_max"));
	while (y < data->y_max)
	{
		while (x < data->x_max)
		{
			if (data->coordinates[y][x] != correct[y][x])
				return (print_error_msg(" failed because of incorrect z value"));
			x++;
		}
		x = 0;
		y++;
	}
	ft_putendl(" succeeded");
	return (0);
}

int             main(int ac, char **av)
{
	t_data	*data;
	int		correct[CORRECT_Y_MAX][CORRECT_X_MAX] = {
		{0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		{0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8},
		{0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7},
		{0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6},
		{0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5},
		{0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
		};

	if (ac != 2)
		return (-1);
	ft_putstr("Test");
	data = set_data_structure();
	get_map_3d_coordinates(data, av[1]);
	is_different_from_correct_array(data, correct);
	delete_data(&data);
    return (0);
}
