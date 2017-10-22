/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:56:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 16:48:28 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <stdio.h>

int				get_map_max_col(char *map);
int				get_map_line_nb(char *map);

static void		print_string_array(char **copy)
{
	int		y;

	y = 0;
	while (copy[y] != NULL)
	{
		printf("*copy[%d] : [%s]\n", y, copy[y]);
		y++;
	}
}

int             main(int ac, char **av)
{
	t_data	*data;
	char	**copy;

	if (ac != 2)
		return (-1);
	data = set_data_structure();
	data->y_max = get_map_line_nb(av[1]);
	data->x_max = get_map_max_col(av[1]);
	copy = copy_file_to_str_array(data, av[1]);
	print_string_array(copy);
	erase_char_array(copy);
	delete_data(&data);
    return (0);
}
