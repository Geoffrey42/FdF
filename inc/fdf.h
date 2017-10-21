/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:06:25 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 00:02:41 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

# define MAP_BUF_SIZE 1
# define WIDTH 1000
# define HEIGHT 1000

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*image_id;
	char		*memory_area;
	int			bpp;
	int			x_max;
	int			y_max;
	int			size_line;
	int			endian;
	int			**coordinates;
}				t_data;

/*
** check_errors.c
*/

int				check_errors(int ac, char *file);

/*
** check_errors_utils.c
*/

int				is_invalid_characters(char *map_copy);
int				print_error_msg(char *error_msg);

/*
** file_manipulation_utils.c
*/

char			*copy_map_in_a_string(char *map_name);
int				get_map_fd(char *map_name);

/*
** data_structure.c
*/

t_data			*set_data_structure(void);

/*
** delete_utils.c
*/

void			delete_data(t_data **data);

/*
** map_coordinates.c
*/

void			get_map_3d_coordinates(t_data *data, char *map);
#endif
