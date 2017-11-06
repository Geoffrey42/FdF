#include "fdf.h"

static void		draw_ascending_line(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	int		xn, yn;

	xn = x1;
	yn = y1;
	while (xn <= x2)
	{
		yn = (((xn - x1) * (y2 - y1)) / (x2 - x1));
		mlx_pixel_put(mlx, win, xn++, y1 + yn, WHITE);
	}
}

static void		draw_descending_line(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	int		xn, yn;

	xn = x1;
	yn = y1;
	while (xn <= x2)
	{
		yn = y2 - (((x2 - xn) * (y2 - y1)) / (x2 - x1));
		mlx_pixel_put(mlx, win, xn++, yn, WHITE);
	}
}

static void		draw_horizontal_line(void *mlx, void *win, int x1, int y1, int x2)
{
	int		xn;

	xn = x1;
	while (xn <= x2)
		mlx_pixel_put(mlx, win, xn++, y1, WHITE);
}

static void		draw_vertical_line(void *mlx, void *win, int x1, int y1, int y2)
{
	int		yn;

	yn = y1;
	while (yn <= y2)
		mlx_pixel_put(mlx, win, x1, yn++, WHITE);
}

void			draw_a_line(t_data *data, int x1, int y1, int x2, int y2)
{
	if (x1 < x2 && y1 > y2)
		draw_ascending_line(data->mlx, data->win, x1, y1, x2, y2);
	else if (x1 > x2 && y1 < y2)
		draw_ascending_line(data->mlx, data->win, x2, y2, x1, y1);
	else if (x1 < x2 && y1 < y2)
		draw_descending_line(data->mlx, data->win, x1, y1, x2, y2);
	else if (x1 > x2 && y1 > y2)
		draw_descending_line(data->mlx, data->win, x2, y2, x1, y1);
	else if (x1 < x2 && y1 == y2)
		draw_horizontal_line(data->mlx, data->win, x1, y1, x2);
	else if (x1 > x2 && y1 == y2)
		draw_horizontal_line(data->mlx, data->win, x2, y2, x1);
	else if (x1 == x2 && y1 < y2)
		draw_vertical_line(data->mlx, data->win, x1, y1, y2);
	else if (x1 == x2 && y1 > y2)
		draw_vertical_line(data->mlx, data->win, x2, y2, y1);
}
