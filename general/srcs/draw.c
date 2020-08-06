/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:15:18 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/05 21:11:27 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

t_cord	get_step(t_cord cords, float x1, float y1)
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

void	put_pixel(t_cord cords, float x1, float y1, const t_fdf *fdf)
{
	t_cord	step;

	step = get_step(cords, x1, y1);
	while ((int)(cords.x - x1) || (int)(cords.y - y1))
	{
		if (cords.x > 1300 || cords.y > 1300 ||
					cords.y < -300 || cords.x < -300)
			break ;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, cords.x, cords.y, fdf->color);
		cords.x += step.x;
		cords.y += step.y;
	}
}

void	bresenham(t_cord cords, float x1, float y1, t_fdf *fdf)
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
	// fdf->color = (z || z1) ? RED : WHITE;
	// fdf->color = (z || z1) ? 0xfc0345 : 0xBBFAFF;
	// fdf->color = (z != z1) ? 0xfc031c : fdf->color;
	fdf->color = WHITE;
	cords.x += fdf->shift_x;
	cords.y += fdf->shift_y;
	x1 += fdf->shift_x;
	y1 += fdf->shift_y;
	put_pixel(cords, x1, y1, fdf);
}

void	draw(t_fdf *fdf)
{
	t_cord	cords;

	cords.y = 0;
	while (cords.y < fdf->height)
	{
		cords.x = 0;
		while (cords.x < fdf->width)
		{
			if (cords.x < fdf->width - 1)
				bresenham(cords, cords.x + 1, cords.y, fdf);
			if (cords.y < fdf->height - 1)
				bresenham(cords, cords.x, cords.y + 1, fdf);
			cords.x++;
		}
		cords.y++;
	}
}
