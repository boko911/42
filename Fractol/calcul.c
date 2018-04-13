/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:56:59 by nbuhler           #+#    #+#             */
/*   Updated: 2017/05/04 14:57:01 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_center_plan(t_env *e)
{
	if (e->type == 1 || e->type == 3)
	{
		e->x = -(e->width -
				(((e->fractal->x2 - e->fractal->x1) / 2) * e->z)) / 8;
		e->y = -(e->height - ((e->fractal->y2 - e->fractal->y1) * e->z)) / 2;
	}
	else
	{
		e->x = -(e->width - ((e->fractal->x2 - e->fractal->x1) * e->z)) / 2;
		e->y = -(e->height - ((e->fractal->y2 - e->fractal->y1) * e->z)) / 2;
	}
}

void	ft_check_argv(const char *str)
{
	t_env e;

	if (ft_strcmp(str, "1") == 0)
	{
		e = ft_init_env(&e);
		e.type = 1;
		ft_setup(&e);
	}
	if (ft_strcmp(str, "2") == 0)
	{
		e = ft_init_env(&e);
		e.type = 2;
		ft_setup(&e);
	}
	if (ft_strcmp(str, "3") == 0)
	{
		e = ft_init_env(&e);
		e.type = 3;
		ft_setup(&e);
	}
	else
	{
		ft_error(1);
		exit(0);
	}
}
