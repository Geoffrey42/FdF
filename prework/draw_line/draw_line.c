#include "fdf.h"
#include <stdio.h>
#include <math.h>

#define DRAW_LINE &draw_ascending_line, &draw_reverse_vertical_line, &draw_reverse_descending_line, &draw_reverse_horizontal_line, &draw_horizontal_line, &draw_reverse_ascending_line, &draw_descending_line, &draw_vertical_line


#define PINK 0x00FF358B
#define WHITE 0x00FFFFFF
#define RED 0x008E3557
#define BLUE 0x004BB5C1
#define BROWN 0x00BD8D46
#define GREEN 0x0096CA2D
#define ORANGE 0x00FEB201
#define YELLOW 0x00F2E203

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
	int		x1;
	int		y1;
	int		x2;
	int		y2;

    x1 = g->spot_1[0];
    y1 = g->spot_1[1];
    x2 = g->spot_2[0];
    y2 = g->spot_2[1];
    printf("ligne ascendante\n");
    print_displayed_color(color);
    printf("spot1 (x : %d, y : %d)\n", g->spot_1[0], g->spot_1[1]);
    printf("spot2 (x : %d, y : %d)\n", g->spot_2[0], g->spot_2[1]);
	x_n = g->spot_1[0];
	while (x_n <= g->spot_2[0])
	{
		//y_n = (g->spot_2[0] - x_n * (g->spot_1[1] - g->spot_2[1])) / (g->spot_2[0] - g->spot_1[0]);
        y_n = ((x_n - x1)  * sqrt(pow(x2 - x1, 2) + pow(y1 - y2, 2))) / (x2 - x1);
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
    printf("spot1 (x : %d, y : %d)\n", g->spot_1[0], g->spot_1[1]);
    printf("spot2 (x : %d, y : %d)\n", g->spot_2[0], g->spot_2[1]);
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
    printf("spot1 (x : %d, y : %d)\n", g->spot_1[0], g->spot_1[1]);
    printf("spot2 (x : %d, y : %d)\n", g->spot_2[0], g->spot_2[1]);
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
    printf("spot1 (x : %d, y : %d)\n", g->spot_1[0], g->spot_1[1]);
    printf("spot2 (x : %d, y : %d)\n", g->spot_2[0], g->spot_2[1]);
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
    printf("spot1 (x : %d, y : %d)\n", g->spot_1[0], g->spot_1[1]);
    printf("spot2 (x : %d, y : %d)\n", g->spot_2[0], g->spot_2[1]);
	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (x_n <= g->spot_2[0])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
		x_n++;
	}
}

