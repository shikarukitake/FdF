/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:14:57 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/05 19:36:45 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_fdf(t_fdf *fdf)
{
	int	i;

	if (fdf->mlx_ptr && fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->temp)
		free(fdf->temp);
	if (fdf->tempd)
		to_free_dstr(fdf->tempd);
	i = 0;
	if (fdf->z_matrix)
	{
		while (i != fdf->height)
		{
			if (fdf->z_matrix[i])
				free(fdf->z_matrix[i]);
			i++;
		}
		free(fdf->z_matrix);
	}
	free(fdf);
}

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		ft_error_t("fdf init malloc");
	fdf->z_matrix = NULL;
	fdf->tempd = NULL;
	fdf->temp = NULL;
	fdf->zoom = 20;
	fdf->shift_x = 300;
	fdf->shift_y = 300;
	fdf->isometric = 1;
	fdf->win_ptr = NULL;
	fdf->mlx_ptr = NULL;
	return (fdf);
}

t_fdf	*error_f(char const *text, int init)
{
	static	t_fdf *fdf;

	if (init)
	{
		fdf = init_fdf();
		return (fdf);
	}
	free_fdf(fdf);
	ft_error_t(text);
	return (NULL);
}

void	end(t_fdf *fdf)
{
	free_fdf(fdf);
	exit(0);
}

float	mod(float n)
{
	return (n < 0 ? n * -1 : n);
}
