#include "fdf.h"

/*
** Doit gerer si :
** 1- le fichier existe
** 2- le fichier contient quelque chose
** 3- le contenu est une map valide
*/

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
