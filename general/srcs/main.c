#include "fdf.h"

int main(int ac, char **av)
{
	t_fdf *fdf;

	if (ac == 2)
	{
		fdf = error_f(NULL, 1);
		read_file(fdf, av[1]);
	}
	else
	{
		ft_printf("HELLO");
		return (0);
	}

	int i = 0;
	int j = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("%3d ", fdf->z_matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return (0);
}