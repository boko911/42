/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_filters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:00:03 by acoudray          #+#    #+#             */
/*   Updated: 2018/02/16 13:53:12 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color	*apply_grayscale(t_color *color)
{
	float gray;

	gray = (color->r * 0.2126 + color->g * 0.7152 + color->b * 0.0722);
	color->r = gray;
	color->g = gray;
	color->b = gray;
	return (color);
}

static t_color	*apply_negative(t_color *color)
{
	color->r = 1.0 - color->r;
	color->g = 1.0 - color->g;
	color->b = 1.0 - color->b;
	return (color);
}

static t_color	*apply_sepia(t_color *color)
{
	float tr;
	float tg;
	float tb;

	tr = (0.55 * color->r + 0.44 * color->g + 0.15 * color->b);
	tg = (0.3 * color->r + 0.4 * color->g + 0.12 * color->b);
	tb = (0.3 * color->r + 0.3 * color->g + 0.1 * color->b);
	color->r = tr;
	color->g = tg;
	color->b = tb;
	if (tr > 1.0)
		color->r = 1.0;
	if (tg > 1.0)
		color->g = 1.0;
	if (tb > 1.0)
		color->b = 1.0;
	return (color);
}

int				parse_filter(char **line, int *i, int *filter)
{
	if (line[*i + 1] == 0)
		return (0);
	if (!(ft_strcmp(line[*i + 1], "sepia")))
		*filter = 1;
	else if (!(ft_strcmp(line[*i + 1], "negative")))
		*filter = 2;
	else if (!(ft_strcmp(line[*i + 1], "grayscale")))
		*filter = 3;
	else
		return (0);
	return (1);
}

int				check_filter(t_color *color, t_env *env)
{
	if (env->scene->filter == 1)
		color = apply_sepia(color);
	else if (env->scene->filter == 2)
		color = apply_negative(color);
	else if (env->scene->filter == 3)
		color = apply_grayscale(color);
	return (0);
}
