#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

typedef struct  s_3d
{
    int         x;
    int         y;
    int         z;
}               t_3d;

typedef struct  s_2d;
{
    int         x;
    int         y;
}               t_2d;

/*
** check.c
*/

int             is_not_a_correct_map(int ac, char **av);

/*
** check.c
*/

int             print_error_msg(char *error_msg);

/*
** fd_basic_functions.c
*/

char            *copy_map_in_a_string(int fd);
int             get_map_fd(char *map_name);

#endif
