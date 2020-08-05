#include "fdf.h"

float	mod(float n)
{
	return (n < 0 ? n * -1 : n);
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;

	x_step = x1 - x;
	y_step = y1 - y;

	max = mod(x_step) > mod(y_step) ? mod(x_step) : mod(y_step);
	x_step /= max;
	y_step /= max;

}
