/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:44:59 by ggane             #+#    #+#             */
/*   Updated: 2017/10/12 19:45:42 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/ggane/FdF/prework/display_map/inc/fdf.h"
#include <fcntl.h>
#include <stdio.h>

static void		create_file_from_a_string(char *original)
{
	int		fd;

	fd = open("copied_map.fdf", O_WRONLY);
	ft_putendl(original);
	ft_putstr_fd(original, fd);
	close(fd);
}

int				main(int ac, char **av)
{
	char	*map_copy;

	if (ac != 2)
		return (-1);
	map_copy = copy_map_in_a_string(av[1]);
	create_file_from_a_string(map_copy);
	return (0);
}
