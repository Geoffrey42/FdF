/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manipulation_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:25:48 by ggane             #+#    #+#             */
/*   Updated: 2017/11/24 21:37:10 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	get_map_file_size(int fd)
{
	size_t	size;
	char	buf[MAP_BUF_SIZE];
	int		ret;

	size = 0;
	while ((ret = read(fd, buf, MAP_BUF_SIZE)))
	{
		if (ret == -1)
			exit(print_error_msg("read() failed"));
		size++;
	}
	return (size);
}

static void		copy_file_content(int fd, char **map_copy)
{
	char	buf[MAP_BUF_SIZE];
	char	*tmp;
	int		i;

	i = 0;
	tmp = *map_copy;
	while (read(fd, buf, MAP_BUF_SIZE))
		tmp[i++] = buf[0];
}

char			*copy_map_in_a_string(char *map_name)
{
	size_t	size;
	char	*map_copy;
	int		fd;

	fd = get_map_fd(map_name);
	size = get_map_file_size(fd);
	close(fd);
	fd = get_map_fd(map_name);
	if (!(map_copy = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	map_copy[size] = '\0';
	copy_file_content(fd, &map_copy);
	close(fd);
	return (map_copy);
}

int				get_map_fd(char *map_name)
{
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit(print_error_msg("error : open() failed"));
	else
		return (fd);
}
