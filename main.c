#include "mlx.h"

int		main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
			mlx_pixel_put(mlx, win, x++, y, 0x00FFFFFF);
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
