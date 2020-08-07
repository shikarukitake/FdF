/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:57:13 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/06 18:57:15 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

t_cord		get_step(t_cord cords, float x1, float y1)
{
	t_cord	step;
	float	max;

	step.x = x1 - cords.x;
	step.y = y1 - cords.y;
	max = mod(step.x) > mod(step.y) ? mod(step.x) : mod(step.y);
	step.x /= max;
	step.y /= max;
	return (step);
}

void		my_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		i++;
		fdf->data_addr[i] = color >> 8;
		i++;
		fdf->data_addr[i] = color >> 16;
	}
}

void		put_pixel(t_cord cords, float x1, float y1, t_fdf *fdf)
{
	t_cord	step;

	step = get_step(cords, x1, y1);
	while ((int)(x1 - cords.x) || (int)(y1 - cords.y))
	{
		my_put_pixel(fdf, cords.x, cords.y, 16777215);
		cords.x += step.x;
		cords.y += step.y;
	}
}

void		bresenham(t_cord cords, float x1, float y1, t_fdf *fdf)
{
	int		z;
	int		z1;

	z = fdf->z_matrix[(int)cords.y][(int)cords.x] * fdf->zoom;
	z1 = fdf->z_matrix[(int)y1][(int)x1] * fdf->zoom;
	cords.x *= fdf->zoom;
	cords.y *= fdf->zoom;
	x1 *= fdf->zoom;
	y1 *= fdf->zoom;
	if (fdf->isometric)
	{
		isometric(&cords.x, &cords.y, z);
		isometric(&x1, &y1, z1);
	}
	fdf->color = (z || z1) ? 0xfc0345 : 0xBBFAFF;
	fdf->color = (z != z1) ? 0xfc031c : fdf->color;
	fdf->color = WHITE;
	cords.x += fdf->shift_x;
	cords.y += fdf->shift_y;
	x1 += fdf->shift_x;
	y1 += fdf->shift_y;
	put_pixel(cords, x1, y1, fdf);
}
