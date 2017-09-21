#include "mlx.h"
#include <stdio.h>

typedef	struct	s_graph
{
	void		*mlx;
	void		*win;
	const int	spot_1[2];
	const int	spot_2[2];
}				t_graph;

void	draw_line(t_graph *graph)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_pixel_put(graph->mlx, graph->win, x, y, 0x00FFFFFF);
}

int		main(void)
{
	void	*mlx;
	void	*win;
	t_graph	*graph;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "draw_line");
	graph = (t_graph)malloc(sizeof(t_graph *));
	if (!graph)
		return (-1);
	graph->mlx = mlx;
	graph->win = win;
	graph->spot_1 = {3, 9};
	graph->spot_2 = {9, 14};
	mlx_loop(mlx);
	return (0);
}
