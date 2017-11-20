#include "fdf.h"

int		get_max_coordinate(int coord_1, int coord_2)
{
	if (coord_1 > coord_2)
		return (coord_1);
	else
		return (coord_2);
}

int		get_min_coordinate(int coord_1, int coord_2)
{
	if (coord_1 < coord_2)
		return (coord_1);
	else
		return (coord_2);
}