/* x1 > x2 && y1 < y2 */
void	draw_reverse_ascending_line(t_graph *g, int color)
{
	int		x_n;
	int		y_n;

    printf("ligne ascendante inversee\n");
    print_displayed_color(color);
    printf("spot1 (x : %d, y : %d)\n", g->spot_1[0], g->spot_1[1]);
    printf("spot2 (x : %d, y : %d)\n", g->spot_2[0], g->spot_2[1]);
	x_n = g->spot_1[0];
	while (x_n >= g->spot_2[0])
	{
		y_n = (g->spot_1[0] + x_n * (g->spot_2[1] - g->spot_1[1])) / g->spot_1[0] - g->spot_2[0];
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
        //printf("x_n : %d - y_n : %d\n", x_n, y_n);
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
    printf("spot1 (x : %d, y : %d)\n", g->spot_1[0], g->spot_1[1]);
    printf("spot2 (x : %d, y : %d)\n", g->spot_2[0], g->spot_2[1]);
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
    printf("spot1 (x : %d, y : %d)\n", g->spot_1[0], g->spot_1[1]);
    printf("spot2 (x : %d, y : %d)\n", g->spot_2[0], g->spot_2[1]);
	x_n = g->spot_1[0];
	y_n = g->spot_1[1];
	while (y_n <= g->spot_2[1])
	{
		mlx_pixel_put(g->mlx, g->win, x_n, y_n, color);
		y_n++;
	}
}
/*
int		choose_draw_function(t_graph *g)
{
    int     x_op;
    int     y_op;
	int		r1;
	int		r2;

	r1 = 0;
	r2 = 5;
    x_op = g->spot_1[0] - g->spot_2[0];
    y_op = g->spot_1[1] - g->spot_2[1];
    if (x_op == 0)
        r1 = 0;
    else if (x_op > 0)
        r1 = 1;
    else
        r1 = 2;
    if (y_op == 0)
        r2 = 5;
    else if (y_op > 0)
        r2 = 3;
    else
        r2 = 4;
	//r1 = (g->spot_1[0] - g->spot_2[0] > 0) ? 1 : 2;
	//r2 = (g->spot_1[1] - g->spot_2[1] > 0) ? 3 : 4;
	printf("r1 : (%d)\n", r1);
	printf("r2 : (%d)\n", r2);
	return (r1 + r2);
}
*/

int     choose_draw_function(t_graph *g)
{
    int     x_op;
    int     y_op;

    x_op = g->spot_1[0] - g->spot_2[0];
    y_op = g->spot_1[1] - g->spot_2[1];
    if (x_op < 0 && y_op < 0)
        return (6);
    else if (x_op == 0 && y_op < 0)
        return (7);
    else if (x_op > 0 && y_op < 0)
        return (5);
    else if (x_op > 0 && y_op == 0)
        return (3);
    else if (x_op < 0 && y_op > 0)
        return (0);
    else if (x_op == 0 && y_op > 0)
        return (1);
    else if (x_op > 0 && y_op > 0)
        return (2);
    else if (x_op < 0 && y_op == 0)
        return (4);
    else
        return (-1);
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
    else if (searched_color == ORANGE)
        printf("orange\n");
    else if (searched_color == YELLOW)
        printf("yellow\n");
}
/*
void	draw_line(t_graph *graph)
{
    int     color[8] = {WHITE, RED, PINK, BLUE, BROWN, GREEN, ORANGE, YELLOW};
	void	(*draw_function_list[8])(t_graph *, int) = {DRAW_LINE};
	int		i;

	i = choose_draw_function(graph);
	printf("i : (%d)\n", i);
    if (i >= 0 && i != 7)
	    draw_function_list[i](graph, color[i]);
}
*/
void	draw_line(t_graph *graph, int color)
{
    int     x1, x2, y1, y2, xn, yn, coef_directeur, ordonnee_a_lorigine;

    x1 = graph->spot_1[0];
    xn = x1;
    x2 = graph->spot_2[0];
    y1 = graph->spot_1[1];
    y2 = graph->spot_2[1];
    print_displayed_color(color);
    if (graph->spot_1[0] == graph->spot_2[0])
    {
        yn = y1;
        if (graph->spot_1[1] > graph->spot_2[1])
        {
            yn = y2;
            xn = x2;
            y2 = graph->spot_1[1];
            y1 = graph->spot_2[1];
        }
        while (yn <= y2)
		    mlx_pixel_put(graph->mlx, graph->win, xn++, yn++, color);
        return ;
    }
    if (graph->spot_1[0] > graph->spot_2[0])
    {
        x1 = graph->spot_2[0];
        xn = x1;
        x2 = graph->spot_1[0];
        y1 = graph->spot_2[1];
        y2 = graph->spot_1[1];
    }
    coef_directeur = (y2 - y1) / (x2 - x1);
    ordonnee_a_lorigine = y1 - coef_directeur * x1;
    while (xn <= x2)
    {
       yn = coef_directeur * xn + ordonnee_a_lorigine;
	   mlx_pixel_put(graph->mlx, graph->win, xn, yn, color);
       xn++;
    }
}

/*
void    draw_line(t_graph *graph)
{
    int     x_n, y_n, dx, dy;
    int     e;

    e = graph->spot_2[0] - graph->spot_1[0];
    x_n = graph->spot_1[0];
    y_n = graph->spot_1[1];
    dx = e * 2;
    dy = (graph->spot_2[1] - graph->spot_1[1]) * 2;
    while (x_n <=  graph->spot_2[0])
    {
		mlx_pixel_put(graph->mlx, graph->win, x_n, y_n, BLUE);
        x_n++;
        if ((e = e - dy) <= 0)
        {
            y_n++;
            e += dx;
        }
    }
}
*/
void	initialize_graph(t_graph graph[8], void *mlx, void *win)
{
    int     i;
    int     j;
    int     s1[8][2] = {{1494,1090},{800,1500},{1000,700},{800,500},{860,800},{400,800},{800,830},{700,900}};
    int     s2[8][2] = {{1939,900},{800,1000},{600,1000},{400,500},{860,400},{800,400},{600,500},{1000,900}};

    i = 0;
    j = 0;
    while (i < 8)
    {
        graph[i].mlx = mlx;
	    graph[i].win = win;
        while (j < 2)
        {
            graph[i].spot_1[0] = s1[i][j];
            graph[i].spot_2[0] = s2[i][j];
            j++;
            graph[i].spot_1[1] = s1[i][j];
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
    int     color[8] = {WHITE, RED, PINK, BLUE, BROWN, GREEN, ORANGE, YELLOW};

    i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 2000, 2000, "draw_line");
	initialize_graph(graph, mlx, win);
    draw_line(&graph[0], color[0]);
    /*
    while (i < 8)
    {
        printf("test %d:\n", i + 1);
        //draw_line(&graph[i++]);
        draw_line(&graph[i], color[i]);
        i++;
        printf("-----------------\n");
    }*/
	mlx_loop(mlx);
	return (0);
}
