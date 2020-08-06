/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:17:19 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/05 19:35:10 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define MENU_WIDTH			250
# define WIDTH				1000
# define HEIGHT				1000
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E
# define RED				0xe80c0c
# define WHITE				0xffffff
# define TEXT_COLOR			0xEAEAEA

typedef struct	s_fdf
{
	int		height;
	int		width;
	int		**z_matrix;
	char	*temp;
	char	**tempd;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		zoom;
	int		color;
	int		shift_y;
	int		shift_x;
	int		isometric;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data_addr;
}				t_fdf;

typedef struct	s_cord
{
	float	x;
	float	y;
}				t_cord;

/*
** function to safe exit when get some error
*/

t_fdf			*error_f(char const *text, int init);

/*
** reading map and check on errors
*/

void			read_file(t_fdf *fdf, char *f_name);

/*
** Function to draw a line
*/

void			bresenham(t_cord cords, float x1, float y1, t_fdf *fdf);

/*
** Function to draw a map
*/

void			draw(t_fdf *fdf);

/*
** Service functions
*/

void			end(t_fdf *fdf);
float			mod(float n);
#endif
