#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# define MAP_BUF_SIZE 1

typedef struct  s_3d
{
    int         x;
    int         y;
    int         z;
}               t_3d;

typedef struct  s_2d
{
    int         x;
    int         y;
}               t_2d;

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
** isometric_projection.c
*/

t_2d            **convert_3d_coordinates_for_isometric_projection(
                t_3d **raw_coordinates);

/*
** image_management.c
*/

void            *get_image_from(t_2d **converted_coordinates);

/*
** window_display.c
*/

void            display_image_in_window(void *image_id);

/*
** parsing_utils.c
*/

int             get_whole_number(char *map, int i);
int             is_more_than_single_digit(char *map, int i);
int             go_to_last_digit(char *map, int i);

/*
** free_functions.c
*/

int             erase_both_arrays(t_3d **coord_3d, t_2d **coord_2d);

#endif