/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:55:03 by nbuhler           #+#    #+#             */
/*   Updated: 2017/05/04 14:55:06 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fractal_mandelbrot(t_env *e)
{
	e->fractal->x1 = -2.1;
	e->fractal->x2 = 0.6;
	e->fractal->y1 = -1.2;
	e->fractal->y2 = 1.2;
	e->fractal->zr = 0;
	e->fractal->zi = 0;
	e->fractal->cr = 0;
	e->fractal->ci = 0;
	e->fractal->tmp = 0;
}

void	put_pxl(t_env *e, int x, int y, unsigned int c)
{
	int	i;

	i = (x * 4) + (y * e->s_line);
	e->pxl[i] = c;
	e->pxl[++i] = c >> 8;
	e->pxl[++i] = c >> 16;
}

int		ft_draw_cal_m(t_env *e, long double cr, long double ci)
{
	int			i;
	long double	zr;
	long double	zi;
	long double	tmp;

	i = 0;
	zr = 0;
	zi = 0;
	while ((zr * zr + zi * zi) < 4 && i < e->ite_max)
	{
		tmp = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = 2 * (zi) * tmp + ci;
		i++;
	}
	if (i == e->ite_max)
		return (0x000000);
	else
		return (i * e->color);
}

int		ft_draw_cal_bship(t_env *e, long double cr, long double ci)
{
	int			i;
	long double	zr;
	long double	zi;
	long double	tmp;

	i = 0;
	zr = 0;
	zi = 0;
	while ((zr * zr + zi * zi) < 4 && i < e->ite_max)
	{
		tmp = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = 2 * fabsl(zi * tmp) + ci;
		i++;
	}
	if (i == e->ite_max)
		return (0x000000);
	else
		return (i * e->color);
}

void	ft_draw_m(t_env *e)
{
	long		x;
	long		y;
	long double	cr;
	long double	ci;

	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			cr = (x / e->z) - 2.1;
			ci = (y / e->z) - 1.2;
			if (e->type == 1)
				put_pxl(e, x - e->x, y - e->y, ft_draw_cal_m(e, cr, ci));
			if (e->type == 3)
				put_pxl(e, x - e->x, y - e->y, ft_draw_cal_bship(e, cr, ci));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_menu(e);
}
