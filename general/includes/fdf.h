//
// Created by Sole Dagger on 8/4/20.
//

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>

# define RED 0xe80c0c
# define WHITE 0xffffff

typedef struct	s_fdf
{
	int		height;
	int		width;
	int		**z_matrix;
	char	*temp;
	char	**tempd;
	void	*mlx_ptr;
	void	*win_ptr;
	int		zoom;
	int		color;
	int		shift_y;
	int		shift_x;
	int		isometric;
}				t_fdf;

/*
** function to safe exit when get some error
*/

t_fdf		*error_f(char const *text, int init);

/*
** reading map and check on errors
*/

void		read_file(t_fdf *fdf, char *f_name);

/*
** Function to draw a line
*/

void		bresenham(float x, float y, float x1, float y1, t_fdf *fdf);

/*
** Function to draw a map
*/

void		draw(t_fdf *fdf);

/*
** Service functions
*/

void		end(t_fdf *fdf);
#endif