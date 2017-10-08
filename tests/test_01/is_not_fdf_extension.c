#include "fdf.h"

int  is_not_fdf_extension(char *map_name)
{
    char    *extension;

    extension = map_name + ft_strlen(map_name) - 4;
    if (ft_strcmp(extension, ".fdf") != 0)
        return (-1);
    return (0);
}
