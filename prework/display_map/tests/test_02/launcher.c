#include "/Users/ggane/FdF/prework/display_map/inc/fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include "fdf.h"

static int  is_not_valid_non_digit(char c)
{
    if (c != ' ' && c != '-' && c != '\n')
        return (-1);
    return (0);
}

static int  is_invalid_characters(char *map_copy)
{
    int     i;

    i = 0;
    while (map_copy[i])
    {
        if (is_not_valid_non_digit(map_copy[i]) && !ft_isdigit(map_copy[i]))
            return (-1);
        i++;
    }
    return (0);
}

static size_t   get_map_file_size(int fd)
{
    size_t  size;
    char    buf[MAP_BUF_SIZE];

    size = 0;
    while (read(fd, buf, MAP_BUF_SIZE))
        size++;
    return (size);
}

static void     copy_file_content(int fd, char **map_copy)
{
    char    buf[MAP_BUF_SIZE];
    char    *tmp;
    int     i;
    int     ret;

    i = 0;
    tmp = *map_copy;
    while (read(fd, buf, MAP_BUF_SIZE))
        tmp[i++] = buf[0];
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
    if (!(map_copy = (char *)malloc(sizeof(char) * size + 1)))
        return (NULL);
    map_copy[size] = '\0';
    copy_file_content(fd, &map_copy);
    close(fd);
    return (map_copy);
}

int     print_error_msg(char *error_msg)
{
    ft_putendl_fd(error_msg, 2);
    return (-1);
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

int             main(int ac, char **av)
{
    char    *map_copy;

    if (ac != 2)
        return (-1);
    map_copy = copy_map_in_a_string(av[1]);
    printf("Characters from [%s] are ", av[1]);
    if (is_invalid_characters(map_copy))
        printf("invalid !!!!\n");
    else
        printf("valid !\n");
    return (0);
}
