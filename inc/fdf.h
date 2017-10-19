#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# define MAP_BUF_SIZE 1
# define CONST1 0.5
# define CONST2 1
# define HEIGHT 800
# define WIDTH 600
# define RED 0x008E3557 
# define BIG_ENDIAN 1
# define LITTLE_ENDIAN 0

typedef struct  s_3d
{
    int         x;
    int         y;
    int         z;
    size_t      len;
}               t_3d;

typedef struct  s_2d
{
    int         x;
    int         y;
    size_t      len;
}               t_2d;

typedef struct  s_image
{
    void        *id;
    char        *memory_area;
	int			bpp;
	int			size_line;
	int			endian;
}               t_image;

typedef struct  s_mlx
{
    void        *mlx;
    void        *win;
}               t_mlx;

/*
** check00.c
*/

int             is_not_a_correct_map(int ac, char **av);

/*
** check01.c
*/

int             is_not_fdf_extension(char *map_name);
int             is_invalid_characters(char *map_copy);

/*
** errors.c
*/

int             print_error_msg(char *error_msg);

/*
** fd_basic_functions.c
*/

char            *copy_map_in_a_string(char *map_name);
int             get_map_fd(char *map_name);

/*
** 3d_map_coordinates.c
*/

t_3d            **get_map_coordinates(char *map_name);

/*
** 3d_coordinates_values.c
*/

int             get_z_value(char *map, int i);
int             get_x_value(char *map, int i);
int             get_y_value(char *map, int i);

/*
** 3d_coordinates_test_utils.c
*/

void            print_3d_coordinates(t_3d **coordinates);

/*
** isometric_projection.c
*/

t_2d            **convert_3d_coordinates_for_isometric_projection(
                t_3d **raw_coordinates);

/*
** image_management.c
*/

t_image         *get_image_from(t_2d **coordinates, t_mlx *data);

/*
** least_significant_bits.c
*/

int				get_least_significant_bits(t_image *image, int color_value);

/*
** minilibx_initialization.c
*/

t_mlx           *initialize_minilibx(void);

/*
** window_display.c
*/

void            display_image_in_window(t_image *image);

/*
** parsing_utils.c
*/

size_t          get_digit_size(char *map, int i);
int             is_more_than_single_digit(char *map, int i);
int             go_to_last_digit(char *map, int i);

/*
** free_functions.c
*/

int             erase_both_arrays(t_3d **coord_3d, t_2d **coord_2d);
int             erase_image(t_image *image);
int             erase_data(t_mlx *data);

#endif
