#include "fdf.h"

static size_t   get_digit_size(char *map, int i)
{
    size_t      size;

    size = go_to_last_digit(map, i) - (size_t)i;
    return (size);
}

int             get_whole_number(char *map, int i)
{
    char    *to_convert;
    int     z;
    int     j;

    j = 0;
    if (!(to_convert = (char *)ft_memalloc(sizeof(char) * get_digit_size( \
    map, i) + 1)))
        return (NULL);
    while (ft_isdigit(map[i]))
    {
        to_convert[j] = map[i];
        j++;
        i++;
    }
    to_convert[j] = '\0';
    z = ft_atoi(to_convert);
    return (z);
}

int             is_more_than_single_digit(char *map, int i)
{
    if (ft_isdigit(map[i + 1]))
        return (1);
    return (0);
}

int             go_to_last_digit(char *map, int i)
{
    while (ft_isdigit(map[i + 1]))
        i++;
    return (i);
}
