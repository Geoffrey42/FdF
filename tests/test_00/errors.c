#include "fdf.h"

int     print_error_msg(char *error_msg)
{
    ft_putendl_fd(error_msg, 2);
    return (-1);
}
