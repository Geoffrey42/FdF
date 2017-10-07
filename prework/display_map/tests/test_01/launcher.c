#include "/Users/ggane/FdF/prework/display_map/inc/fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include "fdf.h"

int  is_not_fdf_extension(char *map_name)
{
    char    *extension;

    extension = map_name + ft_strlen(map_name) - 4;
    printf("extension : [%s]\n", extension);
    if (ft_strcmp(extension, ".fdf") != 0)
        return (-1);
    return (0);
}

int             main(int ac, char **av)
{
    if (ac != 2)
        return (-1);
    printf("Le fichier [%s] ", av[1]);
    if (is_not_fdf_extension(av[1]))
        ft_putendl("n'est pas un .fdf");
    else
        ft_putendl("est bien au format .fdf");
    return (0);
}
