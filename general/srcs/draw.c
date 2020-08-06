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

void		print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, 15, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: 5/2");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection: C/8");
}

static void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = (i % WIDTH < MENU_WIDTH) ? MENU_BACKGROUND : BACKGROUND;
		i++;
	}
}

void		draw(t_fdf *fdf)
{
	t_cord	cords;

	draw_background(fdf);
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
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img, 0, 0);
	print_menu(fdf);
}
