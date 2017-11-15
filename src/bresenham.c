#include "fdf.h"

void	draw_line_with_bresenham(t_data *data, t_dot *p1, t_dot *p2)
{
	int		xn;
	int		yn;
	int		e;

	if ((xn = p2->x - p1->x))
	{
		if (xn > 0)
		{
			if ((yn = p2->y - p1->y))
			{
				if (yn > 0)
				{
					if (xn >= yn)
					{
						e = xn;
						xn *= 2;
						yn *= 2;
						while (1)
						{
							data->pixel_function(data, p1->x, p1->y);
							if ((p1->x = p1->x + 1) == p2->x)
								break ;
							if ((e = e - yn) < 0)
							{
								p1->y++;
								e += xn;
							}
						}
					}
					else
					{
						e = yn;
						yn *= 2;
						xn *= 2;
						while (1)
						{
							data->pixel_function(data, p1->x, p1->y);
							if ((p1->y = p1->y + 1) == p2->y)
								break ;
							if ((e = e - xn) < 0)
							{
								p1->x++;
								e += yn;
							}
						}
					}
				}
				else if (yn < 0 && xn > 0)
				{
					// vecteur oblique dans le 4e cadran
					if (xn >= -yn)
					{
						e = xn;
						xn *= 2;
						yn *= 2;
						while (1)
						{
							data->pixel_function(data, p1->x, p1->y);
							if ((p1->x = p1->x + 1) == p2->x)
								break ;
							if ((e = e + yn) < 0)
							{
								p1->y--;
								e += xn;
							}
						}
					}
					else
					{
						e = yn;
						yn *= 2;
						xn *= 2;
						while (1)
						{
							data->pixel_function(data, p1->x, p1->y);
							if ((p1->y = p1->y - 1) = p2->y)
								break ;
							if ((e += xn) > 0)
							{
								p1->x++;
								e += yn;
							}
						}
					}
				}
			}
			else if (yn == 0 && xn > 0)
			{
				while ((p1->x = p1->x + 1) == p2->x)
					data->pixel_function(data, p1->x, p1->y);
			}
			else if (xn < 0)
			{
				if ((yn = p2->y - p1->y))
				{
					if (yn > 0)
					{
						if (-xn >= yn)
						{
							e = xn;
							xn *= 2;
							yn *= 2;
							while (1)
							{
								data->pixel_function(data, p1->x, p1->y);
								if ((p1->x = p1->x - 1) == p2->x)
									break ;
								if ((e = e + yn) >= 0)
								{
									p1->y++;
									e += xn;
								}
							}
						}
						else
						{
							// vecteur oblique proche verticale 3e octant
							e = yn;
							yn *= 2;
							xn *= 2;
							while (1)
							{
								data->pixel_function(data, p1->x, p1->y);
								if ((p1->y = p1->y + 1) == p2->y)
									break ;
								if ((e = e + xn) <= 0)
								{
									p1->x--;
									e += yn;
								}
							}
						}
					}
					else if (yn < 0 && xn < 0)
					{
						// vecteur oblique ds 3e cadran
						if (xn <= yn)
						{
							e = xn;
							xn *= 2;
							yn *= 2;
							while (1)
							{
								data->pixel_function(data, p1->x, p1->y);
								if ((p1->x = p1->x - 1) == p2->x)
									break ;
								if ((e = e - yn) >= 0)
								{
									p1->y--;
									e += xn;
								}
							}
						}
						else
						{
							e = yn;
							yn *= 2;
							xn *= 2;
							while (1)
							{
								data->pixel_function(data, p1->x, p1->y);
								if ((p1->y = p1->y - 1) == p2->y)
									break ;
								if ((e = e - xn) >= 0)
								{
									p1->x++;
									e += yn;
								}
							}
						}
					}
				}
				else if (yn == 0 && xn < 0)
				{
					while ((p1->x = p1->x - 1) == p2->x)
						data->pixel_function(data, p1->x, p1->y);
				}
			}
			else if (xn == 0)
			{
				if ((yn = p2->y - p1->y))
				{
					if (yn > 0)
					{
						while ((p1->y = p1->y + 1) == p2->y)
							data->pixel_function(data, p1->x, p1->y);
					}
					else if (yn < 0 && xn == 0)
					{
						while ((p1->y = p1->y - 1) == p2->y)
							data->pixel_function(data, p1->x, p1->y);
					}
				}
			}
		}
	}
}
