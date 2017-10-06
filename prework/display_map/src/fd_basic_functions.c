#include "fdf.h"

static size_t   get_map_file_size(int fd)
{
    size_t  size;
    char    buf[BUFF_SIZE];

    size = 0;
    while (read(fd, buf, BUFF_SIZE))
        size++;
    return (size);
}

static void     copy_file_content(int fd, char **map_copy)
{
    char    buf[BUFF_SIZE + 1];
    int     ret;

    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        *map_copy[i] = buf[0];
        i++;
    }
}

static char     *copy_map_in_a_string(char *map_name)
{
    size_t  size;
    char    *map_copy;
    int     fd;

    fd = get_map_fd(map_name);
    size = get_map_file_size(fd);
    close(fd);
    fd = get_map_fd(map_name);
    map_copy = ft_memalloc(size + 1);
    copy_file_content(fd, &map_copy);
    close(fd);
    return (map_copy);
}

int             get_map_fd(char *map_name)
{
    int     fd;

    fd = open(map_name, O_RDONLY);
    if (fd == -1)
        exit(print_error_msg("open() failed"));
    else
        return (fd);
}
