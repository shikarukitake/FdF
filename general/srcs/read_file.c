#include "fdf.h"

void		set_height(char *f_name, t_fdf *fdf)
{
	int	fd;

	fd = open(f_name, O_RDONLY, 0);
	if (fd < 0)
		error_f("set_width open file error", 0);
	fdf->height = 0;
	while (ft_get_next_line(fd, &fdf->temp))
	{
		if (fdf->temp == NULL)
			error_f("set_width gnl malloc", 0);
		fdf->height++;
		free(fdf->temp);
	}
	close(fd);
}

void		set_width(char *f_name, t_fdf *fdf)
{
	int	fd;

	fd = open(f_name, O_RDONLY, 0);
	if (fd < 0)
		error_f("set_width file open error", 0);
	fdf->width = 0;
	while (ft_get_next_line(fd, &fdf->temp))
	{
		if (fdf->temp == NULL)
		{
			ft_printf("hello %d\n", fd);
			error_f("set_width gnl malloc", 0);
			close(fd);
		}
		if (fdf->width != 0 && word_counter(fdf->temp, ' ') != fdf->width)
		{
			ft_printf("hello %d\n", fd);
			error_f("set_height", 0);
			close(fd);
		}
		fdf->width = fdf->width == 0 ? word_counter(fdf->temp, ' ') : fdf->width;
		free(fdf->temp);
	}
	close(fd);

}

void		fill_z(char *line, t_fdf *fdf, int i)
{
	int		j;

	if (!(fdf->tempd = ft_strsplit(line, ' ')))
		error_f("read_file fill_z ft_strsplit malloc", 0);
	j = 0;
	while(fdf->tempd[j])
	{
		fdf->z_matrix[i][j] = ft_atoi(fdf->tempd[j]);
		free(fdf->tempd[j]);
		j++;
	}
	free(fdf->tempd);
}

void		read_file(t_fdf *fdf, char *f_name)
{
	int	i;
	int	fd;

	set_width(f_name, fdf);
	set_height(f_name, fdf);
	i = 0;
	fdf->z_matrix = malloc(sizeof(int*) * (fdf->height + 1));
	if (fdf->z_matrix == NULL)
		error_f("z_matrix malloc", 0);
	while (i <= fdf->height)
		if (!(fdf->z_matrix[i++] = malloc(sizeof(int) * (fdf->width + 1))))
			error_f("z_matrix malloc", 0);
	if (!(fd = open(f_name, O_RDONLY, 0)))
		error_f("read_file open file error", 0);
	i = 0;
	while (ft_get_next_line(fd, &fdf->temp))
	{
		if (!fdf->temp)
			error_f("read_file gnl malloc", 0);
		fill_z(fdf->temp, fdf, i);
		free(fdf->temp);
		i++;
	}
	close(fd);
	fdf->z_matrix[i] = NULL;
}