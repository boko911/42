/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 12:53:25 by agrosset          #+#    #+#             */
/*   Updated: 2018/01/29 13:44:49 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				parse_resolution(char **line, int *i, t_res *res)
{
	if (line[*i + 1] == NULL || line[*i + 2] == NULL ||
		line[*i + 3] == NULL)
		return (0);
	if (!ft_isnumber(line[*i + 1]) || !ft_isnumber(line[*i + 2]))
		return (0);
	res->width = ft_atoi(ft_israndom(&(line[*i + 1]), 500, 1920, 0));
	res->height = ft_atoi(ft_israndom(&(line[*i + 2]), 500, 1080, 0));
	*i += 2;
	if (res->width < 50 || res->height < 10)
		return (0);
	return (1);
}

int				parse_vector3(char **line, int *i, t_mtx *v)
{
	if (line[*i + 1] == NULL || line[*i + 2] == NULL ||
		line[*i + 3] == NULL)
		return (0);
	if ((!ft_isnumber(line[*i + 1]) && !(line[*i + 1][0] == '~'))
	|| (!ft_isnumber(line[*i + 2]) && !(line[*i + 2][0] == '~'))
	|| (!ft_isnumber(line[*i + 3]) && !(line[*i + 3][0] == '~')))
		return (0);
	*v = mtx_init(4, 1);
	v->mtx[0] = ft_atof(ft_israndom(&(line[*i + 1]), 0, 40, 1));
	v->mtx[1] = ft_atof(ft_israndom(&(line[*i + 2]), 0, 40, 1));
	v->mtx[2] = ft_atof(ft_israndom(&(line[*i + 3]), 0, 40, 1));
	v->mtx[3] = 1;
	*i += 3;
	return (1);
}

int				parse_color(char **line, int *i, t_color *rgb)
{
	if (line[*i + 1] == NULL || line[*i + 2] == NULL ||
		line[*i + 3] == NULL)
		return (0);
	if ((!ft_isnumber(line[*i + 1]) && !(line[*i + 1][0] == '~'))
	|| (!ft_isnumber(line[*i + 2]) && !(line[*i + 2][0] == '~'))
	|| (!ft_isnumber(line[*i + 3]) && !(line[*i + 3][0] == '~')))
		return (0);
	rgb->r = ft_fclamp(ft_atof(ft_israndom(&(line[*i + 1]), 0, 1, 4)), 0, 1);
	rgb->g = ft_fclamp(ft_atof(ft_israndom(&(line[*i + 2]), 0, 1, 4)), 0, 1);
	rgb->b = ft_fclamp(ft_atof(ft_israndom(&(line[*i + 3]), 0, 1, 4)), 0, 1);
	*i += 3;
	return (1);
}

int				parse_double(char **line, int *i, double *a, int id)
{
	if (line[*i + 1] == NULL)
		return (0);
	if ((!ft_isnumber(line[*i + 1]) && !(line[*i + 1][0] == '~')))
		return (0);
	*a = ft_atof(ft_israndom(&(line[*i + 1]), 0, 10, id));
	*i += 1;
	return (1);
}

int				parse_int(char **line, int *i, int *a)
{
	if (line[*i + 1] == NULL)
		return (0);
	if ((!ft_isnumber(line[*i + 1]) && !(line[*i + 1][0] == '~')))
		return (0);
	*a = ft_atoi(ft_israndom(&(line[*i + 1]), 0, 255, 0));
	*i += 1;
	return (1);
}
