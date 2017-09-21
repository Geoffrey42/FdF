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
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_pixel_put(graph->mlx, graph->win, x, y, 0x00FFFFFF);
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
