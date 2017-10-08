#include "fdf.h"

int		main(int ac, char **av)
{
    t_3d    raw_coordinates;
    t_2d    converted_coordinates;
    void    *image_id;

    if (is_not_a_correct_map(ac, av))
        return (-1);
    raw_coordinates = get_map_coordinates(av[1]); // en cours
    converted_coordinates = convert_3d_coordinates_for_isometric_projection( \
            raw_coordinates);
    image_id = get_image_from(converted_coordinates);
    display_image_in_window(image_id);
	return (0);
}
