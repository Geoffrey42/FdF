#include "fdf.h"

static int		take_last_bits(int bpp, int color_value)
{
	int		lsb;
	char	*buf;

	buf = ft_itoa(color_value);
	lsb = ft_atoi(buf + (ft_strlen(buf) - (size_t)bpp)); 
	ft_strdel(&buf);
	return (lsb);
}

static int		take_first_bits(int bpp, int color_value)
{
	int		lsb;

	ft_putstr("color_value : ");
	ft_putnbrdl(color_value);
	//lsb = ft_atoi(copy); 
	lsb = color_value & 1;
	ft_putstr("lsb : ");
	ft_putnbrdl(lsb);
	return (lsb);
}

int				get_least_significant_bits(t_image *image, int color_value)
{
	int		lsb;

	lsb = -1;
	if (image->endian == THE_BIG_ENDIAN)
		lsb = take_last_bits(image->bpp, color_value);
	else if (image->endian == THE_LITTLE_ENDIAN)
		lsb = take_first_bits(image->bpp, color_value);
	return (lsb);
}
