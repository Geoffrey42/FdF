#include "fdf.h"

void	draw_line_with_bresenham(t_data *data, t_dot *p1, t_dot *p2)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;

	dx = abs(p2->x - p1->x);
	dy = -abs(p2->y - p1->y);
	sx = p1->x < p2->x ? 1 : -1;
	sy = p1->y < p2->y ? 1 : -1;
	err = dx + dy;

	while (1)
	{
		data->draw_pixel(data, p1->x, p1->y);
		if (p1->x == p2->x && p1->y == p2->y)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			p1->x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			p1->y += sy;
		}
	}
}

/*
void	draw_line_with_bresenham(t_data *data, t_dot *p1, t_dot *p2)
{
	int		dx;
	int		dy;
	int		e;

	if ((dx = p2->x - p1->x))
	{
		if (dx > 0)
		{
			if ((dy = p2->y - p1->y))
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (1) // deplacements horizontaux
						{
							data->pixel_function(data, p1->x, p1->y);
							if ((p1->x = p1->x + 1) == p2->x)
								break ;
							if ((e = e - dy) < 0)
							{
								p1->y++; // deplacement diagonal
								e += dx;
							}
						}
					}
					else
					{
						// vecteur oblique proche verticale ds 2e octant
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1) // deplacements verticaux
						{
							data->pixel_function(data, p1->x, p1->y);
							if ((p1->y = p1->y + 1) == p2->y)
								break ;
							if ((e = e - dx) < 0)
							{
								p1->x++; // deplacement diagonal
								e += dy;
							}
						}
					}
				}
				else if (dy < 0 && dx > 0)
				{
					// vecteur oblique dans le 4e cadran
					if (dx >= -dy)
					{
						// vecteur diagonal ou oblique proche horizontale ds 8e octant
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (1) // deplacements horizontaux
						{
							data->pixel_function(data, p1->x, p1->y);
							if ((p1->x = p1->x + 1) == p2->x)
								break ;
							if ((e = e + dy) < 0)
							{
								p1->y--; // deplacement diagonal
								e += dx;
							}
						}
					}
					else // vecteur oblique proche verticale 7e octant
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1)
						{
							data->pixel_function(data, p1->x, p1->y);
							if ((p1->y = p1->y - 1) == p2->y)
								break ;
							if ((e = e + dx) > 0)
							{
								p1->x++;
								e += dy;
							}
						}
					}
				}
			}
			else if (dy == 0 && dx > 0)
			{
				while (p1->x != p2->x)
					data->pixel_function(data, p1->x++, p1->y);
			}
			else if (dx < 0)
			{
				if ((dy = p2->y - p1->y))
				{
					if (dy > 0)
					{
						if (-dx >= dy)
						{
							e = dx;
							dx = e * 2;
							dy *= 2;
							while (1)
							{
								data->pixel_function(data, p1->x, p1->y);
								if ((p1->x = p1->x - 1) == p2->x)
									break ;
								if ((e = e + dy) >= 0)
								{
									p1->y++;
									e += dx;
								}
							}
						}
						else
						{
							// vecteur oblique proche verticale 3e octant
							e = dy;
							dy = e * 2;
							dx *= 2;
							while (1)
							{
								data->pixel_function(data, p1->x, p1->y);
								if ((p1->y = p1->y + 1) == p2->y)
									break ;
								if ((e = e + dx) <= 0)
								{
									p1->x--;
									e += dy;
								}
							}
						}
					}
					else if (dy < 0 && dx < 0)
					{
						// vecteur oblique ds 3e cadran
						if (dx <= dy)
						{
							e = dx;
							dx = e * 2;
							dy *= 2;
							while (1)
							{
								data->pixel_function(data, p1->x, p1->y);
								if ((p1->x = p1->x - 1) == p2->x)
									break ;
								if ((e = e - dy) >= 0)
								{
									p1->y--;
									e += dx;
								}
							}
						}
						else
						{
							e = dy;
							dy = e * 2;
							dx *= 2;
							while (1)
							{
								data->pixel_function(data, p1->x, p1->y);
								if ((p1->y = p1->y - 1) == p2->y)
									break ;
								if ((e = e - dx) >= 0)
								{
									p1->x--;
									e += dy;
								}
							}
						}
					}
				}
				else if (dy == 0 && dx < 0)
				{
					while ((p1->x = p1->x - 1) == p2->x)
						data->pixel_function(data, p1->x, p1->y);
				}
			}
			else if (dx == 0)
			{
				if ((dy = p2->y - p1->y))
				{
					if (dy > 0)
					{
						while ((p1->y = p1->y + 1) == p2->y)
							data->pixel_function(data, p1->x, p1->y);
					}
					else if (dy < 0 && dx == 0)
					{
						while ((p1->y = p1->y - 1) == p2->y)
							data->pixel_function(data, p1->x, p1->y);
					}
				}
			}
		}
	}
	data->pixel_function(data, p2->x, p2->y);
}
*/
