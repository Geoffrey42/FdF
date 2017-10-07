#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
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

int             is_invalid_characters(char *map_copy);

/*
** errors.c
*/

int             print_error_msg(char *error_msg);

/*
** fd_basic_functions.c
*/

int             get_map_fd(char *map_name);

#endif
