#include "fdf.h"

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

    fd = get_map_fd(map_name);
    get_next_line(fd, &line);
    spaces_nb = get_spaces_nb(line);
    ft_strdel(&line);
    while (get_next_line(fd, &line) != 0)
    {
        if (get_spaces_nb(line) != spaces_nb)
        {
            close(fd);
            ft_strdel(&line);
            return (-1);
        }
    }
    close(fd);
    ft_strdel(&line);
    return (0);
}

static int  is_not_valid_format(char *map_name)
{
    char    *map_copy;
    int     ret;

    ret = 0;
    if (is_not_fdf_extension(map_name))
        ret = -1;
    else
        map_copy = copy_map_in_a_string(map_name);
    if (ft_strlen(map_copy) == 0 || ft_strlen(map_copy) == 1)
        ret = -1;
    else if (is_invalid_characters(map_copy))
        ret = -1;
    else if (is_invalid_lines(map_name))
        ret = -1;
    ft_strdel(&map_copy);
    return (ret);
}

int     is_not_a_correct_map(int ac, char **av)
{
    if (ac != 2)
        return (print_error_msg("invalid number of arguments"));
    else if (is_not_valid_format(av[1]))
        return (print_error_msg("invalid map format"));
    else
        return (0);
}
