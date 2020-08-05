#include "fdf.h"
#include <math.h>

float	mod(float n)
{
	return (n < 0 ? n * -1 : n);
}

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z;
	int		z1;

	z = fdf->z_matrix[(int)y][(int)x];
	z1 = fdf->z_matrix[(int)y1][(int)x1];
//	ft_printf("before start bresenham\n\n");
//	ft_printf("x=%f|y=%f\n", x, y);
//	ft_printf("x1=%f|y1=%f\n", x, y);
	// zoom
	x *= fdf->zoom;
	y *= fdf->zoom;
	x1 *= fdf->zoom;
	y1 *= fdf->zoom;

//	ft_printf("setted zoom bresenham\n\n");
//	ft_printf("x=%f|y=%f\n", x, y);
//	ft_printf("x1=%f|y1=%f\n", x, y);
	// color

	fdf->color = (z || z1) ? RED : WHITE;
//	ft_printf("color setted\n\n");

	if (fdf->isometric)
	{
		isometric(&x, &y, z);
		isometric(&x1, &y1, z1);
	}

	x += fdf->shift_x;
	y += fdf->shift_y;
	x1 += fdf->shift_x;
	y1 += fdf->shift_y;
	out_of_bounds(&x, &y);
	// step
	x_step = x1 - x;
	y_step = y1 - y;
	max = mod(x_step) > mod(y_step) ? mod(x_step) : mod(y_step);
	x_step /= max;
	y_step /= max;
//	ft_printf("start bresenham\n\n");
	while ((int)(x1 - x) || (int)(y1 - y))
	{
//		ft_printf("x=%f|y=%f\n", x, y);
//		ft_printf("x1=%f|y1=%f\n", x, y);
		if (x > 1000 || y > 1000 || y < 0 || x < 0)
			break ;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
		x += x_step;
		y += y_step;

	}
//	ft_printf("end bresenham\n\n\n");
}

void	draw(t_fdf *fdf)
{
	float	x;
	float	y;

	y = 0;
//	ft_printf("draw\n");
//	ft_printf("%d %d\n", fdf->height, fdf->width);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				bresenham(x, y, x + 1, y, fdf);
			if (y < fdf->height - 1)
				bresenham(x, y, x, y + 1, fdf);
			x++;
		}
		y++;
		ft_printf("endofiter\n\n\n");
	}
}
