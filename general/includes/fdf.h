//
// Created by Sole Dagger on 8/4/20.
//

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "libft.h"
# include <fcntl.h>

typedef struct	s_fdf
{
	int		height;
	int		width;
	int		**z_matrix;
	char	*temp;
	char	**tempd;
}				t_fdf;

/*
** function to safe exit when get some error
*/

t_fdf		*error_f(char const *text, int init);

/*
** reading map and check on errors
*/

void		read_file(t_fdf *fdf, char *f_name);

#endif