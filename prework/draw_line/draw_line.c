#include "fdf.h"
#include <stdio.h>

#define DRAW_LINE &draw_ascending_line, &draw_reverse_vertical_line, &draw_reverse_descending_line, &draw_reverse_horizontal_line, &draw_horizontal_line, &draw_reverse_ascending_line, &draw_descending_line, &draw_vertical_line


#define PINK 0x00FF358B
#define WHITE 0x00FFFFFF
#define RED 0x00B9121B
#define BLUE 0x004BB5C1
#define BROWN 0x00BD8D46
#define GREEN 0x0096CA2D
#define DARK_BLUE 0x0046380
#define PURPLE 0x008E3557

typedef	struct	s_graph
{
	void		*mlx;
	void		*win;
	int			spot_1[2];
	int			spot_2[2];
}				t_graph;

void    print_displayed_color(int searched_color);

/* x1 < x2 && y1 >y2 */
void	draw_ascending_line(t_graph *g, int color)
{
	int		x_n;
	int		y_n;

    printf("ligne ascendante\n");
    print_displayed_color(color);
	x_n = g->spot_1[0];
	while (x_n <= g->spot_2[0])
	{
		y_n = (g->spot_1[0] + x_n * g->spot_1[1] - g->spot_2[1]) / g->spot_2[0] - g->spot_1[0];
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
		x_n++;
	}
}

/* x1 == x2 && y1 > y2 */
void	draw_reverse_vertical_line(t_graph *g, int color)
{
	int		x_n;
	int		y_n;

    printf("ligne verticale inversee\n");
    print_displayed_color(color);
	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (y_n >= g->spot_2[1])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
		y_n--;
	}
}

/* x1 > x2 && y1 > y2 */
void	draw_reverse_descending_line(t_graph *g, int color)
{
	int		x_n;
	int		y_n;

    printf("ligne descendante inversee\n");
    print_displayed_color(color);
	x_n = g->spot_1[0];
	while (x_n >= g->spot_2[0])
	{
		y_n = (g->spot_1[0] + x_n * g->spot_2[1] - g->spot_1[1]) / g->spot_1[0] - g->spot_2[0];
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
		x_n--;
	}
}

/* x1 > x2 && y1 == y2 */
void	draw_reverse_horizontal_line(t_graph *g, int color)
{
	int		x_n;
	int		y_n;

    printf("ligne horizontale inversee\n");
    print_displayed_color(color);
	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (x_n >= g->spot_2[0])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
		x_n--;
	}
}

/* x1 < x2 && y1 == y2 */
void	draw_horizontal_line(t_graph *g, int color)
{
	int		x_n;
	int		y_n;

    printf("ligne horizontale\n");
    print_displayed_color(color);
	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (x_n >= g->spot_2[0])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
		x_n--;
	}
}

/* x1 > x2 && y1 < y2 */
void	draw_reverse_ascending_line(t_graph *g, int color)
{
	int		x_n;
	int		y_n;

    printf("ligne ascendante inversee\n");
    print_displayed_color(color);
	x_n = g->spot_1[0];
	while (x_n >= g->spot_2[0])
	{
		y_n = (g->spot_1[0] + x_n * g->spot_2[1] - g->spot_1[1]) / g->spot_1[0] - g->spot_2[0];
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
		x_n--;
	}
}

/* x1 < x2 && y1 < y2 */
void	draw_descending_line(t_graph *g, int color)
{
	int		x_n;
	int		y_n;

    printf("ligne descendante\n");
    print_displayed_color(color);
	x_n = g->spot_1[0];
	while (x_n <= g->spot_2[0])
	{
		y_n = (g->spot_1[0] + x_n * g->spot_2[1] - g->spot_1[1]) / g->spot_2[0] - g->spot_1[0];
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
		x_n++;
	}
}

/* x1 == x2 && y1 < y2 */
void	draw_vertical_line(t_graph *g, int color)
{
	int		x_n;
	int		y_n;

    printf("ligne verticale\n");
    print_displayed_color(color);
	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (y_n <= g->spot_2[1])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
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

void    print_displayed_color(int searched_color)
{
    printf("color : ");
    if (searched_color == PINK)
        printf("pink\n");
    else if (searched_color == WHITE)
        printf("white\n");
    else if (searched_color == RED)
        printf("red\n");
    else if (searched_color == BLUE)
        printf("blue\n");
    else if (searched_color == BROWN)
        printf("brown\n");
    else if (searched_color == GREEN)
        printf("green\n");
    else
        printf("dark blue\n");
}

void	draw_line(t_graph *graph)
{
    int     color[8] = {WHITE, RED, PINK, BLUE, BROWN, GREEN, DARK_BLUE, PURPLE};
	void	(*draw_function_list[8])(t_graph *, int) = {DRAW_LINE};
	int		i;

	i = choose_draw_function(graph);
	printf("i : (%d)\n", i);
	draw_function_list[i](graph, color[i]);
}

void	initialize_graph(t_graph graph[8], void *mlx, void *win)
{
    int     i;
    int     j;
    int     s1[8][2] = {{150,300},{500,800},{800,500},{800,500},{800,800},{500,800},{500,800},{500,800}};
    int     s2[8][2] = {{300,150},{500,800},{800,500},{800,500},{800,800},{500,800},{500,800},{500,800}};

    i = 0;
    j = 0;
    while (i < 8)
    {
        graph[i].mlx = mlx;
	    graph[i].win = win;
        while (j < 2)
        {
            graph[i].spot_1[0] = s1[i][j];
            graph[i].spot_1[1] = s1[i][j];
            graph[i].spot_2[0] = s2[i][j];
            graph[i].spot_2[1] = s2[i][j];
            j++;
        }
        j = 0;
        i++;
    }
}

int		main(void)
{
	void	*mlx;
	void	*win;
	t_graph	graph[8];
    int     i;

    i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 2000, 2000, "draw_line");
	initialize_graph(graph, mlx, win);
    while (i < 8)
    {
        printf("cas numero : %d\n", i + 1);
        draw_line(&graph[i++]);
        printf("-----------------\n");
    }
	mlx_loop(mlx);
	return (0);
}
