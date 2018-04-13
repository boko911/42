/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:08:38 by agrosset          #+#    #+#             */
/*   Updated: 2018/02/14 14:14:29 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				parse_mtx_trans(char **line, int *i, t_mtx *v)
{
	if (line[*i + 1] == NULL || line[*i + 2] == NULL ||
		line[*i + 3] == NULL)
		return (0);
	if ((!ft_isnumber(line[*i + 1]) && !(line[*i + 1][0] == '~'))
	|| (!ft_isnumber(line[*i + 2]) && !(line[*i + 2][0] == '~'))
	|| (!ft_isnumber(line[*i + 3]) && !(line[*i + 3][0] == '~')))
		return (0);
	*v = mtx_init(4, 4);
	v->mtx[0] = 1;
	v->mtx[3] = ft_atof(ft_israndom(&(line[*i + 1]), 0, 40, 1));
	v->mtx[5] = 1;
	v->mtx[7] = ft_atof(ft_israndom(&(line[*i + 2]), 0, 40, 1));
	v->mtx[10] = 1;
	v->mtx[11] = ft_atof(ft_israndom(&(line[*i + 3]), 0, 40, 1));
	v->mtx[15] = 1;
	*i += 3;
	return (1);
}

int				parse_mtx_rot(char **line, int *i, t_mtx *v)
{
	double	rotx;
	double	roty;
	double	rotz;

	if (line[*i + 1] == NULL || line[*i + 2] == NULL ||
		line[*i + 3] == NULL)
		return (0);
	if ((!ft_isnumber(line[*i + 1]) && !(line[*i + 1][0] == '~'))
	|| (!ft_isnumber(line[*i + 2]) && !(line[*i + 2][0] == '~'))
	|| (!ft_isnumber(line[*i + 3]) && !(line[*i + 3][0] == '~')))
		return (0);
	rotx = ft_atof(ft_israndom(&(line[*i + 1]), 0, 360, 1)) * M_PI / 180.;
	roty = ft_atof(ft_israndom(&(line[*i + 2]), 0, 360, 1)) * M_PI / 180.;
	rotz = ft_atof(ft_israndom(&(line[*i + 3]), 0, 360, 1)) * M_PI / 180.;
	*v = mtx_createrotmtx(rotx, roty, rotz);
	*i += 3;
	return (1);
}

int				parse_n(char **line, int *i, double *a, int id)
{
	char *str;

	if (line[*i + 1] == NULL)
		return (0);
	if ((!ft_isnumber(line[*i + 1]) && !(line[*i + 1][0] == '~')))
		return (0);
	str = ft_israndom(&(line[*i + 1]), 0, 3, id);
	*a = ft_atof(str);
	ft_fclamp(*a, 0, 2);
	*i += 1;
	return (1);
}

int				parse_shine(char **line, int *i, double *a, int id)
{
	if (line[*i + 1] == NULL)
		return (0);
	if ((!ft_isnumber(line[*i + 1]) && !(line[*i + 1][0] == '~')))
		return (0);
	*a = ft_atof(ft_israndom(&(line[*i + 1]), 0, 10, id));
	*a = (int)*a;
	if ((int)*a == -1)
		*a = 101;
	else
	{
		if ((int)*a % 2)
			*a = (int)*a + 1;
		if (*a < 10 && *a != 0)
			*a = 12.0;
	}
	*i += 1;
	return (1);
}
