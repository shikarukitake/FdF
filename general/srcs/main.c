/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:15:11 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/05 21:21:49 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *fdf)
{
	if (key == 53 || key == 126 || key == 125 ||
		key == 123 || key == 124 || key == 8 ||
		key == 91 || key == 87 || key == 84)
	{
		if (key == 53)
			end(fdf);
		if (key == 126)
			fdf->shift_y -= 30;
		if (key == 125)
			fdf->shift_y += 30;
		if (key == 123)
			fdf->shift_x -= 30;
		if (key == 124)
			fdf->shift_x += 30;
		if (key == 8 || key == 91)
			fdf->isometric = fdf->isometric == 0 ? 1 : 0;
		if (key == 87)
			fdf->zoom += 1;
		if (key == 84)
			if (fdf->zoom > 1)
				fdf->zoom -= 1;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	return (0);
}

void	map_zoom(t_fdf *fdf)
{
	if (fdf->height * fdf->width <= 100)
		fdf->zoom = 30;
	else if (fdf->height * fdf->width <= 250)
		fdf->zoom = 20;
	else if (fdf->height * fdf->width <= 500)
		fdf->zoom = 15;
	else if (fdf->height * fdf->width <= 1000)
		fdf->zoom = 10;
	else if (fdf->height * fdf->width <= 25000)
		fdf->zoom = 5;
	else if (fdf->height * fdf->width <= 100000)
		fdf->zoom = 4;
	else if (fdf->height * fdf->width <= 200000)
		fdf->zoom = 3;
	else if (fdf->height * fdf->width <= 300000)
		fdf->zoom = 2;
}

void	init_mlx(t_fdf *fdf)
{
	if (!(fdf->mlx_ptr = mlx_init()))
		error_f("MLX_init", 0);
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF")))
		error_f("MLX_init", 0);
	if (!(fdf->img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT)))
		error_f("MLX_init", 0);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
									&(fdf->size_line), &(fdf->endian));
}

int		main(int ac, char **av)
{
	t_fdf *fdf;

	if (ac == 2)
	{
		fdf = error_f(NULL, 1);
		read_file(fdf, av[1]);
		init_mlx(fdf);
		map_zoom(fdf);
		draw(fdf);
		mlx_key_hook(fdf->win_ptr, deal_key, fdf);
		mlx_loop(fdf->mlx_ptr);
		if (fdf)
			free_fdf(fdf);
	}
	else
		ft_printf("Usage : ./fdf_original <filename>\n");
	return (0);
}
