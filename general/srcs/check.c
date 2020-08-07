/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:30:06 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/07 17:30:07 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_sign(int с)
{
	return (с == '-' || с == '+');
}

int		is_alphabet(int с)
{
	if (с >= 'a' && 'f' >= с)
		return (1);
	if (с >= 'A' && 'F' >= с)
		return (2);
	return (0);
}

int		is_x(int c)
{
	return (c == 'x' || c == 'X');
}

t_ull			check_hexad(t_ull i, t_ull j, char **split)
{
	t_ull letters_count;

	letters_count = 0;
	while (split[i][j])
	{
		if (!is_alphabet(split[i][j]) && !ft_isdigit(split[i][j]))
			error_f("Invalid map", 0);
		letters_count += 1;
		j += 1;
	}
	if (letters_count > 6)
		error_f("Invalid map", 0);
	return (1);
}

void		check_values(char **split)
{
	t_ull i;
	t_ull j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!j && is_sign(split[i][j]))
				j += 1;
			else if (ft_isdigit(split[i][j]))
				j += 1;
			else if (j && ((split[i][j] == ',') && split[i][j + 1]) &&
					(split[i][j + 1] == '0' && split[i][j + 2]) &&
					(is_x(split[i][j + 2])) &&
					(check_hexad(i, j + 3, split)))
				break ;
			else
				error_f("Invalid map", 0);
		}
		i += 1;
	}
}
