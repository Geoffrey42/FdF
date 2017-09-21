#include "../../inc/fdf.h"

typedef	struct	s_graph
{
	void		*mlx;
	void		*win;
	int			spot_1[2];
	int			spot_2[2];
}				t_graph;

void	draw_line(t_graph *graph)
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		x_n;
	int		y_n;

	x_n = graph->spot_1[0];
	x1 = graph->spot_1[0];
	y1 = graph->spot_1[1];
	x2 = graph->spot_2[0];
	y2 = graph->spot_2[1];
	while (x_n <= x2)
	{
		y_n = (x1 + x_n * y2 - y1) / x2 - x1;
		mlx_pixel_put(graph->mlx, graph->win, x_n, y_n, 0x00FFFFFF);
		x_n++;
	}
}

void	initialize_graph(t_graph **graph, void *mlx, void *win)
{
	(*graph)->mlx = mlx;
	(*graph)->win = win;
	(*graph)->spot_1[0] = 3;
	(*graph)->spot_1[1] = 9;
	(*graph)->spot_2[0] = 9;
	(*graph)->spot_2[1] = 14;
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
