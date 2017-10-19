#include "fdf.h"

int		get_least_significant_bits(t_image *image, int color_value)
{
	int		lsb;

	lsb = -1;
	if (image->endian == BIG_ENDIAN)
		lsb = take_last_bits(image, color_value);
	else if (image->endian == LITTLE_ENDIAN)
		lsb = take_first_bits(image, color_value);
	return (lsb);
}
