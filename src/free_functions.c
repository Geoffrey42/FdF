#include "fdf.h"

static int      erase_2d_array(t_2d **coord_2d)
{
    return (0);
}

static int       erase_3d_array(t_3d **coord_3d)
{
    return (0);
}

int             erase_both_arrays(t_3d **coord_3d, t_2d **coord_2d)
{
    if (!erase_3d_array(coord_3d) || !erase_2d_array(coord_2d))
        return (-1);
}
