/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:55:13 by nbuhler           #+#    #+#             */
/*   Updated: 2017/05/04 14:55:14 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_fractal_julia(t_env *e)
{
	e->fractal->x1 = -1;
	e->fractal->x2 = 1;
	e->fractal->y1 = -1.2;
	e->fractal->y2 = 1.2;
	e->fractal->zr = 0;
	e->fractal->zi = 0;
	e->fractal->cr = 0.285;
	e->fractal->ci = 0.01;
	e->fractal->tmp = 0;
}

int			ft_draw_cal_j(t_env *e, long double zr, long double zi)
{
	int			i;
	long double tmp;

	i = 0;
	while ((zr * zr + zi * zi) < 4 && i < e->ite_max)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + (e->fractal->cr);
		zi = 2 * (zi * tmp) + e->fractal->ci;
		i++;
	}
	if (i == e->ite_max)
		return (0x000000);
	else
		return (i * e->color);
}

void		ft_draw_j(t_env *e)
{
	long		x;
	long		y;
	long double zr;
	long double zi;

	x = e->x;
	ft_check_mouse(e);
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			zr = (x / e->z) - 1;
			zi = (y / e->z) - 1.2;
			put_pxl(e, x - e->x, y - e->y, ft_draw_cal_j(e, zr, zi));
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_menu(e);
}
