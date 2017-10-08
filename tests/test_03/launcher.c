#include "/Users/ggane/FdF/prework/display_map/inc/fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include "fdf.h"

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

static int  get_spaces_nb(char *line)
{
    int     i;
    int     space_nb;

    i = 0;
    space_nb = 0;
    while (line[i])
    {
        if (line[i] == ' ' && line[i - 1] != ' ' && i != 0)
            space_nb++;
        i++;
    }
    return (space_nb);
}

static int  is_invalid_lines(char *map_name)
{
    int     fd;
    int     spaces_nb;
    char    *line;
    int     actual_line_spaces_nb;
    int     i;

    i = 0;
    fd = get_map_fd(map_name);
    get_next_line(fd, &line);
    spaces_nb = get_spaces_nb(line);
    while (get_next_line(fd, &line) != 0)
    {
        actual_line_spaces_nb = get_spaces_nb(line);
        if (actual_line_spaces_nb != spaces_nb)
        {
            close(fd);
            return (-1);
        }
        i++;
    }
    close(fd);
    return (0);
}

int             main(int ac, char **av)
{
    char    *map_copy;

    if (ac != 2)
        return (-1);
    printf("Lines from [%s] are ", av[1]);
    if (is_invalid_lines(av[1]))
        printf("not the same size!!!!\n");
    else
        printf("valid !\n");
    return (0);
}
