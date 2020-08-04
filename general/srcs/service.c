#include "fdf.h"

t_fdf	*error_f(char const *text, int init)
{
	static t_fdf *fdf;

	if (init)
	{
		if (!(fdf = malloc(sizeof(t_fdf))))
			ft_error_t("fdf init malloc");
		return (fdf);
	}
	ft_error_t(text);
	return (NULL);
}