#include "mlx.h"
#include <stdio.h>

int		my_key_funct(int keycode, void *param)
{
	void	*tmp;

	tmp = param;
	return(printf("key event %d\n", keycode));
}

void	display_odd_colors(void *mlx, void *win, int x, int y)
{
	int		color;

	if (x % 2 == 0)
		color = 0x00FFFFFF;
	else
		color = 0x00FF0000;
	mlx_pixel_put(mlx, win, x, y, color);
}

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
			display_odd_colors(mlx, win, x++, y);
		y++;
	}
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}
