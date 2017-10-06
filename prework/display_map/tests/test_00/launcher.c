#include "/Users/ggane/FdF/prework/display_map/inc/fdf.h"
#include <fcntl.h>

static void     create_file_from_a_string(char *original)
{
    int     fd;

    if ((fd = open("copied_map.txt", O_CREAT) < 0))
        return ;
    ft_putstr_fd(original, fd);
    close(fd);
}

int             main(int ac, char **av)
{
    char    *map_copy;

    if (ac != 2)
        return (-1);
    map_copy = copy_map_in_a_string(av[1]); 
    create_file_from_a_string(map_copy);
    return (0);
}
