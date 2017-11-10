/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:06:25 by ggane             #+#    #+#             */
/*   Updated: 2017/11/10 03:34:07 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifdef __linux__
# include "../inc_linux/mlx.h"
# endif

# ifdef __APPLE__
# include "mlx.h"
# endif

# include "libft.h"
# include <fcntl.h>

# define MAP_BUF_SIZE 1
# define WIDTH 1000
# define HEIGHT 1000
# define CONST1 0.5
# define CONST2 0.5
# define ZOOM 15
# define POS 90
# define PINK 0x00FF358B
# define WHITE 0x00FFFFFF
# define RED 0x008E3557
# define BLUE 0x004BB5C1
# define BROWN 0x00BD8D46
# define GREEN 0x0096CA2D
# define ORANGE 0x00FEB201
# define YELLOW 0x00F2E203

typedef struct	s_dot
{
	int			x;
	int			y;
}				t_dot;

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
void			reset_point(t_dot **point);

/*
** map_coordinates.c
*/

void			get_x_values(int *coordinates_row, char **splitted);
void			get_map_3d_coordinates(t_data *data, char *map);

/*
** type_conversion_utils.c
*/

char			**copy_file_to_str_array(t_data *data, char *map);
void			convert_str_to_int(t_data *data, char **char_map);
void			convert_array_str_to_array_int(char **char_map, t_data *data);

/*
** draw_directly_in_window.c
*/

int				exist_above_point(int y);
int				exist_next_point(t_data *data, int x);
void			draw_directly_in_window(t_data *data);

/*
** draw_a_line_in_window.c
*/

void			draw_a_line(t_data *data, t_dot *start, t_dot *end);

/*
** draw_line.c
*/

void			draw_line(t_data *data);

/*
** isometric_projection.c
*/

int				get_x_for_isometric_projection(int old_x, int y);
int				get_y_for_isometric_projection(int x, int old_y, int z);

/*
** zoom.c
*/

int				set_correct_zoom(int coordinate_value, char coordinate_name);

/*
** print_utils.c
*/

void			print_2d_point(t_dot *point);
void			print_one_point(int x, int y, int z);
void			print_coordinates(t_data *data);

#endif
