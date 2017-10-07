#include "fdf.h"

/*
** Doit gerer si :
** 1- le fichier existe
** 2- le fichier contient quelque chose
** 3- le contenu est une map valide
*/

static int  get_spaces_nb(char *line)
{
    int     i;
    int     space_nb;

    i = 0;
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
    while (get_next_line(fd, &line) != 0)
    {
        if (get_spaces_nb(line) != spaces_nb)
        {
            close(fd);
            return (-1);
        }
    }
    close(fd);
    return (0);
}

static int  is_not_fdf_extension(char *map_name)
{
    char    *extension;

    extension = map_name + ft_strlen(map_name) - 4;
    if (ft_strcmp(extension, ".fdf") != 0)
        return (-1);
    return (0);
}

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

static int  is_not_valid_format(char *map_name)
{
    char    *map_copy;

    if (is_not_fdf_extension(map_name)
        return (-1);
    map_copy = copy_map_in_a_string(map_name);
    if (is_invalid_characters(map_copy))
        return (-1);
    else if (is_invalid_lines(map_copy))
        return (-1);
    return (0);
}

int     is_not_a_correct_map(int ac, char **av)
{
    if (ac > 2)
        return (print_error_msg("invalid number of arguments"));
    else if (!av[1])
        return (print_error_msg("file is NULL"));
    else if (is_not_valid_map_format(av[1]))
        return (print_error_msg("invalid map format"));
    else
        return (0);
}
