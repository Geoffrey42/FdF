#include "../../inc/fdf.h"
#include <stdio.h>

#define DRAW_LINE &draw_ascending_line, draw_reverse_vertical_line, &draw_reverse_descending_line, &draw_reverse_horizontal_line, &draw_horizontal_line, &draw_reverse_ascending_line, &draw_descending_line, &draw_vertical_line


typedef	struct	s_graph
{
	void		*mlx;
	void		*win;
	int			spot_1[2];
	int			spot_2[2];
}				t_graph;

/* x1 < x2 && y1 >y2 */
void	draw_ascending_line(t_graph *g)
{
	int		x_n;
	int		y_n;

	x_n = g->spot_1[0];
	while (x_n <= g->spot_2[0])
	{
		y_n = (g->spot_1[0] + x_n * g->spot_1[1] - g->spot_2[1]) / g->spot_2[0] - g->spot_1[0];
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, 0x00FFFFFF);
		x_n++;
	}
}

/* x1 == x2 && y1 > y2 */
void	draw_reverse_vertical_line(t_graph *g)
{
	int		x_n;
	int		y_n;

	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (y_n >= g->spot_2[1])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, 0x00FFFFFF);
		y_n--;
	}
}

/* x1 > x2 && y1 > y2 */
void	draw_reverse_descending_line(t_graph *g)
{
	int		x_n;
	int		y_n;

	x_n = g->spot_1[0];
	while (x_n >= g->spot_2[0])
	{
		y_n = (g->spot_1[0] + x_n * g->spot_2[1] - g->spot_1[1]) / g->spot_1[0] - g->spot_2[0];
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, 0x00FFFFFF);
		x_n--;
	}
}

/* x1 > x2 && y1 == y2 */
void	draw_reverse_horizontal_line(t_graph *g)
{
	int		x_n;
	int		y_n;

	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (x_n >= g->spot_2[0])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, 0x00FFFFFF);
		x_n--;
	}
}

/* x1 < x2 && y1 == y2 */
void	draw_horizontal_line(t_graph *g)
{
	int		x_n;
	int		y_n;

	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (x_n >= g->spot_2[0])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, 0x00FFFFFF);
		x_n--;
	}
}

/* x1 > x2 && y1 < y2 */
void	draw_reverse_ascending_line(t_graph *g)
{
	int		x_n;
	int		y_n;

	x_n = g->spot_1[0];
	while (x_n >= g->spot_2[0])
	{
		y_n = (g->spot_1[0] + x_n * g->spot_2[1] - g->spot_1[1]) / g->spot_1[0] - g->spot_2[0];
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, 0x00FFFFFF);
		x_n--;
	}
}

/* x1 < x2 && y1 < y2 */
void	draw_descending_line(t_graph *g)
{
	int		x_n;
	int		y_n;

	x_n = g->spot_1[0];
	while (x_n <= g->spot_2[0])
	{
		y_n = (g->spot_1[0] + x_n * g->spot_2[1] - g->spot_1[1]) / g->spot_2[0] - g->spot_1[0];
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, 0x00FFFFFF);
		x_n++;
	}
}

/* x1 == x2 && y1 < y2 */
void	draw_vertical_line(t_graph *g)
{
	int		x_n;
	int		y_n;

	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (y_n <= g->spot_2[1])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, 0x00FFFFFF);
		y_n++;
	}
}

int		choose_draw_function(t_graph *g)
{
	int		r1;
	int		r2;

	r1 = 0;
	r2 = 5;
	r1 = (g->spot_1[0] - g->spot_2[0] > 0) ? 1 : 2;
	r2 = (g->spot_1[1] - g->spot_2[1] > 0) ? 3 : 4;
	printf("r1 : (%d)\n", r1);
	printf("r2 : (%d)\n", r2);
	return (r1 + r2);
}

void	draw_line(t_graph *graph)
{
	void	(*draw_function_list[8])(t_graph *) = {DRAW_LINE};
	int		i;

	i = choose_draw_function(graph);
	printf("i : (%d)\n", i);
	draw_function_list[i](graph);
}

void	initialize_graph(t_graph **graph, void *mlx, void *win)
{
	(*graph)->mlx = mlx;
	(*graph)->win = win;
	(*graph)->spot_1[0] = 100;
	(*graph)->spot_1[1] = 50;
	(*graph)->spot_2[0] = 50;
	(*graph)->spot_2[1] = 100;
}

int		main(void)
{
	void	*mlx;
	void	*win;
	t_graph	*graph;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "draw_line");
	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (-1);
	initialize_graph(&graph, mlx, win);
	draw_line(graph);
	mlx_loop(mlx);
	return (0);
}
