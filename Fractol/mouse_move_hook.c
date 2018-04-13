/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:55:37 by nbuhler           #+#    #+#             */
/*   Updated: 2017/05/04 14:55:39 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move_hook(int x, int y, t_env *e)
{
	if (x < 0 || x >= e->width || y < 0 || y >= e->height)
	{
		e->mouse_x = 1;
		e->mouse_y = 1;
	}
	if (x > 0 && x <= e->width && y > 0 && y <= e->height && e->type == 2
		&& e->mouse == 1 && e->z == 100)
	{
		e->mouse_x = x;
		e->mouse_y = y;
		ft_refresh(e);
	}
	else
	{
		e->mouse_x = x;
		e->mouse_y = x;
	}
	return (0);
}

void	ft_check_mouse(t_env *e)
{
	if (e->mouse == 0)
	{
		e->fractal->cr = 0.285;
		e->fractal->ci = 0.01;
	}
	if (e->mouse == 1 && e->z == 100)
	{
		e->fractal->cr = (0.285 * e->mouse_x * 0.25) * 0.01;
		e->fractal->ci = (0.01 * e->mouse_y);
	}
}
