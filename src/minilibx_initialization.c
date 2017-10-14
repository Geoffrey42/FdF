#include "fdf.h"

t_mlx   *initialize_minilibx(void)
{
	t_mlx	*data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	data->mlx = mlx_init();
	return (data);
}
