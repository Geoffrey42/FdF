#include "fdf.h"

/*
** Doit gerer si :
** 1- le fichier existe
** 2- le fichier contient quelque chose
** 3- le contenu est une map valide
*/

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

int         is_invalid_characters(char *map_copy)
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
