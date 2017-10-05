#include "fdf.h"

size_t  get_map_file_size(int fd)
{
    size_t  size;

    while ((ret = read(fd, buf, 1)))
    return (size);
}

char   *copy_map_in_a_string(int fd)
{
    int     ret;
    char    *buf;
    size_t  size;

    size = get_map_file_size(fd);
}

int     get_map_fd(char *map_name)
{
    int     fd;

    fd = open(map_name, O_RDONLY);
    if (fd == -1)
        exit(print_error_msg("open() failed"));
    else
        return (fd);
}
