/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:06:25 by ggane             #+#    #+#             */
/*   Updated: 2017/10/22 21:14:14 by ggane            ###   ########.fr       */
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
# define CONST1 1
# define CONST2 1
# define PINK 0x00FF358B
# define WHITE 0x00FFFFFF
# define RED 0x008E3557
# define BLUE 0x004BB5C1
# define BROWN 0x00BD8D46
# define GREEN 0x0096CA2D
# define ORANGE 0x00FEB201
# define YELLOW 0x00F2E203

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

/*
** draw_directly_in_window.c
*/

void			draw_directly_in_window(t_data *data);

/*
** draw_line.c
*/

void			draw_line(int x1, int y1, int x2, int y2, t_data *data);

/*
** isometric_projection.c
*/

int				get_x_for_isometric_projection(int old_x, int y);
int				get_y_for_isometric_projection(int x, int old_y, int z);

#endif
