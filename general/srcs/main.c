#include "fdf.h"

int	deal_key(int key, t_fdf *fdf)
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
		ft_printf("s_x=%d | s_y=%d\n", fdf->shift_x, fdf->shift_y);
		if (key == 8 || key == 91)
			fdf->isometric = fdf->isometric == 0 ? 1 : 0;
		if (key == 87)
			fdf->zoom += 100;
		if (key == 84)
			fdf->zoom -= 100;
		ft_printf("zoom=%d\n", fdf->zoom);
		draw(fdf);
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	ft_printf("%d ", key);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf *fdf;

	if (ac == 2)
	{
		fdf = error_f(NULL, 1);
		read_file(fdf, av[1]);
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "FDF");
		draw(fdf);
		mlx_key_hook(fdf->win_ptr, deal_key, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	return (0);
}